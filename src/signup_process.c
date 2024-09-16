#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libusb.h>
#include "config.h"
#include "database_handler.h"
#include "image_capturer.h"
#include "fingerprint_processor.h"

void signup_process()
{
    libusb_device_handle *device = NULL;
    fp_dev_t *dev = NULL;
    fp_image_t *img = NULL;
    fp_print_data_t *print = NULL;
    MYSQL *db_conn = NULL;

    init_fingerprint_reader(&device);

    // Get national ID from user input
    char national_id[NATIONAL_ID_LENGTH + 1];
    printf("Enter your national ID: ");
    scanf("%20s", national_id);

    db_conn = connect_to_mysql();

    // Capture fingerprint
    process_fingerprint(img, &print);

    // Save fingerprint data and national ID to database
    save_fingerprint_data(db_conn, national_id, print);

    printf("User registered successfully\n");

    fp_print_free(print);
    fp_img_free(img);
    fp_dev_close(dev);
    libusb_close(device);
    mysql_close(db_conn);
}
