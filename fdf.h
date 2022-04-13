/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdas-nev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 15:43:23 by rdas-nev          #+#    #+#             */
/*   Updated: 2022/04/13 17:05:39 by rdas-nev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include<stdio.h>
# include<stdlib.h>
# include<fcntl.h>
# include<unistd.h>
# include<mlx.h>

# define BUFFER_SIZE 10
# define GREEN 0x0000FF00
# define WINW 1920
# define WINH 1080
# define F float

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bpp;
	int		len;
	int		e;
}			t_data;

typedef struct coordenadas {
	int		x;
	int		y;
	int		z;
}			t_guhuza;

typedef struct dimensions {
	int		l;
	int		c;
}			t_dimen;

typedef struct image {
	void	*mlx;
	void	*mlx_win;
	t_data	img;
}			t_winint;

char		*ft_strchr(const char *s, int c);

char		*ft_exstrchr(char *s);

size_t		ft_strlen(const char *str);

char		*ft_strnldup(char *s1);

char		*ft_strjoin(char *s1, char *s2);

char		*ft_strdup(const char *s1);

char		*get_next_line(int fd);

size_t		ft_strlcpy(char *dst, char *src, size_t size);

int			valuescount(char *s);

long long	ft_atoi(const char *str);

char		**ft_split(const char *s, char c);

void		my_mlx_pixel_put(t_data *data, int x, int y, int color);

void		super_liner(int *p, t_data img);

float		s(float x1, int y1, int x2, int y2);

int			bargaksetra(int columns, int lines);

t_dimen		dim_formater(char *map);

t_guhuza	**calc_mesh(t_dimen dim, int bargak_setra, char *str, t_guhuza **m);

void		fil_de_fer(t_dimen dim, t_guhuza **m, t_data img);

void		line_drawer(t_dimen dim, t_guhuza **m, t_data img);

void		column_drawer(t_dimen dim, t_guhuza **m, t_data img);

t_winint	graf_init(void);

#endif
