#ifndef FINGERPRINT_PROCESSOR_H
#define FINGERPRINT_PROCESSOR_H

typedef struct fp_image_t* fp_image_t;
typedef struct fp_print_data_t* fp_print_data_t;

void process_fingerprint(fp_image_t* img, fp_print_data_t** print);

#endif // FINGERPRINT_PROCESSOR_H
