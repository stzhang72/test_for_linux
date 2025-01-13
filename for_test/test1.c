#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "/mnt/myfs/First/one" // 文件路径

int main() {
    char buffer[64];
    int fd;
    int ret;
    size_t len;

    char message[] = "I am testing myfs file system!";
    char *read_buffer;

    len = sizeof(message); // 设置数据长度

    // 1. 打开文件
    fd = open(FILE_NAME, O_RDWR);
    if (fd < 0) {
        perror("Error opening file");
        return -1;
    }

    // 2. 向文件写数据
    ret = write(fd, message, len);
    if (ret != len) {
        perror("Error writing to file");
        close(fd);
        return -1;
    }

    printf("Written %d bytes to %s\n", ret, FILE_NAME);

    // 3. 读取文件数据
    read_buffer = malloc(2 * len);  // 分配足够的内存以存储读取的内容
    if (read_buffer == NULL) {
        perror("Error allocating memory for read buffer");
        close(fd);
        return -1;
    }
    memset(read_buffer, 0, 2 * len);  // 初始化缓冲区

    // 从文件读取数据
    ret = read(fd, read_buffer, 2 * len);  // 尝试读取两倍的数据量
    if (ret < 0) {
        perror("Error reading from file");
        free(read_buffer);
        close(fd);
        return -1;
    }

    printf("Read %d bytes\n", ret);
    printf("Read buffer = %s\n", read_buffer);

    // 4. 关闭文件
    close(fd);
    free(read_buffer); // 释放内存

    return 0;
}

