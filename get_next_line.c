/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htemsama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 19:10:18 by htemsama          #+#    #+#             */
/*   Updated: 2023/12/07 19:10:20 by htemsama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *ft_check_line(char *ptr, int fd, char *buffer)
{
	int rd;
	
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return NULL;
	rd = read(fd, buffer, BUFFER_SIZE);
	buffer[rd] = '\0';
	if (rd > 0 && ft_strchr(buffer, '\n'))
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
	ft_check_line(ptr,fd,buffer);	
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
	char *str = get_next_line(fd);
	printf("%s", str);
	return (0);
}

