/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarthric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 16:57:00 by rarthric          #+#    #+#             */
/*   Updated: 2021/12/01 16:57:03 by rarthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_place(int fd, char *line, char *buff);
char	*ft_end(char *line, char *buff);
char	*ft_strjoin(char *s1, char *s2);
void	ft_strlcat(char *dst, char *src);
void	ft_strlcpy(char *dst, char *src);
int		ft_strlen(char *str);
int		ft_strchr(char *str, int c);

#endif
