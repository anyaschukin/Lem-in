# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aschukin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/08 10:56:19 by aschukin          #+#    #+#              #
#    Updated: 2018/06/22 14:57:53 by aschukin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LEM_IN =		lem_in
NAME =			$(LEM_IN)
LIBFT_A =		libftprintf.a

COMP =			gcc -Wall -Werror -Wextra -I includes -I libft/includes -I libft/libft -c -o

OBJ_DIR =		obj/
SRC_DIR =		srcs/
LIBFT =			libft/

SRC =			add_ants.c \
				add_links.c \
				add_rooms.c \
				create_hashtable.c \
				create_lem_in.c \
				do_connections.c \
				lem_in.c \
				lem_in_error.c \
				lem_in_free.c \
				move_ants.c \
				parse_input.c \
				solve.c

OBJ =			$(SRC:%.c=%.o)

SRC_PATH =   	$(SRC:%=$(SRC_DIR)%)
OBJ_PATH =		$(addprefix $(OBJ_DIR), $(OBJ))

all:			color do_libft $(OBJ_DIR) $(NAME)
				@echo "\\n\033[32;1m LEM-IN COMPLETE \033[0m \\n"

$(OBJ_DIR):
				@mkdir -p $(OBJ_DIR)
				@echo Create: Object directory

$(NAME):		$(OBJ_PATH)
				@gcc $(OBJ_PATH) *.a -o lem-in \
					-I includes -I libft/includes

$(OBJ_PATH):	$(SRC_PATH)
				@$(MAKE) $(OBJ)

$(OBJ):			$(LIBFT_A)
				@echo Create: $(@:obj/%=%)"\x1b[1A\x1b[M"
				@$(COMP) $(OBJ_DIR)$@ $(SRC_DIR)$(@:%.o=%.c)

do_libft:
				@make -C $(LIBFT)
				@cp $(LIBFT)/$(LIBFT_A) .

color:
				@echo "\x1b[36m""\x1b[1A\x1b[M"

clean:			color
				@/bin/rm -rf $(OBJ_DIR) $(LIBFT_A)
				@make -C $(LIBFT) clean
				@echo "\\n\033[32;1m Cleaned libft \033[0m"

fclean:			clean
				@/bin/rm -f $(LEM_IN) $(LIBFT_A)
				@make -C $(LIBFT) fclean
				@echo "\033[32;1m Cleaned $(NAME) \033[0m \\n"

re: 			fclean all

.PHONY:			all clean flcean re color