#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libusb.h>
#include "config.h"
#include "database_handler.h"
#include "image_capturer.h"
#include "fingerprint_processor.h"

void login_process()
{
    libusb_device_handle *device = NULL;
    fp_dev_t *dev = NULL;
    fp_image_t *img = NULL;
    fp_print_data_t *print = NULL;
    MYSQL *db_conn = NULL;

    init_fingerprint_reader(&device);

    db_conn = connect_to_mysql();

    // Capture fingerprint
    process_fingerprint(img, &print);

    mysql_query(db_conn, "SELECT * FROM users WHERE fingerprints = ?");
    mysql_stmt_bind_param(stmt, &print->data);
    mysql_stmt_execute(stmt);

    if (mysql_num_rows(stmt_result) > 0)
    {
        MYSQL_ROW row = mysql_fetch_row(stmt_result);

        printf("Login successful\n");
        printf("National ID: %s\n", row[1]);
        printf("Photo Path: %s\n", row[2]);

        // You can add face recognition logic here if needed
        // ...
    }
    else
    {
        printf("Invalid fingerprint\n");
    }

    fp_print_free(print);
    fp_img_free(img);
    fp_dev_close(dev);
    libusb_close(device);
    mysql_close(db_conn);
}
