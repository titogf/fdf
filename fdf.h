/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 14:55:35 by gfernand          #+#    #+#             */
/*   Updated: 2022/10/20 16:42:13 by gfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define BUFFER_SIZE 100
# define HEIGHT 900 //altura ventana
# define WIDE 1200 //anchura ventana
# define PIXEL 50
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <math.h>
# include "minilibx/mlx.h"

typedef struct s_brsh
{
	int	x0;
	int	y0;
	int	x1;
	int	y1;
	int	dx;
	int	dy;
	int	stepx;
	int	stepy;
	int	p;
}	t_brsh;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		**height;
	int		**color;
	int		rows;
	int		columns;
	int		space;
	int		div2;
	int		posx;
	int		posy;
	t_brsh	brsh;
}	t_data;

void		ft_window(t_data *data);
void		ft_malloc(t_data *data, int fd);
void		ft_get_map(t_data *data, char *av, int fd);
void		ft_draw_x(t_data *data, int n);
void		ft_legend(t_data *data, int n);
void		ft_len1(t_data *data);

void		ft_bresenham(t_data *data, int mx, int my);

char		**ft_split(char *s, char c);
char		**ft_splitfree(char **str);

void		ft_putpixel(t_data *data, int mx, int my);
int			ft_atoi_base(char *str, int base);
void		ft_putfinish(char *str);

char		*get_next_line(int fd);
char		*ft_export_line(char *str, char *s);
int			ft_count(char *s, char c);
char		*ft_leftover(char *str, char *s);
char		*ft_substr(char *s, int start, int len);
int			ft_strlen(const char *s);
char		*ft_stuff(void);
int			ft_enter(char *str);
char		*ft_strjoin(char const *s1, char const *s2, int i);
char		*ft_read(char *str, int fd);
void		*ft_free(char *aux, char *s);

#endif
