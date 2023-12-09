#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
/* 
int main()
{
    int fd = open("text.txt", O_CREAT | O_CREAT);
    char *str = "HELLO";
    write (fd, &str, sizeof(str));
    char *ptr = malloc(25);
    int rd = read(fd, ptr, 3);
    printf("%d->", rd);
    printf("%s", ptr);
} */

/* static char ptr[];
int main()
{
    ptr = calloc(5,1);
    ptr[4] = '\0';
    int i = 0;
    while (ptr[i++])
        ptr[i] = 'a';
    printf("%s", ptr);
} */

#include "get_next_line.h"

int main()
{
	char *tmp;
	int rd;
    int fd = open("tjriba.txt", O_CREAT | O_RDWR | O_APPEND);

	tmp = malloc(BUFFER_SIZE * sizeof(char));
	rd = read(fd, tmp, BUFFER_SIZE);
	printf("%s", tmp);
	return (0);
}