#include "deps/Definitions.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_STR_SIZE 64

// port settings
const char *DEV_NAME    = "EPOS4";
const char *PROTO_NAME  = "CANopen";
const char *IF_NAME     = "CAN_mcp251x 0";
const char *PORT_NAME   = "CAN0";

// protocol stack settings
const uint32_t BAUDRATE = 250000; // 250 kbit/s
const uint32_t TIMEOUT  = 500; // 500 ms

// node settings
const uint16_t NODE_ID 	= 2;

// motor settings
const uint16_t MOTOR_TYPE = MT_EC_SINUS_COMMUTATED_MOTOR;
const uint32_t NOMINAL_CURRENT;
const uint32_t OUTPUT_CURRENT_LIMIT;
const uint8_t NUMBER_OF_POLE_PAIRS;
const uint16_t THERMAL_TIME_CONSTANT_WINDING;
const uint32_t TORQUE_CONSTANT;
const uint32_t MAX_MOTOR_SPEED;
const uint32_t MAX_GEAR_INPUT_SPEED;

void *port_open(void);
void port_close(void *port);
void protocol_stack_settings_set(void *port);
void node_reset(void *port, uint16_t node_id);
void node_configure(void *port, uint16_t node_id);

void driver_info_dump(void);

void print_error_and_quit(const char *what, uint32_t err);

int main(int argc, char *argv[])
{
        driver_info_dump();

        void *port = port_open();
        protocol_stack_settings_set(port);

	node_reset(port, NODE_ID);
	sleep(3);
	node_configure(port, NODE_ID);

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
                print_error_and_quit("failed to open port", err);
        }

        printf("port opened: handle=0x%x\n", port);
        return port;
}

void port_close(void *port)
{
        printf("closing port 0x%x...\n", port);

        uint32_t err;
        if (!VCS_CloseDevice(port, &err)) {
                print_error_and_quit("failed to close port", err);
        }
}

void protocol_stack_settings_set(void *port)
{
        printf("setting baudrate to %dkbits/s and timeout to %ums...\n",
               BAUDRATE / 1000, TIMEOUT);

        uint32_t err;
        if (!VCS_SetProtocolStackSettings(port, BAUDRATE, TIMEOUT, &err)) {
                print_error_and_quit("failed to set protocol stack settings",
                                     err);
        }
}

void node_reset(void *port, uint16_t node_id)
{
	printf("resetting node %u...\n");
	uint32_t err;
	if (!VCS_SendNMTService(port, node_id, NCS_RESET_NODE, &err)) {
		print_error_and_quit("failed to reset node", err);
	}
}

void node_configure(void *port, uint16_t node_id)
{
	printf("configuring node %u...\n", node_id);

	uint16_t data;
	uint32_t bytes_read;
	uint32_t err;
	if (!VCS_GetObject(port, node_id, 0x2200, 0x1, &data, sizeof(data),
				&bytes_read, &err)) {
		print_error_and_quit("failed to get position must", err);
	}

	printf("%u\n", data);
}

void driver_info_dump(void)
{
        printf("getting driver information...\n");

        char lib_name[MAX_STR_SIZE];
        char lib_version[MAX_STR_SIZE];

        uint32_t err;
        if (!VCS_GetDriverInfo(lib_name, MAX_STR_SIZE,
                               lib_version, MAX_STR_SIZE, &err)) {
                print_error_and_quit("failed to get driver information", err);
        }

        printf("driver name='%s' (version '%s')\n", lib_name, lib_version);
}

void print_error_and_quit(const char *what, uint32_t err)
{
        fprintf(stderr, "%s: 0x%x", what, err);

        char err_info[MAX_STR_SIZE];
        if (VCS_GetErrorInfo(err, err_info, MAX_STR_SIZE)) {
                fprintf(stderr, " (%s)", err_info);
        }

        fprintf(stderr, "\n");
        exit(1);
}

