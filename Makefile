# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aattak <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/19 10:16:42 by aattak            #+#    #+#              #
#    Updated: 2024/06/03 13:25:00 by aattak           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################
 ######################### Variables ##########################
################################################################

NAME 			=	fractol

B_NAME 			=	fractol_bonus

HEADERS			=	-I includes/ -I /usr/local/include

LIBS			=	-L /usr/local/lib -lmlx_Linux -L /usr/lib -lm -lXext -lX11

CC				=	cc

CFLAGS			=	-Wall -Wextra -Werror -O3

RM				=	rm -f

FRACTOL_SRC		=	srcs/fractol.c

FRACTOL_OBJ		=	$(FRACTOL_SRC:.c=.o)

B_FRACTOL_SRC	=	bonus/fractol_bonus.c

B_FRACTOL_OBJ	=	$(B_FRACTOL_SRC:.c=.o)

SRCS			=	srcs/mlx/complex_shifting.c srcs/mlx/generate_color.c \
					srcs/mlx/iterations.c srcs/mlx/mlx.c srcs/mlx/mlx_hooks.c \
					srcs/mlx/moves.c srcs/mlx/render_fractal.c srcs/mlx/shift_color.c \
					srcs/mlx/zoom.c srcs/input_output/parsing.c srcs/input_output/utils.c \
					srcs/input_output/writing.c srcs/fractals/fractal_init.c \
					srcs/fractals/mandelbrot.c srcs/fractals/julia.c

OBJS			=	$(SRCS:.c=.o)

B_SRCS			=	bonus/input_output/parsing_bonus.c bonus/fractals/mandelbrot_cube_bonus.c \
					bonus/fractals/julia_cube_bonus.c bonus/fractals/burning_ship_bonus.c \
					bonus/fractals/bird_of_prey_bonus.c

B_OBJS			=	$(B_SRCS:.c=.o)

################################################################
 ################### Fractol Creation Rules ################### 
################################################################

.c.o:
		@echo "\033[1;32m\nCompiling objects ...\033[0m"
		$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

all: $(NAME)

$(OBJS): includes/fractol.h

$(B_OBJS): includes/fractol.h includes/fractol_bonus.h

$(FRACTOL_OBJ): includes/fractol.h

$(B_FRACTOL_OBJ): includes/fractol.h includes/fractol_bonus.h

$(NAME): $(OBJS) $(FRACTOL_OBJ)
		@echo "\033[1;32m\nBulding fractol ...\033[0m"
		$(CC) $(CFLAGS) $(HEADERS) $(FRACTOL_OBJ) $(OBJS) $(LIBS) -o $(NAME)
		@echo "\033[1;32m\nfractol built successfully\n\033[0m"

$(B_NAME) : $(OBJS) $(B_OBJS) $(B_FRACTOL_OBJ)
		@echo "\033[1;32m\nBulding fractol_bonus ...\033[0m"
		$(CC) $(CFLAGS) $(HEADERS) $(B_FRACTOL_OBJ) $(OBJS) $(B_OBJS) $(LIBS) -o $(B_NAME)
		@echo "\033[1;32m\nfractol_bonus built successfully\n\033[0m"

bonus: $(B_NAME)

################################################################
 ###################### General Rules ######################### 
################################################################

re: fclean all

clean:
		@echo "\033[1;31m\nCleaning objects ...\033[0m"
		@echo "\033[1;31m\nRemove fractol object ...\033[0m"
		$(RM) $(FRACTOL_OBJ)
		@echo "\033[1;31m\nRemove fractol_bonus object ...\033[0m"
		$(RM) $(B_FRACTOL_OBJ)
		@echo "\033[1;31m\nRemove srcs objects ...\033[0m"
		$(RM) $(OBJS)
		@echo "\033[1;31m\nRemove bonus srcs objects ...\033[0m"
		$(RM) $(B_OBJS)
		@echo "\033[1;32m\nCleaning terminated successfully\n\033[0m"

fclean: clean
		@echo "\033[1;31m\nCleaning executables ...\033[0m"
		@echo "\033[1;31m\nRemove fractol ...\033[0m"
		$(RM) $(NAME)
		@echo "\033[1;31m\nRemove fractol_bonus ...\033[0m"
		$(RM) $(B_NAME)
		@echo "\033[1;32m\nFull Cleaning terminated successfully\n\033[0m"

.PHONY: all clean fclean re bonus
.SECONDARY: $(FRACTOL_OBJ) $(B_FRACTOL_OBJ) $(OBJS) $(B_OBJS)
