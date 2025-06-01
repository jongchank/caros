#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/rtc.h>
#include <errno.h>
#include <time.h>

const char* rtc_device = "/dev/rtc";

int main(void)
{
    int fd;
    struct rtc_time rtc_tm;
    
    fd = open(rtc_device, O_RDWR);
    if (fd < 0) {
        perror("Failed to open RTC");
        return 1;
    }
    
    if (ioctl(fd, RTC_RD_TIME, &rtc_tm) == 0) {
        printf("Time: %04d-%02d-%02d %02d:%02d:%02d\n",
               rtc_tm.tm_year + 1900, rtc_tm.tm_mon + 1, rtc_tm.tm_mday,
               rtc_tm.tm_hour, rtc_tm.tm_min, rtc_tm.tm_sec);
        printf("Day:  %d (0=Sunday)\n", rtc_tm.tm_wday);
    }
    
    close(fd);
    return 0;
}

