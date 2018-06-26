/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 14:17:40 by aschukin          #+#    #+#             */
/*   Updated: 2018/06/05 14:17:42 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdio.h>

void    lemin(t_lem_in *lem_in)
{
	parse_input(lem_in);
	loop_links(lem_in);
//	parse_stored(lem_in);
}

int     main(int argc, char **argv)
{
	t_lem_in *lem_in;

	lem_in = NULL;
	if (argc < 1)
		return (0);
	create_lem_in(&lem_in, argv);
	lemin(lem_in);
}


// simulating collision circumstances
/*
	key = generate_hash("room8", lem_in->room_count);
	lem_in->table[key]->ptr->name = ft_strdup("Dav");
	tmp = point_room(lem_in, "room8", lem_in->room_count);
	printf("name = %s\n y = %d\n", tmp->name, tmp->y);
*/