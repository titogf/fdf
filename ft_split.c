/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 16:40:27 by gfernand          #+#    #+#             */
/*   Updated: 2022/05/03 18:28:00 by gfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	**ft_split(char *s, char c)
{
	size_t	count;
	char	**str;

	count = ft_count(s, c);
	str = (char **)malloc(sizeof(char *) *(count + 1));
	if (!str)
		return (NULL);
	ft_site(str, s, c);
	return (str);
}

static int	ft_count(char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 1;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1])
			count++;
		i++;
	}
	if (s[0] == c || s[0] == '\0')
		count--;
	return (count);
}

static char	**ft_site(char **str, char *s, char c)
{
	int	i;
	int	found;
	int	count;
	int	start;

	i = 0;
	found = 1;
	count = ft_count(s, c);
	while (found <= count)
	{
		if (s[i] != c)
		{
			start = i++;
			while (s[i] != c && s[i])
				i++;
			str[found - 1] = ft_substr(s, start, (i - 1) - start + 1);
			if (str == NULL)
				return (ft_free(str, count));
			found++;
		}
		else
			i++;
	}
	str[found - 1] = NULL;
	return (str);
}

char	*ft_substr(char *s, int start, int len)
{
	int		i;
	char	*d;

	if (s == '\0')
		return (NULL);
	i = 0;
	d = (char *)malloc(sizeof(char) * len + 1);
	if (!d)
		return (NULL);
	while (s[start] && i < len)
	{
		d[i] = s[start];
		i++;
		start++;
	}
	d[i] = '\0';
	return (d);
}

static char	**ft_free(char **str, int count)
{
	while (count >= 0)
	{
		free(str[count]);
		count--;
	}
	free(str);
	return (NULL);
}
