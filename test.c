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
            return NULL;
        }
        ptr = temp;
    }
    if (rd == 0 && ptr[0] == 0 )
    {
        free(buffer);
        return NULL;
    }
    if (rd == 0)
    {
        free(buffer);
        return ptr;
    }
        // return NULL;
    free(buffer);
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

    ptr = malloc(i + 2);
    while (buffer[j] != '\0' && buffer[j] != '\n')
    {
        ptr[j] = buffer[j];
        j++;
    }
    ptr[j] = '\n';
    ptr[j + 1] = '\0';
    if (flag == 1)
    {
        reminder = malloc((ft_strlen(buffer)) - j + 1);
        if (!reminder)
        {
            free(ptr);
            return NULL;
        }
        j++;
        while (buffer[j] != '\0')
        {   
            reminder[k] = buffer[j];
            k++;
            j++;
        }
        reminder[k] = '\0';
        free(ptr);
        // free(buffer);
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

    buffer = NULL;

    // printf("how many times the functions is used is : %d\n", j);
    if (fd <0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > 2147483647)
        return (NULL);
    if (j == 0)
    {
        printf("j = 0 -> %d->", j);
	    buffer = ft_check_line(ptr,fd, buffer);
        if (buffer == NULL)
        {
            free(buffer);
            return NULL;
        }
        // printf("1 | the buffer in this moment is %s\n", buffer);
        i = ft_check_newline(buffer);
        ptr = ft_full_ptr(ptr,buffer,i,0);
        // printf("2 | the ptr in this moment is %s", ptr);
        reminder = ft_full_ptr(ptr,buffer,i,1);
        // printf("3 | the reminder is : ++%s++\n", reminder);
    }
    if (j > 0)
    {
        printf("j > 0 -> %d->", j);
	    buffer = ft_check_line(reminder,fd, buffer);
        if (buffer == NULL)
        {
            free(buffer);
            return NULL;
        }
        i = ft_check_newline(buffer);
        ptr = ft_full_ptr(ptr,buffer,i,0);
        reminder = ft_full_ptr(ptr,buffer,i,1);
        // free(reminder);
    }
    j++;
    if (buffer != NULL)
        free(buffer);
    // printf("the ptr rn is --%d--", ptr[0]);
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

    str = get_next_line(fd);
    printf("%s", str);
    free(str);
    close (fd);
}
