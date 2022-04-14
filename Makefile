# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rdas-nev <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/07 15:28:33 by rdas-nev          #+#    #+#              #
#    Updated: 2022/04/14 16:20:13 by rdas-nev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =		srcs/*.c srcs/libft.a

CFLAGS =	-Wall -Wextra -Werror

RM	=		rm -f

NAME	=	fdf

all:		$(NAME)

$(NAME): 	$(SRCS)
			cc $(SRCS) -g -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

fclean:		
			$(RM) $(NAME)

re:			fclean all
