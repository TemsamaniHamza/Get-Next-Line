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
        if (!temp)
        {
            free(buffer);
            return NULL;  // Handle ft_strjoin failure
        }
        ptr = temp;
    }
    if (rd == 0)
    {
        free(buffer);
        return ptr;
    }
        // return NULL;
    // free(buffer);
    return ptr;
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

    ptr = malloc(i + 1);
    while (buffer[j] != '\0' && buffer[j] != '\n')
    {
        ptr[j] = buffer[j];
        j++;
    }
    ptr[j] = '\n';
    ptr[j + 1] = '\0';
    reminder = malloc((ft_strlen(buffer)) - j);
    if (flag == 1)
    {
        j++;
        while (buffer[j] != '\0')
        {   
            reminder[k] = buffer[j];
            k++;
            j++;
        }
        reminder[k] = '\0';
        return (reminder);
        // printf("---%s\n", reminder);
    }
    return (ptr);
}
char *get_next_line(int fd)
{
    static char *ptr;
    char *buffer;
    static char *reminder;
    size_t i = 0;
    static int j = 0;

    // printf("how many times the functions is used is : %d\n", j);
    if (fd <0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > 2147483647)
        return (NULL);
    if (j == 0)
    {
	    buffer = ft_check_line(ptr,fd, buffer);
        if (buffer == NULL)
            return NULL;
        // printf("1 | the buffer in this moment is %s\n", buffer);
        i = ft_check_newline(buffer);
        ptr = ft_full_ptr(ptr,buffer,i,0);
        // printf("2 | the ptr in this moment is %s", ptr);
        reminder = ft_full_ptr(ptr,buffer,i,1);
        // printf("3 | the reminder is : ++%s++\n", reminder);
    }
    if (j > 0)
    {
	    buffer = ft_check_line(reminder,fd, buffer);
        if (buffer == NULL)
            return NULL;
        // printf("1 | the buffer in this moment is %s\n", buffer);
        i = ft_check_newline(buffer);
        // printf("x | the index where the new line is in is %zu\n", i);
        ptr = ft_full_ptr(ptr,buffer,i,0);
        // printf("2 | the ptr in this moment is %s\n", ptr);
        reminder = ft_full_ptr(ptr,buffer,i,1);
        // printf("3 | the reminder is : ++%s++\n", reminder);
        // return(ptr);
    }
    j++;
    free(buffer);
    return (ptr);
}

int main()
{
    int fd = open("get_next_line.h", O_CREAT | O_RDWR | O_APPEND);
    char *str;

    int i = 0;
    while (i < 19)
    {
        str = get_next_line(fd);
        printf("%s", str);
        i++;
    }
/*     str = get_next_line(fd);
    printf("%s", str);
    free(str);  */
}
/* char *get_next_line(int fd)
{
    char *ptr;
    char *buffer;
    size_t i = 0;
    if (fd<0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > 2147483647)
        return (NULL);
	ptr = ft_check_line(buffer,fd, ptr);
    i = ft_check_newline(ptr);
    buffer = ft_full_ptr(buffer,ptr,i,0);
    free(ptr);
    return (buffer);
}  */