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

