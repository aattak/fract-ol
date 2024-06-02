# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aattak <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/19 10:16:42 by aattak            #+#    #+#              #
#    Updated: 2024/06/02 21:53:48 by aattak           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			=	fractol

B_NAME 			=	fractol_bonus

HEADERS			=	-I mandatory/ -I /usr/local/include

B_HEADERS		=	-I bonus/

LIBS			=	-L /usr/local/lib -lmlx_Linux -L /usr/lib -lm -lXext -lX11

LIB_FRACTOL		=	libfractol.a

B_LIB_FRACTOL	=	libfractol_bonus.a

CC				=	cc

CFLAGS			=	-Wall -Wextra -Werror -O3

RM				=	rm -f

SRCS			=	mandatory/fractol.c

OBJS			=	$(SRCS:.c=.o)

B_SRCS			=	bonus/fractol_bonus.c

B_OBJS			=	$(B_SRCS:.c=.o)

LIB_SRCS		=	mandatory/mlx/complex_shifting.c mandatory/mlx/generate_color.c \
					mandatory/mlx/iterations.c mandatory/mlx/mlx.c mandatory/mlx/mlx_hooks.c \
					mandatory/mlx/moves.c mandatory/mlx/render_fractal.c mandatory/mlx/shift_color.c \
					mandatory/mlx/zoom.c mandatory/input_output/parsing.c mandatory/input_output/utils.c \
					mandatory/input_output/writing.c mandatory/fractals/fractal_init.c \
					mandatory/fractals/mandelbrot.c mandatory/fractals/julia.c

LIB_OBJS		=	$(LIB_SRCS:.c=.o)

B_LIB_SRCS		=	bonus/input_output/parsing_bonus.c bonus/fractals/mandelbrot_cube_bonus.c \
					bonus/fractals/julia_cube_bonus.c bonus/fractals/burning_ship_bonus.c \
					bonus/fractals/bird_of_prey_bonus.c

B_LIB_OBJS		=	$(B_LIB_SRCS:.c=.o)

###############################################################################

.c.o:
		$(CC) $(CFLAGS) $(HEADERS) $(B_HEADERS) -c $< -o $@

all: $(NAME)

################################################################
#################### Library Creation Rules ####################
################################################################

$(LIB_OBJS): $(LIB_SRCS) mandatory/fractol.h

$(LIB_FRACTOL): $(LIB_OBJS)
		ar rcs $(LIB_FRACTOL) $(LIB_OBJS)

$(B_LIB_OBJS): $(B_LIB_SRCS) mandatory/fractol.h bonus/fractol_bonus.h

$(B_LIB_FRACTOL): $(LIB_OBJS) $(B_LIB_OBJS)
		ar rcs $(B_LIB_FRACTOL) $(LIB_OBJS) $(B_LIB_OBJS)

################################################################
#################### Fractol Creation Rules ####################
################################################################

$(OBJS): $(SRCS) mandatory/fractol.h

$(NAME): $(LIB_FRACTOL) $(OBJS)
		$(CC) $(CFLAGS) $(HEADERS) $(OBJS) $(LIB_FRACTOL) $(LIBS) -o $(NAME)

$(B_OBJS): $(B_SRCS) mandatory/fractol.h bonus/fractol_bonus.h

$(B_NAME) : $(LIB_FRACTOL) $(B_LIB_FRACTOL) $(B_OBJS)
		$(CC) $(CFLAGS) $(HEADERS) $(B_HEADERS) $(B_OBJS) $(B_LIB_FRACTOL) $(LIBS) -o $(B_NAME)

bonus: $(B_NAME)

################################################################
######################## General Rules #########################
################################################################

re: fclean all

clean:
		$(RM) $(OBJS)
		$(RM) $(B_OBJS)
		$(RM) $(LIB_OBJS)
		$(RM) $(B_LIB_OBJS)
		$(RM) $(LIB_FRACTOL)
		$(RM) $(B_LIB_FRACTOL)

fclean: clean
		$(RM) $(NAME)
		$(RM) $(B_NAME)

###############################################################################

.PHONY: all clean fclean re bonus
.SECONDARY: $(OBJS) $(B_OBJS) $(LIB_OBJS) $(B_LIB_OBJS) $(LIB_FRACTOL) $(B_LIB_FRACTOL)
