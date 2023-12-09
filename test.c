#include "get_next_line.h"

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

size_t  ft_check_newline(char *buffer)
{
    size_t i = 0;
    while (buffer[i] && buffer[i] != '\n')
        i++;
    return (i);
}
char *ft_full_ptr(char *ptr, char *buffer, size_t i)
{
    size_t j = 0;
    ptr = malloc(i + 1);
    while (buffer[j] != '\0' &&buffer[j] != '\n')
    {
        ptr[j] = buffer[j];
        j++;
    }
    ptr[j] = '\n';
    ptr[j + 1] = '\0';
    return (ptr);
}
char *get_next_line(int fd)
{
    static char *ptr;
    static char *buffer;
    size_t i = 0;
    if (fd<0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > 2147483647)
        return (NULL);
	buffer = ft_check_line(ptr,fd, buffer);
    i = ft_check_newline(buffer);
    ptr = ft_full_ptr(ptr,buffer,i);
    free(buffer);
    return (ptr);
} 

int main()
{
    int fd = open("tjriba.txt", O_CREAT | O_RDWR | O_APPEND);
    char *str;
    str = get_next_line(fd);
    printf("%s", str);
    free(str);

     str = get_next_line(fd);
    printf("%s", str);
    free(str); 
 
/*     str = get_next_line(fd);
    printf("%s", str);
    free(str);
    return (0); */
}