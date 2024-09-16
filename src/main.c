#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/stat.h>
#include <libusb.h>
#include <mysql/mysql.h>
#include "config.h"
#include "database_handler.h"
#include "image_capturer.h"
#include "fingerprint_processor.h"

int main(int argc, char *argv[])
{
    int mode = (argc == 2 && strcmp(argv[1], "--signup") == 0) ? 1 : 0;

    if (mode)
    {
        signup_process();
    }
    else
    {
        login_process();
    }

    return 0;
}
