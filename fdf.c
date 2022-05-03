/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 14:39:23 by gfernand          #+#    #+#             */
/*   Updated: 2022/05/03 18:42:19 by gfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	int	fd;

	if (argc != 2)
		ft_putfinish("WRONG PARAMETERS\n");
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		ft_putfinish("WRONG MAP");

	return (0);
}
