/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarthric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 16:56:43 by rarthric          #+#    #+#             */
/*   Updated: 2021/12/01 16:56:46 by rarthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	if (str == NULL)
		return (0);
	i = 0;
	while (*str++ != '\0')
		i++;
	return (i);
}

int	ft_strchr(char *str, int c)
{
	if (str == NULL)
		return (0);
	while (*str != c)
	{
		if (*str == '\0')
			return (0);
		str++;
	}
	return (1);
}

void	ft_strlcpy(char *dst, char *src)
{
	while (*src != '\0')
		*dst++ = *src++;
	*dst = '\0';
}

void	ft_strlcat(char *dst, char *src)
{
	while (*dst != '\0')
		dst++;
	while (*src != '\0')
		*dst++ = *src++;
	*dst = '\0';
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
	{
		free(s1);
		return (NULL);
	}
	ft_strlcpy(str, s1);
	ft_strlcat(str, s2);
	while (*s2)
		*s2++ = '\0';
	free(s1);
	return (str);
}
