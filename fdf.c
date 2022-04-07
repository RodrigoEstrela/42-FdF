/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdas-nev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 14:22:38 by rdas-nev          #+#    #+#             */
/*   Updated: 2022/04/07 18:34:14 by rdas-nev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<mlx.h>
#include<stdio.h>
#include"fdf.h"
#include<fcntl.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(int ac, char **av)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	int		fd;
	char	*line;
	int		columns = 0;
	int		lines = 0;

	if (ac != 2)
		return (0);
	fd = open(av[1], O_RDWR);
	columns = valuescount(get_next_line(fd));
	printf("%d\n", columns);
	while ((line = get_next_line(fd)))
    {
      //  printf("%s", line);
		lines++;
        free(line);
	}
	printf("%d", lines);

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Fil de fer");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	
	
	int Bargakṣētra = 0;
	
	if (columns >= lines)
		Bargakṣētra = columns;
	else
		Bargakṣētra = lines;

	if (Bargakṣētra <= 20)
		Bargakṣētra = 17;
	else if (Bargakṣētra <= 50)
		Bargakṣētra = 9;
	else if (Bargakṣētra <= 100)
		Bargakṣētra = 7;
	else
		Bargakṣētra = 1;


	int x = 960;
	int y = 1079;
	int xstart = x;
	int ystart = y;
	
	int ncolumns = columns - 1;
	int i = Bargakṣētra * ncolumns;

	int nlines = lines - 1;
	
	while (lines)
	{
		x = xstart;
		y = ystart;
		i = Bargakṣētra * ncolumns;
		while (i)
		{
			my_mlx_pixel_put(&img, x, y, 0x00EEE9FF);
			y--;
			for (int b = 0; b < 2; b++)
			{
				for (int a = 0; a < 2; a++)
					my_mlx_pixel_put(&img, x++, y, 0x00EEE9FF);
				x++;
				y--;
				b++;
			}
			i--;
		}
		xstart -= (Bargakṣētra * 3);
		ystart -= (Bargakṣētra * 2);
		lines--;
	}

	x = 1920/2;
	y = 1079;
	xstart = x;
	ystart = y;

	int e = Bargakṣētra * nlines;

	while (columns)
	{
		x = xstart;
		y = ystart;
		e = Bargakṣētra * nlines;
		while (e)
		{
			my_mlx_pixel_put(&img, x, y, 0x00EEE9FF);
			y--;
			for (int b = 0; b < 2; b++)
			{
				for (int a = 0; a < 2; a++)
					my_mlx_pixel_put(&img, x--, y, 0x00EEE9FF);
				x--;
				y--;
				b++;
			}
			e--;
		}
		xstart += (Bargakṣētra * 3);
		ystart -= (Bargakṣētra * 2);
		columns--;
	}
	
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
