#include <stdio.h>
#include <sys/statvfs.h>

int getAvailableDiskSpace(const char* drive) {
    struct statvfs buf;

    if (statvfs(drive, &buf) != 0) {
        return -1;
    }

    return (buf.f_bsize * buf.f_bavail) / (1024 * 1024);
}

int getTotalDiskSpace(const char* drive) {
    struct statvfs buf;

    if (statvfs(drive, &buf) != 0) {
        return -1;
    }

    return (buf.f_bsize * buf.f_blocks) / (1024 * 1024);
}

int getBusyDiskSpace(const char* drive) {
    struct statvfs buf;

    if (statvfs(drive, &buf) != 0) {
        return -1;
    }

    return ((buf.f_bsize * buf.f_blocks) - (buf.f_bsize * buf.f_bavail)) / (1024 * 1024);
}
