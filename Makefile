# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmateo-t <mmateo-t@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/11 16:02:18 by mmateo-t          #+#    #+#              #
#    Updated: 2020/06/12 19:02:28 by mmateo-t         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#What we need
	#change srcs
	#change minilibx depends on the OS

#AUTHOR mmateo-t
#USAGE

#make          #compile all binary
#make clean		#remove all binaries
#make fclean		#remove all binaries and executable 

SRCS_DIR:= files/srcs/
SRCS := $(wildcard $(SRCS_DIR)*.c) \
		$(wildcard $(GNL)*.c) \
		$(wildcard $(SRCS_DIR)config/*.c)

OBJS := $(SRCS:%.c=%.o)
OBJS_DIR := ./files/cub3D/objects
NAME:= cub3D
CC:= gcc 
MLXFLAG =   -L/usr/X11/lib /usr/X11/lib/libmlx.a -lXext -lX11 -lmlx
#CFLAGS:= -Wall -Werror -Wextra
#MLX_DIR:= files/lib/minilibx-linux
RM :=	rm -rvf
LIBFT_DIR:= ./files/lib/libft
DEBUG_FLAG:= -g
GNL:= files/lib/get_next_line/


all:	libft minilibx $(NAME)
		@echo "Compiling all files"
		@echo "cub3D built"

$(NAME): $(OBJS)
	$(CC) -g $(OBJS) $(GNL)*.c -o $(NAME) $(MLXFLAG) -L$(LIBFT_DIR) $(LIBFT_DIR)/libft.a 

$(%.o): $(%.c)
		$(CC) -c $^ -o $@ 
		@echo "Creating objects"

libft:
		make -C $(LIBFT_DIR)
		
minilibx:
#		make -C $(MLX_DIR)

debug:
	$(CC) $(OBJS) $(GNL)*.c -o $(NAME) -L$(LIBFT_DIR) $(LIBFT_DIR)/libft.a $(DEBUG_FLAG)
		@echo "Debugging executable Created"
clean:
		@echo "Removing objects"
		make -C $(LIBFT_DIR) clean
#		make -C $(MLX_DIR) clean
		$(RM) $(OBJS)
fclean:
		make clean
		$(RM) $(NAME)
		make -C $(LIBFT_DIR) fclean
		@echo "Removed executable"

re:
	make fclean all
	@echo "All files has been deleted and recompiled"

normi:
	norminette files/lib
	norminette files/srcs

.PHONY: clean fclean all re objects debug minilibx libft objects normi
