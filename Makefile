# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rdas-nev <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/22 10:03:56 by rdas-nev          #+#    #+#              #
#    Updated: 2022/04/22 12:52:15 by rdas-nev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= bargaksetra.c fdf.c get_next_line_utils.c upview.c colors.c \
		  graph_actions.c valuescount.c directions.c fil_de_fer_constructor.c \
		  height_changer.c win_set.c errors_check.c get_next_line.c liner.c zoom.c \


OBJS	= $(addprefix objs/,$(SRCS:.c=.o))

CFLAGS	= -Wall -Wextra -Werror

RM		= rm -f

NAME	= fdf

# COLORS

DARKRED	= \033[0;31m
RED		= \033[1;3;91m
GREEN	= \033[1;3;92m
BLUE	= \033[1;3;94m
YELLOW	= \033[1;3;93m
CYAN	= \033[0;36m
NC		= \033[0;0m

all:		$(NAME)

objs/%.o: srcs/%.c
			@$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

$(NAME): 	$(OBJS)
			@cc $(OBJS) libftprintf.a libft.a -g -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
			@echo  "\n${YELLOW}A wild ${RED}F${GREEN}d${BLUE}f ${YELLOW}appears in current dir...${NC}\n"

clean:
			@$(RM) $(OBJS)
			@echo "\n${DARKRED}No more objs! ${NC}\n"

fclean:		clean
			@$(RM) $(NAME)
			@echo "\n${RED}F${GREEN}d${BLUE}f ${CYAN}says goodbye! ${NC}\n"

re:			fclean all
			@echo "\n${RED}F${GREEN}d${BLUE}f ${CYAN}remade! ${NC}\n" 
