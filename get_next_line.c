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

char *ft_check_line(fd, buffer)
{
	char *tmp;
	int rd;

	tmp = malloc(BUFFER_SIZE * sizeof(char));
	rd = read(fd, tmp, BUFFER_SIZE);
	printf("%s", tmp);
	return (tmp);
}

/* char *get_next_line(int fd)
{
    static char *ptr;
    char *buffer;
    if (fd<0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > 2147483647)
        return (NULL);
	buffer = ft_check_line(fd, buffer);	
	return (buffer);
} */

