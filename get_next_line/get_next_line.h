/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 12:22:00 by gfernand          #+#    #+#             */
/*   Updated: 2022/05/09 13:47:57 by gfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFFER_SIZE 100
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_export_line(char *str, char *s);
char	*ft_leftover(char *str, char *s);
int		ft_strlen(const char *s);
char	*ft_stuff(void);
int		ft_enter(char *str);
char	*ft_substr(char const *s, unsigned int start, int len);
char	*ft_strjoin(char const *s1, char const *s2, int i);
char	*ft_read(char *str, int fd);
void	*ft_free(char *aux, char *s);

#endif
