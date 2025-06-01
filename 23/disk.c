#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/hdreg.h>
#include <linux/fs.h>

void print_disk_info(const char* device)
{
    int fd;
    struct hd_geometry geometry;
    unsigned long long size_bytes;
    unsigned long size_sectors;
    int block_size;
    
    printf("\n=== %s Disk Information ===\n", device);
    
    // Open device
    fd = open(device, O_RDONLY);
    if (fd < 0) {
        perror("Failed to open device");
        return;
    }
    
    // Disk geometry information
    if (ioctl(fd, HDIO_GETGEO, &geometry) == 0) {
        printf("Cylinders: %d\n", geometry.cylinders);
        printf("Heads: %d\n", geometry.heads);
        printf("Sectors/track: %d\n", geometry.sectors);
        printf("Start sector: %lu\n", geometry.start);
    }
    
    // Total sector count
    if (ioctl(fd, BLKGETSIZE, &size_sectors) == 0) {
        printf("Total sectors: %lu\n", size_sectors);
    }
    
    // Total bytes
    if (ioctl(fd, BLKGETSIZE64, &size_bytes) == 0) {
        printf("Total size: %llu bytes (%.2f GB)\n", 
               size_bytes, (double)size_bytes / (1024*1024*1024));
    }
    
    // Block size
    if (ioctl(fd, BLKBSZGET, &block_size) == 0) {
        printf("Block size: %d bytes\n", block_size);
    }
    
    // Read-only status
    int readonly;
    if (ioctl(fd, BLKROGET, &readonly) == 0) {
        printf("Read-only: %s\n", readonly ? "Yes" : "No");
    }
    
    close(fd);
}

int main(int argc, char *argv[])
{
    if (argc < 2) {
        printf("Usage: %s <device1> [device2] ...\n", argv[0]);
        printf("Example: %s /dev/sda /dev/sdb\n", argv[0]);
        printf("Note: Root privileges may be required.\n");
        return 1;
    }
    
    for (int i = 1; i < argc; i++) {
        print_disk_info(argv[i]);
    }
    
    return 0;
}
