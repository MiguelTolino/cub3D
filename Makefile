# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmateo-t <mmateo-t@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/24 16:04:19 by user42            #+#    #+#              #
#    Updated: 2020/07/09 23:17:51 by mmateo-t         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

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
		$(wildcard $(SRCS_DIR)config/*.c) \
		$(wildcard $(SRCS_DIR)engine/*.c)
SRCS_BONUS :=	$(wildcard $(SRCS_DIR)*.c) \
				$(wildcard $(GNL)*.c) \
				$(wildcard $(SRCS_DIR)config/*.c) \
				$(wildcard $(SRCS_DIR)bonus/*.c)
OBJS := $(SRCS:%.c=%.o)
OBJS_BONUS := $(SRCS_BONUS:%.c=%.o)
NAME:= cub3D
IMG:= $(NAME).bmp
CC:= gcc 
MLXFLAG =   -Lfiles/lib/minilibx-linux files/lib/minilibx-linux/libmlx.a -lXext -lX11 -lmlx -lm
#CFLAGS:= -Wall -Werror -Wextra -I.
MLX_DIR:= files/lib/minilibx-linux
RM :=	rm -rvf
LIBFT_DIR:= ./files/lib/libft
DEBUG_FLAG:= -g
GNL:= files/lib/get_next_line/


all:	libft minilibx $(NAME) msg

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(GNL)*.c -o $(NAME) $(CFLAGS) $(MLXFLAG) -L$(LIBFT_DIR) $(LIBFT_DIR)/libft.a 

bonus: libft minilibx $(OBJS_BONUS) 
	$(CC) $(OBJS_BONUS) $(GNL)*.c -o $(NAME) $(CFLAGS) $(MLXFLAG) -L$(LIBFT_DIR) $(LIBFT_DIR)/libft.a 

$(%.o): $(%.c)
		$(CC) -c $^ -o $@ 
		@echo "Creating objects"

libft:
		make -C $(LIBFT_DIR)
		
minilibx:
		make -C $(MLX_DIR)

debug:
	$(CC) $(OBJS) $(GNL)*.c -o $(NAME) -L$(LIBFT_DIR) $(LIBFT_DIR)/libft.a $(DEBUG_FLAG)
		@echo "Debugging executable Created"
clean:
		@echo "Removing objects"
		make -C $(LIBFT_DIR) clean
#		make -C $(MLX_DIR) clean
		$(RM) $(OBJS) $(OBJS_BONUS)
fclean:
		make clean
		$(RM) $(NAME) $(IMG)
		make -C $(LIBFT_DIR) fclean
		@echo "Removed executable"
msg:
		@echo  "\e[42m                   \e[0m"
		@echo  "\e[92mAll files compiled"
		@echo  "cub3D built"
		@echo  "Execute--> ./cub3D 'name'.cub"
		@echo  "\e[93mENJOY IT!!"
		@echo  "\e[42m                   \e[0m"

re:
	make fclean all
	@echo "All files has been deleted and recompiled"



.PHONY: clean fclean all re objects debug minilibx libft objects bonus

