#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main()
{
    int fd;
    char *line;

    fd = open("file.txt", O_RDONLY);
    if (fd == -1)
    {
        return 1;
    }
    ///line = get_next_line(fd);
    //printf("buf = %s", line);
    //free(line);
    //line = get_next_line(fd);
    // printf("buf = %s", line);
    // free(line);
    line = get_next_line(0);
    printf("buf = %s", line);
    free(line);
    close(fd);
    return 0;
}

