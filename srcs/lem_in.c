/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 14:17:40 by aschukin          #+#    #+#             */
/*   Updated: 2018/06/30 13:56:25 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	lemin(t_lem_in *lem_in)
{
	parse_input(lem_in);
	do_connections(lem_in);
	solve(lem_in);
	add_ants(lem_in);
	move_ants(lem_in);
}

int		main(int argc, char **argv)
{
	t_lem_in *lem_in;

	lem_in = NULL;
	if (argc < 1)
		return (0);
	create_lem_in(&lem_in, argv);
	lemin(lem_in);
	lem_in_free(lem_in);
}
