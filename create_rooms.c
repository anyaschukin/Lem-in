/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 13:34:20 by aschukin          #+#    #+#             */
/*   Updated: 2018/06/05 13:34:21 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdio.h>

void    create_rooms(t_lem_in *lem_in, t_room **room)
{
    if (!((*room) = (t_room *)malloc(sizeof(t_room))))
        lem_in_error(lem_in); // lem_in_error
    (*room)->name = NULL;
	(*room)->room_num = 0;
	(*room)->x = 0;
	(*room)->y = 0;
	(*room)->next = NULL;
}

/*
void	create_rooms(t_lem_in *lem_in, t_room **room)
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
