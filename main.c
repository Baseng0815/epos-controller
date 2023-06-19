#include "deps/Definitions.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_STR_SIZE 64

struct cob_id {
        uint16_t id;
        uint8_t sid;
};

// port settings
const char *DEV_NAME    = "EPOS4";
const char *PROTO_NAME  = "CANopen";
const char *IF_NAME     = "CAN_mcp251x 0";
const char *PORT_NAME   = "CAN0";

// port settings
const uint32_t BAUDRATE = 250000; // 250 kbit/s
const uint32_t TIMEOUT  = 500; // 500 ms

// node settings
const uint16_t NODE_ID 	= 2;

// motor settings
const uint16_t MOTOR_TYPE = MT_EC_SINUS_COMMUTATED_MOTOR; // motor-specific
const uint32_t NOMINAL_CURRENT; // motor-specific
const uint32_t OUTPUT_CURRENT_LIMIT; // user-specific
const uint8_t  NUMBER_OF_POLE_PAIRS; // motor-specific
const uint16_t THERMAL_TIME_CONSTANT; // motor-specific
const uint32_t TORQUE_CONSTANT; // motor-specific
const uint32_t MAX_MOTOR_SPEED; // user-specific
const uint32_t MAX_GEAR_INPUT_SPEED; // user-specific

// position sensor settings
// application settings
// ...

// COB-IDs for objects which cannot be configured directly through the library
const struct cob_id COB_ID_NUMBER_OF_POLE_PAIRS = { .id = 0x3001, .sid = 0x03 };
const struct cob_id COB_ID_MAX_MOTOR_SPEED      = { .id = 0x6080, .sid = 0x00 };
const struct cob_id COB_ID_MAX_GEAR_INPUT_SPEED = { .id = 0x3003, .sid = 0x03 };

// Open a communication port to TX/RX to/from the CAN bus.
void *port_open(void);

// Close the communication port handle.
void port_close(void *port);

// Set port settings like baudrate and timeout.
void port_configure(void *port);

// Reset node, i.e. change NMT state to pre-operational
// (see https://www.can-cia.org/can-knowledge/canopen/network-management/ for
// details).
void node_reset(void *port, uint16_t node_id);

// Configure node parameters by writing parameters to object dictionary.
// Parameters configured are mode-independent parameters like motor type and
// number of pole pairs and sensor configuration.
void node_configure(void *port, uint16_t node_id);

// Test a node by entering profile velocity mode (PVM) and setting the target
// velocity to 1rpm.
void node_test_1rpm(void *port, uint16_t node_id);

// utility functions
void driver_info_dump(void);
void die(const char *what, uint32_t err);

int main(int argc, char *argv[])
{
        driver_info_dump();

        void *port = port_open();
        port_configure(port);

        node_reset(port, NODE_ID);
        sleep(3);
        // not needed since all parameters are stored in non-volatile memory
        // node_configure(port, NODE_ID);

        node_test_1rpm(port, NODE_ID);

        port_close(port);
        return 0;
}

void *port_open(void)
{

        printf("opening port '%s' using protocol '%s' on interface '%s' and"
               " port '%s'...\n", DEV_NAME, PROTO_NAME, IF_NAME, PORT_NAME);

        uint32_t err;
        void *port = VCS_OpenDevice(DEV_NAME, PROTO_NAME, IF_NAME, PORT_NAME,
                                    &err);
        if (!port) {
                die("failed to open port", err);
        }

        printf("|-> port opened: handle=0x%p\n", port);
        return port;
}

void port_close(void *port)
{
        printf("closing port 0x%p...\n", port);

        uint32_t err;
        if (!VCS_CloseDevice(port, &err)) {
                die("failed to close port", err);
        }
}

void port_configure(void *port)
{
        printf("setting baudrate to %dkbits/s and timeout to %ums...\n",
               BAUDRATE / 1000, TIMEOUT);

        uint32_t err;
        if (!VCS_SetProtocolStackSettings(port, BAUDRATE, TIMEOUT, &err)) {
                die("failed to set port settings",
                                     err);
        }
}

void node_reset(void *port, uint16_t node_id)
{
        printf("resetting node %u...\n", node_id);
        uint32_t err;
        if (!VCS_SendNMTService(port, node_id, NCS_RESET_NODE, &err)) {
                die("failed to reset node", err);
        }
}

