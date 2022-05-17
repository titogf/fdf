/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 14:55:35 by gfernand          #+#    #+#             */
/*   Updated: 2022/05/17 13:40:39 by gfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define BUFFER_SIZE 100
# define WIDE 600 //altura ventana
# define HEIGHT 900 //anchura ventana
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
int			keyb(int key, t_data *data);
int			exkey(t_data *data);
void		ft_putfinish(char *str);
char		**ft_split(char *s, char c);
int			ft_atoi(const char *str);
char		*get_next_line(int fd);
char		*ft_export_line(char *str, char *s);
int			ft_count(char *s, char c);
char		**ft_splitfree(char **str, int count);
char		*ft_leftover(char *str, char *s);
char		*ft_substr(char *s, int start, int len);
int			ft_strlen(const char *s);
char		*ft_stuff(void);
int			ft_enter(char *str);
char		*ft_strjoin(char const *s1, char const *s2, int i);
char		*ft_read(char *str, int fd);
void		*ft_free(char *aux, char *s);

#endif
