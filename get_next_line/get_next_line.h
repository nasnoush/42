/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadahman <nadahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 10:18:13 by nadahman          #+#    #+#             */
/*   Updated: 2024/10/28 13:03:55 by nadahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

# include <unistd.h>
# include <stdlib.h>
# include <string.h>

size_t	ft_strlen(char *str);
int		found_line(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*get_next_line(int fd);
char	*ft_strdup(const char *str);

#endif
