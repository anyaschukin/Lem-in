/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_rooms.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 13:48:28 by aschukin          #+#    #+#             */
/*   Updated: 2018/06/30 13:49:07 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			start_or_end_room(t_lem_in *lem_in, t_room *room)
{
	if (lem_in->start_c == 1)
	{
		lem_in->start = room;
		lem_in->start_c++;
	}
	if (lem_in->end_c == 1)
	{
		lem_in->end = room;
		lem_in->end_c++;
	}
}

static t_room	*create_rooms(t_lem_in *lem_in)
{
	t_room		*new;

	if (!(new = (t_room *)malloc(sizeof(t_room))))
		lem_in_error(lem_in);
	ft_bzero(new, sizeof(t_room));
	return (new);
}

void			add_rooms(t_lem_in *lem_in, t_room **new)
{
	t_room		*tmp;

	tmp = lem_in->room;
	if (!lem_in->room)
	{
		*new = create_rooms(lem_in);
		lem_in->room = *new;
	}
	else
	{
		if (!((*new) = create_rooms(lem_in)))
			lem_in_error(lem_in);
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = (*new);
	}
}
