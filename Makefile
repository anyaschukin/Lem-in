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

#     TEMPORARY MAKEFILE        #

all: remove lem-in

lem-in:
	make -C libft
	cp libft/libftprintf.a .
	gcc -g3 -Wall -Werror -Wextra *.c libftprintf.a -o lem-in -I includes -I libft/includes -I libft/libft

remove:
	rm -rf libftprintf.a lem-in

fclean:
	make -C libftprintf fclean
	rm -rf libftprintf.a lem-in

re:
	fclean all
