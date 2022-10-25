
#include "fdf.h"

static void	ft_put_color(t_data *data, int x, int y, int c);

void	ft_read_color(t_data *data, int fd)
{
	int	x;
	int	y;
	int	c;

	y = 0;
	while (data->color[y] && y < data->rows)
	{
		x = 0;
		while (x < data->columns)
		{
			c = data->height[y][x];
			if (c < 0)
				c *= -1;
			if (data->color[y][x] == -1)
				ft_put_color(data, x, y, c);
			x++;
		}
		y++;
	}
	close(fd);
}

static void	ft_put_color(t_data *data, int x, int y, int c)
{
	if (c == 0)
		data->color[y][x] = 16777215;
	else if (c < 31)
		data->color[y][x] = 65280;
	else if (c < 51)
		data->color[y][x] = 8454658;
	else if (c > 50)
		data->color[y][x] = 12988888;
}

int	interpolate(int color1, int color2, float fraction)
{
	if (color1 == color2)
		return (color1);
	unsigned char	r1 = (color1 >> 16) & 0xff;
	unsigned char	r2 = (color2 >> 16) & 0xff;
	unsigned char	g1 = (color1 >> 8) & 0xff;
	unsigned char	g2 = (color2 >> 8) & 0xff;
	unsigned char	b1 = color1 & 0xff;
	unsigned char	b2 = color2 & 0xff;
	return (int) ((r2 - r1) * fraction + r1) << 16 |
                (int) ((g2 - g1) * fraction + g1) << 8 |
                (int) ((b2 - b1) * fraction + b1);
}
