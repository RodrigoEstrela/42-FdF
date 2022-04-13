# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rdas-nev <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/07 15:28:33 by rdas-nev          #+#    #+#              #
#    Updated: 2022/04/13 16:15:12 by rdas-nev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =		fdf.c get_next_line.c get_next_line_utils.c valuescount.c libft.a liner.c \
			bargaksetra.c fil_de_fer_constructor.c win_set.c \

CFLAGS =	-Wall -Wextra -Werror

RM	=		rm -f

NAME	=	fdf

all:		$(NAME)

$(NAME): 	$(SRCS)
			cc $(SRCS) -g -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

fclean:		
			$(RM) $(NAME)

re:			fclean all
