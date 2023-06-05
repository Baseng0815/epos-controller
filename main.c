#include "deps/Definitions.h"

#include <stdio.h>
#include <stdlib.h>

#define MAX_STR_SIZE 64

void print_error_and_quit(const char *what, uint32_t err);

void *device_open(void);
void device_close(void *device);

void driver_info_dump(void);
void protocol_settings_dump(void *device);

int main(int argc, char *argv[])
{
        driver_info_dump();

        void *device = device_open();
        protocol_settings_dump(device);
        device_close(device);

        return 0;
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

void *device_open(void)
{
        const char *dev_name    = "EPOS4";
        const char *proto_name  = "CANopen";
        const char *if_name     = "TODO INTERFACE";
        const char *port_name   = "CAN0";

        printf("opening device '%s' using protocol '%s' on interface '%s' and"
               " port '%s'...\n", dev_name, proto_name, if_name, port_name);

        uint32_t err;
        void *device = VCS_OpenDevice(dev_name, proto_name, if_name, port_name,
                                      &err);
        if (!device) {
                print_error_and_quit("failed to open device", err);
        }

        printf("device opened: handle=0x%x\n", device);
        return device;
}

void device_close(void *device)
{
        printf("closing device 0x%x...\n", device);

        uint32_t err;
        if (!VCS_CloseDevice(device, &err)) {
                print_error_and_quit("failed to close device", err);
        }

        printf("device closed\n");
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

void protocol_settings_dump(void *device)
{
        printf("getting protocol information for device 0x%x...\n", device);

        uint32_t err, baudrate, timeout;
        if (!VCS_GetProtocolStackSettings(device, &baudrate, &timeout, &err)) {
                print_error_and_quit("failed to get protocol settings", err);
        }

        printf("baudrate=%d, timeout=%d\n", baudrate, timeout);
}

