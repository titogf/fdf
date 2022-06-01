/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 14:55:35 by gfernand          #+#    #+#             */
/*   Updated: 2022/06/01 13:21:52 by gfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define BUFFER_SIZE 100
# define HEIGHT 900 //altura ventana
# define WIDE 1200 //anchura ventana
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include "minilibx/mlx.h"

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		rows;
	int		columns;
	int		**color;
	int		**height;
}	t_data;
int			keyb(int key, t_data *data);
int			exkey(t_data *data);
int			ft_malloc(t_data *data, int fd);
char		**ft_get_map(t_data *data, char *av, int fd);
int			ft_map_point(t_data *data, char **s, int i, int count);
int			ft_matrizlen(t_data *data, int fd);
void		ft_putfinish(char *str);
char		**ft_split(char *s, char c);
int			ft_atoi_base(char *str, int base);
char		*get_next_line(int fd);
char		*ft_export_line(char *str, char *s);
int			ft_count(char *s, char c);
char		**ft_splitfree(char **str);
char		*ft_leftover(char *str, char *s);
char		*ft_substr(char *s, int start, int len);
int			ft_strlen(const char *s);
char		*ft_stuff(void);
int			ft_enter(char *str);
char		*ft_strjoin(char const *s1, char const *s2, int i);
char		*ft_read(char *str, int fd);
void		*ft_free(char *aux, char *s);

#endif
