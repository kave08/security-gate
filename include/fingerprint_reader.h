#ifndef FINGERPRINT_READER_H
#define FINGERPRINT_READER_H

typedef struct libusb_device_handle* libusb_device_handle;

void init_fingerprint_reader(libusb_device_handle** device);
void deinit_fingerprint_reader(libusb_device_handle* device);

#endif // FINGERPRINT_READER_H
