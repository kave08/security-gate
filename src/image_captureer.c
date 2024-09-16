#include <stdio.h>
#include <stdlib.h>
#include <opencv2/opencv.hpp>
#include "image_capturer.h"

void capture_and_save_image(const char *filename)
{
    cv::VideoCapture cap(0); // 0 is usually the default camera index

    if (!cap.isOpened())
    {
        printf("Cannot open camera\n");
        return;
    }

    cv::Mat frame;
    cap >> frame;

    cv::imwrite(filename, frame);

    printf("Image saved to %s\n", filename);
}
