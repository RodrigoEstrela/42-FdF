/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdas-nev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 15:43:23 by rdas-nev          #+#    #+#             */
/*   Updated: 2022/04/25 11:40:18 by rdas-nev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include<stdio.h>
# include<stdlib.h>
# include<fcntl.h>
# include<unistd.h>
# include<mlx.h>
# include"ft_printf.h"
# include"libft.h"

# define BUFFER_SIZE 10
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
	int			colorcode;
}				t_data;

typedef struct coordenadas {
	int			x;
	int			y;
	int			z;
	int			color;
}				t_guhuza;

typedef struct dimensions {
	int			l;
	int			c;
	int			*chg;
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

char			*ft_exstrchr(char *s);

char			*get_next_line(int fd);

int				valuescount(char *s);

char			**ft_split(const char *s, char c);

void			my_mlx_pixel_put(t_data *data, int x, int y, int color);

void			super_liner(int *p, t_data img);

float			bargaksetra(int columns, int lines);

t_dimen			dim_formater(char *map);

t_guhuza		**calc_mesh(t_dimen d, float bs, char *str, t_guhuza **m);

t_winint		graf_init(void);

void			fil_de_fer(t_dimen dim, t_guhuza **m, t_data img);

float			bs_zupdater(float bargak_setra, t_dimen d, char *str);

int				error_check(int ac, char *str);

int				ft_strncmp(const char *s1, const char *s2, size_t n);

void			graph_actions(t_winint g);

void			y_updater(t_dimen dim, t_guhuza **matriz, float bargak_setra);

void			directions(int key, t_winint *g);

void			colors(int key, t_winint *g);

void			zoom(int key, t_winint *g);

void			height_changer(int key, t_winint *g);

void			draw_img(t_winint *g);

void			clean_slate(t_winint *g);

void			up_view(t_winint *g);

void			reset_view(int key, t_winint *g);

char			*ft_strjoin(char *s1, char *s2);

char			*ft_strnldup(char *s1);

size_t			ft_strlen(const char *str);

int				color_reader(char *s);

t_guhuza		**malltrix(t_guhuza **m, t_winint *g);

#endif
