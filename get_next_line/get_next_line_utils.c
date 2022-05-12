/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 13:38:12 by gfernand          #+#    #+#             */
/*   Updated: 2022/05/12 15:12:35 by gfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_stuff(void)
{
	char	*e;

	e = malloc(sizeof(char *) * 1);
	*e = '\0';
	return (e);
}

int	ft_enter(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_substr(char *s, int start, int len)
{
	int		i;
	char	*d;

	if (!s || len <= 0)
		return (NULL);
	i = 0;
	d = (char *)malloc(sizeof(char) * (len + 1));
	if (!d)
		return (NULL);
	while (s[start] && i < len)
	{
		d[i] = s[start];
		i++;
		start++;
	}
	d[len] = '\0';
	return (d);
}

char	*ft_strjoin(char const *s1, char const *s2, int i)
{
	char	*string;
	int		m;

	if (ft_strlen(s1) + ft_strlen(s2) == 0)
		return (NULL);
	string = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!string)
		return (NULL);
	m = 0;
	while (s1 != NULL && s1[i])
	{
		string [m] = s1[i];
		i++;
		m++;
	}
	i = 0;
	while (s2[i])
	{
		string[m] = s2[i];
		m++;
		i++;
	}
	string[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	return (string);
}
