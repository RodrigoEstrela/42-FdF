/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdas-nev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 15:43:23 by rdas-nev          #+#    #+#             */
/*   Updated: 2022/04/19 16:51:16 by rdas-nev         ###   ########.fr       */
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
# define W 1750
# define H 1300
# define F float

typedef struct s_data {
	void		*img;
	char		*addr;
	int			bpp;
	int			len;
	int			e;
	int			color;
}				t_data;

typedef struct coordenadas {
	int			x;
	int			y;
	int			z;
}				t_guhuza;

typedef struct dimensions {
	int			l;
	int			c;
	int			chgx;
	int			chgy;
}				t_dimen;

typedef struct image {
	void		*mlx;
	void		*mlx_win;
	float		bs;
	char		*inp;
	t_data		img;
	t_guhuza	**m;
	t_dimen		d;
}				t_winint;

char			*ft_strchr(const char *s, int c);

char			*ft_exstrchr(char *s);

size_t			ft_strlen(const char *str);

char			*ft_strnldup(char *s1);

char			*ft_strjoin(char *s1, char *s2);

char			*ft_strdup(const char *s1);

char			*get_next_line(int fd);

size_t			ft_strlcpy(char *dst, char *src, size_t size);

int				valuescount(char *s);

int				ft_atoi(const char *str);

char			**ft_split(const char *s, char c);

void			my_mlx_pixel_put(t_data *data, int x, int y, int color);

void			super_liner(int *p, t_data img);

float			s(float x1, int y1, int x2, int y2);

float			bargaksetra(int columns, int lines);

t_dimen			dim_formater(char *map);

t_guhuza		**calc_mesh(t_dimen d, float bs, char *str, t_guhuza **m);

t_winint		graf_init(void);

void			fil_de_fer(t_dimen dim, t_guhuza **m, t_data img);

void			line_drawer(t_dimen dim, t_guhuza **m, t_data img);

void			column_drawer(t_dimen dim, t_guhuza **m, t_data img);

float			bs_zupdater(float bargak_setra, t_dimen d, char *str);

int				error_check(int ac, char *str);

int				ft_strncmp(const char *s1, const char *s2, size_t n);

void			graph_actions(t_winint g);

char			*ft_strdup(const char *s1);

void			*ft_calloc(size_t count, size_t size);

void			y_updater(t_dimen dim, t_guhuza **matriz, float bargak_setra);

void			ft_bzero(void *s, size_t n);

void			directions(int key, t_winint *g);

void			colors(int key, t_winint *g);

void			zoom(int key, t_winint *g);

#endif
