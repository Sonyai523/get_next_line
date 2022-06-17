/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarthric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 16:41:23 by rarthric          #+#    #+#             */
/*   Updated: 2021/12/28 15:45:06 by rarthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

char	*ft_end(char *line, char *buff)
{
	int	i_l;
	int	i_b;
	int	i_n;

	i_l = 0;
	i_b = 0;
	if (line == NULL)
		return (NULL);
	while (line[i_l] != '\n' && line[i_l] != '\0')
		i_l++;
	if (line[i_l] == '\n')
	{
		i_l++;
		i_n = i_l;
		while (line[i_l] != '\0')
			buff[i_b++] = line[i_l++];
		line[i_n] = '\0';
		while (i_b < BUFFER_SIZE)
			buff[i_b++] = '\0';
	}
	return (line);
}

char	*ft_place(int fd, char *line, char *buff)
{
	if (line == NULL)
		return (NULL);
	while (ft_strchr(line, '\n') == 0)
	{
		if (read(fd, buff, BUFFER_SIZE) == 0)
		{
			line = ft_end(line, buff);
			return (line);
		}
		else if (ft_strchr(line, '\n') != 1)
			line = ft_strjoin(line, buff);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char		buff[BUFFER_SIZE];
	char			*line;

	line = malloc(sizeof(char) * 1);
	if (!line)
		return (NULL);
	line[0] = '\0';
	if (read(fd, buff, 0) < 0)
	{
		free (line);
		return (NULL);
	}
	line = ft_strjoin(line, buff);
	if (!ft_strlen(line))
	{
		if (read(fd, buff, BUFFER_SIZE) == 0)
		{
			free(line);
			return (NULL);
		}
		line = ft_strjoin(line, buff);
	}
	line = ft_place(fd, line, buff);
	line = ft_end(line, buff);
	return (line);
}
