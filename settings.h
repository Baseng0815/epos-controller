#pragma once

#include <stdint.h>
#include <netinet/in.h>

struct cob_id {
        uint16_t id;
        uint8_t sid;
};

#define NET_BUF_SIZE 8
#define MAX_STR_SIZE 64

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

// network settings
const in_port_t RECV_PORT = 12345;

// COB-IDs for objects which cannot be configured directly through the library
const struct cob_id COB_ID_NUMBER_OF_POLE_PAIRS = { .id = 0x3001, .sid = 0x03 };
const struct cob_id COB_ID_MAX_MOTOR_SPEED      = { .id = 0x6080, .sid = 0x00 };
const struct cob_id COB_ID_MAX_GEAR_INPUT_SPEED = { .id = 0x3003, .sid = 0x03 };
