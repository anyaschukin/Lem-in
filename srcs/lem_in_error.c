/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 15:27:15 by aschukin          #+#    #+#             */
/*   Updated: 2018/07/10 19:54:14 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		error_messages(int error)
{
	error == 1 ? write(1, "Error: malloc failure\n", 22) : 0;
	error == 2 ? write(1, "Error: ' ' or '-' before ants\n", 30) : 0;
	error == 3 ? write(1, "Error: negative, too many, or no ants\n", 38) : 0;
	error == 4 ? write(1, "Error: comment after ##start or ##end\n", 38) : 0;
	error == 5 ? write(1, "Error: ants badly formatted\n", 28) : 0;
	error == 6 ? write(1, "Error: room starts with 'L' or '#'\n", 35) : 0;
	error == 7 ? write(1, "Error: more than 1 start or end room\n", 37) : 0;
	error == 8 ? write(1, "Error: no start or end\n", 23) : 0;
	error == 9 ? write(1, "Error: start room = end room\n", 30) : 0;
	error == 10 ? write(1, "Error: room links to self\n", 27) : 0;
	error == 11 ? write(1, "Error: no rooms\n", 17) : 0;
	error == 12 ? write(1, "Error: no links or empty map\n", 29) : 0;
	error == 13 ? write(1, "Error: no path\n", 15) : 0;
	error == 14 ? write(1, "Error: link to unknown room\n", 28) : 0;
	error == 15 ? write(1, "Error: more than 3 coordinates\n", 31) : 0;
	error == 16 ? write(1, "Error: duplicate rooms\n", 23) : 0;
	error == 18 ? write(1, "Error: too many arguments\n", 26) : 0;
}

void			lem_in_error(t_lem_in *lem_in, int error)
{
	if (error > 0)
		error_messages(error);
	else
		write(1, "Error\n", 6);
	lem_in_free(lem_in);
	exit(-1);
}
