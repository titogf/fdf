/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 14:55:35 by gfernand          #+#    #+#             */
/*   Updated: 2022/05/03 18:29:45 by gfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>

void		ft_putstr(char *str);
void		ft_putfinish(char *str);
char		**ft_split(char *s, char c);
static int	ft_count(char *s, char c);
static char	**ft_site(char **str, char *s, char c);
static char	**ft_free(char **str, int count);
char		*ft_substr(char *s, int start, int len);

#endif
