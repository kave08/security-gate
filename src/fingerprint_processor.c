#include <stdio.h>
#include <stdlib.h>
#include <libusb.h>
#include "fingerprint_processor.h"

void process_fingerprint(fp_image_t *img, fp_print_data_t **print)
{
    if (fp_img_capture(img, NULL) != FP_OK)
    {
        fprintf(stderr, "Failed to capture fingerprint\n");
        return;
    }

    if (fp_print_process(*print, img) != FP_OK)
    {
        fprintf(stderr, "Failed to process fingerprint\n");
        return;
    }
}
