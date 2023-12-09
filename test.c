#include "get_next_line.h"

/* char *ft_check_line(char *ptr, int fd, char *buffer)
{
	int rd;
	
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return NULL;
	rd = read(fd, buffer, BUFFER_SIZE);
	buffer[rd] = '\0';
	while (rd > 0 && ft_strchr(buffer, '\n'))
	{
		ptr = ft_strjoin(ptr,buffer);
		free(buffer);
		ft_check_line(ptr,fd,buffer);
		return (ptr);		
	}
	else if (rd == 0)
	{
		free(buffer);
		return ptr;
	}
	free(buffer);
	return ft_check_line(ptr,fd,buffer);	
} */

/* char *ft_check_line(char *ptr, int fd, char *buffer)
{
	int rd;
	
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return NULL;
	rd = read(fd, buffer, BUFFER_SIZE);
	buffer[rd] = '\0';
	while (rd > 0 && ft_strchr(buffer, '\n'))
	{
		ptr = ft_strjoin(ptr,buffer);
		free(buffer);
        rd = read(fd, buffer, BUFFER_SIZE);
        buffer[rd] = '\0';
	}
    return (ptr);
} */
char *ft_check_line(char *ptr, int fd, char *buffer)
{
	int rd;
	char *temp;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return NULL;
    while ((rd = read(fd, buffer, BUFFER_SIZE)) > 0)
    {
        buffer[rd] = '\0';

        if (ft_strchr(buffer, '\n') == 1)
        {
            temp = ft_strjoin(ptr, buffer);
            free(ptr);
            free(buffer);
            return temp;
        }
        temp = ft_strjoin(ptr, buffer);  
        free(ptr);
        ptr = temp;
    }
    // free(buffer);
    return ptr;
}

char *get_next_line(int fd)
{
    static char *ptr;
    char *buffer;
    if (fd<0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > 2147483647)
        return (NULL);
	ptr = ft_check_line(ptr,fd, buffer);
    return (ptr);
} 

int main()
{
    int fd = open("tjriba.txt", O_CREAT | O_RDWR | O_APPEND);
    char *ptr = get_next_line(fd);
    printf("%s", ptr);
    free(ptr);
    return (0);
}
/* char *ft_check_line(char *ptr, int fd, char *buffer)
{
    int rd;

    buffer = malloc(BUFFER_SIZE + 1);
    if (!buffer)
        return NULL;
    rd = read(fd, buffer, BUFFER_SIZE);
    if (rd> 0)
        buffer[rd] = '\0';
    while(ft_strchr(buffer,'\n') == NULL)
} */
/* int main()
{
    int fd = open("tjriba.txt", O_CREAT | O_RDWR | O_APPEND);
    char *str = malloc(BUFFER_SIZE + 1);
    char *ptr = malloc(BUFFER_SIZE + 1);
    size_t rd = read(fd,str,BUFFER_SIZE);
    size_t rl = read(fd,ptr,BUFFER_SIZE);
    str[rd] = '\0';
    ptr[rl] = '\0';
    printf("%s --> %s", str, ptr);
	return (0);
} */