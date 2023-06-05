#include "deps/Definitions.h"

#include <stdio.h>
#include <stdlib.h>

void *open_device(void);
void 

int main(int argc, char *argv[])
{
        void *device = open_device();
}

void *open_device(void)
{
        const char *device_name         = "EPOS4";
        const char *protocol_stack_name = "CANopen";
        const char *interface_name      = "TODO INTERFACE";
        const char *port_name           = "CAN0";

        unsigned int err;
        void *ret = VCS_OpenDevice(device_name, protocol_stack_name,
                                   interface_name, port_name, &err);
        if (ret == NULL) {
                fprintf(stderr, "Failed to open device %s using protocol %s on"
                        " interface %s and port %s: error code %x\n",
                        device_name, protocol_stack_name, interface_name,
                        port_name, err);
                exit(err);
        }

        return ret;
}
