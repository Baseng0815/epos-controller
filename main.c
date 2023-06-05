#include "deps/Definitions.h"

#include <stdio.h>
#include <stdlib.h>

void *device_open(void);
void protocol_settings_dump(void *device);

int main(int argc, char *argv[])
{
        void *device = device_open();
}

void *device_open(void)
{
        const char *device_name         = "EPOS4";
        const char *protocol_stack_name = "CANopen";
        const char *interface_name      = "TODO INTERFACE";
        const char *port_name           = "CAN0";

        unsigned int err;
        void *device = VCS_OpenDevice(device_name, protocol_stack_name,
                                   interface_name, port_name, &err);
        if (device == NULL) {
                fprintf(stderr, "Failed to open device %s using protocol %s on"
                        " interface %s and port %s: error code %x\n",
                        device_name, protocol_stack_name, interface_name,
                        port_name, err);
                exit(err);
        }

        return device;
}

void protocol_settings_dump(void *device)
{
        unsigned int err;

}