void node_configure(void *port, uint16_t node_id)
{
        printf("configuring node %u...\n", node_id);

        printf("|-> configuring motor parameters...\n");

        uint32_t err;
        uint32_t bytes_written;
        if (!VCS_SetMotorType(port, node_id, MOTOR_TYPE, &err) ||
            !VCS_SetDcMotorParameterEx(port, node_id, NOMINAL_CURRENT,
                                       OUTPUT_CURRENT_LIMIT,
                                       THERMAL_TIME_CONSTANT,
                                       &err) ||
            !VCS_SetObject(port, node_id, COB_ID_MAX_MOTOR_SPEED.id,
                           COB_ID_MAX_MOTOR_SPEED.sid,
                           &MAX_MOTOR_SPEED, sizeof(MAX_MOTOR_SPEED),
                           &bytes_written, &err) ||
            !VCS_SetObject(port, node_id, COB_ID_MAX_GEAR_INPUT_SPEED.id,
                           COB_ID_MAX_GEAR_INPUT_SPEED.sid,
                           &MAX_GEAR_INPUT_SPEED, sizeof(MAX_GEAR_INPUT_SPEED),
                           &bytes_written, &err)) {
                die("failed to configure motor", err);
        }

        printf("|-> configured motor with MOTOR_TYPE=%d, NOMINAL_CURRENT=%d, "
               "OUTPUT_CURRENT_LIMIT=%d, THERMAL_TIME_CONSTANT_WINDING=%d, "
               "NUMBER_OF_POLE_PAIRS=%d, MAX_MOTOR_SPEED=%d, "
               "MAX_GEAR_INPUT_SPEED=%d\n", MOTOR_TYPE, NOMINAL_CURRENT,
               OUTPUT_CURRENT_LIMIT, THERMAL_TIME_CONSTANT,
               NUMBER_OF_POLE_PAIRS, MAX_MOTOR_SPEED, MAX_GEAR_INPUT_SPEED);

        if (MOTOR_TYPE == MT_EC_BLOCK_COMMUTATED_MOTOR ||
            MOTOR_TYPE == MT_EC_SINUS_COMMUTATED_MOTOR) {
                // brushless DC (EC) motor for which the number of pole pairs
                // needs to be configured as well
                printf("|-> using brushless DC motor - setting "
                       "NUMBER_OF_POLE_PAIRS=%d...\n", NUMBER_OF_POLE_PAIRS);
                if (!VCS_SetObject(port, node_id,
                                   COB_ID_NUMBER_OF_POLE_PAIRS.id,
                                   COB_ID_NUMBER_OF_POLE_PAIRS.sid,
                                   &NUMBER_OF_POLE_PAIRS,
                                   sizeof(NUMBER_OF_POLE_PAIRS),
                                   &bytes_written, &err)) {
                        die("failed to set NUMBER_OF_POLE_PAIRS", err);
                }

        }

        uint16_t data;
        uint32_t bytes_read;
        if (!VCS_GetObject(port, node_id, 0x2200, 0x1, &data, sizeof(data),
                           &bytes_read, &err)) {
                die("failed to get position must", err);
        }

        printf("%u\n", data);
}

void node_test_1rpm(void *port, uint16_t node_id)
{
        uint32_t err;
        if (!VCS_ActivateProfilePositionMode(port, node_id, &err)) {
                die("failed to set operational mode to PVM", err);
        }

        // 10'000rpm/s
        if (!VCS_SetVelocityProfile(port, node_id, 1, 1, &err)) {
                die("failed to set velocity profile", err);
        }

        // move with 1rpm
        if (!VCS_MoveWithVelocity(port, node_id, 1, &err)) {
                die("failed to move with target velocity", err);
        }
}

void driver_info_dump(void)
{
        printf("getting driver information...\n");

        char lib_name[MAX_STR_SIZE];
        char lib_version[MAX_STR_SIZE];

        uint32_t err;
        if (!VCS_GetDriverInfo(lib_name, MAX_STR_SIZE,
                               lib_version, MAX_STR_SIZE, &err)) {
                die("failed to get driver information", err);
        }

        printf("driver name='%s' (version '%s')\n", lib_name, lib_version);
}

void die(const char *what, uint32_t err)
{
        fprintf(stderr, "|-> %s: 0x%x", what, err);

        char err_info[MAX_STR_SIZE];
        if (VCS_GetErrorInfo(err, err_info, MAX_STR_SIZE)) {
                fprintf(stderr, " (%s)", err_info);
        }

        fprintf(stderr, "\n");
        exit(err);
}

