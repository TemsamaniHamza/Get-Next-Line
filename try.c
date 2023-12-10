#include "get_next_line.h"

int ft_read(int fd, char *buffer)
{
    ssize_t rd;

    rd = read(fd,buffer,BUFFER_SIZE);
    return (rd);
}
char *ft_check_line(char *ptr, int fd, char *buffer)
{
	ssize_t rd;
	char *temp;

	buffer = malloc((size_t)(BUFFER_SIZE) + 1);
	if (!buffer)
		return NULL;
    while ((rd = ft_read(fd,buffer)) > 0)
    {
        buffer[rd] = '\0';
        if (ft_strchr(buffer, '\n') == 1)
        {
            temp = ft_strjoin(ptr, buffer);
            free(ptr);
            free(buffer);
            return (temp);
        }
        temp = ft_strjoin(ptr, buffer);  
        free(ptr);
        ptr = temp;
    }
    if (ptr == NULL || ptr[0] == 0)
        return NULL;
    free(buffer);
    return (ptr);
}

size_t  ft_check_newline(char *buffer)
{
    size_t i = 0;
    while (buffer[i] != '\n' && buffer[i] != '\0')
        i++;
    return (i);
}

char *ft_full_ptr(char *ptr, char *buffer, size_t i, int flag)
{
    size_t j = 0;
    char *reminder;
    size_t k = 0;
    if (ft_strchr(buffer,'\n')== 1)
        ptr = malloc(i + 2);
    else
        ptr = malloc(i + 1);
    while (j < i)
    {
        ptr[j] = buffer[j];
        j++;
    }
    if (ft_strchr(buffer,'\n')== 1)
    {
    ptr[j] = '\n';
    ptr[j+1] = '\0';
    }
    else
        ptr[j] = '\0';
    if (flag == 1)
    {
        reminder = malloc((ft_strlen(buffer)) - j + 1);
        if (!reminder)
        {
            free(ptr);
            return NULL;
        }
        if (buffer[j] != '\0' && buffer[j] == '\n')
            j++;
        while (buffer[j])
        {  
            reminder[k] = buffer[j];
            k++;
            j++;
        }
        reminder[k] = '\0';
        free(ptr);
        return (reminder);
    }
    return (ptr);
}

char *get_next_line(int fd)
{
    static char *ptr;
    char *buffer;
    static char *reminder;
    size_t i = 0;
    static int j;

    buffer = NULL;

    if (fd <0 || BUFFER_SIZE <= 0)
        return (NULL);
    if (j == 0)
	    buffer = ft_check_line(ptr,fd, buffer);
    else
        buffer = ft_check_line(reminder,fd, buffer);
    if (buffer == NULL)
        return NULL;
    i = ft_check_newline(buffer);
    ptr = ft_full_ptr(ptr,buffer,i,0);
    reminder = ft_full_ptr(ptr,buffer,i,1);
    if (ft_read(fd,buffer) == 0)
        free(reminder);
    j++;
    if (buffer != NULL)
        free(buffer);
    return (ptr);
}

int main()
{
    int fd = open("test.txt", O_CREAT | O_RDWR | O_APPEND);
    char *str;
    int i = 0;
    str = get_next_line(fd);
        printf("--%s--", str);
    free(str);


    // str = get_next_line(fd);
    // printf("%s", str);
    // free(str);

    // str = get_next_line(fd);
    // printf("%s", str);
    // free(str); 
    close (fd);
} 
