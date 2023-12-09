#include "get_next_line.h"

int main()
{
    char *str;
    str = malloc(100);
    int fd = open("tjriba.txt", O_CREAT | O_APPEND | O_RDWR);
    int rd = read(fd,str,4);
    int rd1 = read(fd,str,4);
    printf("%s", str);
    return (0);
}