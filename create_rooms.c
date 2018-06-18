/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_rooms.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 16:19:09 by aschukin          #+#    #+#             */
/*   Updated: 2018/06/12 16:19:13 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdio.h>

// in this function:
// malloc + initialize rooms/start/end
// parse rooms for double-rooms (2 rooms with same name) ?

static t_room	*create_rooms(t_lem_in *lem_in, t_room **room)
{
    if (!((*room) = (t_room *)malloc(sizeof(t_room))))
        lem_in_error(lem_in);
    (*room)->name = NULL;
	(*room)->room_num = 0;
	(*room)->x = 0;
	(*room)->y = 0;
	(*room)->next = NULL;
	return(*room);
}

void			add_rooms(t_lem_in *lem_in)
{
	t_room		*new;
	t_room		*old;

	if (!lem_in->room)
		lem_in->room = create_rooms(lem_in, &new);
	else
	{
		if (!(new = (t_room *)malloc(sizeof(t_room))))
			lem_in_error(lem_in);
		new->name = NULL;
		new->room_num = 0;
		new->x = 0;
		new->y = 0;
		old = lem_in->room;
		while (old->next != NULL)
			old = old->next;
		old->next = new;
		new->next = NULL;
	}
}



// room_info ?
// link_rooms ?

/*
void	parse_rooms(t_lem_in *lem_in, t_room **room)
{
	t_room *start;
	t_room *end;
	t_room *room;
	char	*room_type;

	if (room_type == start || room_type == end)
		room_type == (start) ? start : end;
	else 
		room_type = room;
	if (lem_in->start_c)
		create_rooms(lem_in, room_type);

}
*/
