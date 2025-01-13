#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

#define FILE_PATH "/mnt/myfs/First/one"  // 文件路径
#define DATA_SIZE 100  // 每次写入的数据量

int main() {
    int fd;
    char *data;
    struct stat file_stat;
    ssize_t written;

    // 动态分配写入的数据
    data = (char *)malloc(DATA_SIZE);
    if (!data) {
        perror("Failed to allocate memory");
        return -1;
    }

    // 填充测试数据
    memset(data, 'A', DATA_SIZE);

    // 打开文件
    fd = open(FILE_PATH, O_WRONLY | O_APPEND);
    if (fd == -1) {
        perror("Failed to open file");
        free(data);
        return -1;
    }

    // 向文件写入数据并检查文件大小
    for (int i = 0; i < 5; i++) {
        printf("Writing data to file (Iteration %d)...\n", i + 1);

        // 向文件写入数据
        written = write(fd, data, DATA_SIZE);
        if (written == -1) {
            perror("Write failed");
            close(fd);
            free(data);
            return -1;
        }

        // 获取并显示文件的大小
        if (fstat(fd, &file_stat) == -1) {
            perror("fstat failed");
            close(fd);
            free(data);
            return -1;
        }
        printf("Current file size: %ld bytes\n", file_stat.st_size);
    }

    // 关闭文件
    close(fd);

    // 释放内存
    free(data);

    return 0;
}

