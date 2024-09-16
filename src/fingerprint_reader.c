#include <stdio.h>
#include <stdlib.h>
#include <libusb.h>
#include "fingerprint_reader.h"

void init_fingerprint_reader(libusb_device_handle **device)
{
    // Initialize libusb
    libusb_init(NULL);

    // Open USB device
    *device = libusb_open_device_with_vid_pid(NULL, 0x03EB, 0x0903);
    if (*device == NULL)
    {
        fprintf(stderr, "Failed to open device\n");
        exit(1);
    }
}

void deinit_fingerprint_reader(libusb_device_handle *device)
{
    libusb_close(device);
    libusb_exit(NULL);
}
