# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hameur <hameur@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/09 18:16:10 by hameur            #+#    #+#              #
#    Updated: 2022/05/17 15:42:26 by hameur           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := so_long

CC := gcc

CFLAGS := -Wall -Wextra -Werror -lmlx -framework OpenGL -framework AppKit

SRC :=	so_long.c\
		so_long_utils.c\
		checking_maps/read_map.c\
		checking_maps/check_map.c\
		checking_maps/put_map.c\
		checking_maps/put_xpm.c\
		get_next_line/ft_putstr_fd.c\
		get_next_line/ft_putnbr_fd.c\
		get_next_line/ft_strdup.c\
		get_next_line/ft_strjoin.c\
		get_next_line/get_next_line_utils.c\
		get_next_line/get_next_line.c

OBJ := $(SRC:.c=.o)

###___Colors___###
RED= \033[0;31m
GREEN= \033[0;32m
YELLOW= \033[1;33m
WHITE= \033[0;37m

all: $(NAME)
	@echo "${YELLOW}Meking${GREEN} So_Long Game ${WHITE}..."

$(NAME): $(OBJ)
	@$(CC) $(FLAGS) $^ -o $@ -lmlx -framework OpenGL -framework AppKit
	@echo "${YELLOW}Meking${GREEN} So_Long Game ${WHITE}..."
	
%.o : %.c so_long.h
	@$(CC) $(FLAGS) -c $< -o $@ 
	
clean:
	@rm -rf so_long
	@echo "${RED}Removin ${GREEN} So_Long Game ${WHITE}..."
	
fclean: clean
	@rm -rf $(OBJ)

re: @clean all