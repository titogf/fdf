/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 14:55:35 by gfernand          #+#    #+#             */
/*   Updated: 2022/05/10 15:00:26 by gfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <mlx.h>

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
}	t_data;
void		ft_putfinish(char *str);
char		**ft_split(char *s, char c);
char		*ft_substr(char *s, int start, int len);
int			ft_pixel(t_data *data);

#endif
