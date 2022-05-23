/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 14:51:01 by gfernand          #+#    #+#             */
/*   Updated: 2022/05/23 13:16:22 by gfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_putfinish(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	exit(1);
}

int	ft_atoi(char *str)
{
	unsigned long long int	result;
	int						sig;
	int						i;

	i = 0;
	sig = 1;
	result = 0;
	if (str == NULL)
		return (-1);
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sig = sig * (-1);
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (str[i] - 48) + (result * 10);
		i++;
	}
	return (result * sig);
}
