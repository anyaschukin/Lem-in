/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_room.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 10:35:57 by aschukin          #+#    #+#             */
/*   Updated: 2018/06/26 10:35:59 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdio.h>

static t_connection	*create_connections(t_lem_in *lem_in)
{
	t_connection *new;

    if (!(new = (t_connection *)malloc(sizeof(t_connection))))
        lem_in_error(lem_in);
    ft_bzero(new, sizeof(t_connection));
	return(new);
}

static void     assign_connections(t_lem_in *lem_in, t_room *from, t_room *to)
{
    t_connection    *conn;

    conn = create_connections(lem_in);
    conn->to = to;
    if (!(from->connect))
        from->connect = conn;
    else
    {
        conn->next = from->connect;
        from->connect = conn;
    }
    conn = create_connections(lem_in);
    conn->to = from;
    if (!(to->connect))
        to->connect = conn;
    else
    {
        conn->next = to->connect;
        to->connect = conn;
    }
}

t_room              *point_room(t_lem_in *lem_in, char *str)
{
    t_room          *point;
    unsigned int    key;
    
    key = generate_hash(str, lem_in->room_count);
    point = lem_in->table[key]->ptr;
    while (point && ft_strcmp(str, point->name))
        point = point->collision;
    return (point);
}

void			    do_connections(t_lem_in *lem_in)
{
	t_link	        *tmp;
	t_room	        *from;
    t_room	        *to;

	tmp = lem_in->link;
	while (tmp != NULL)
	{
		from = point_room(lem_in, tmp->from_room);
		to = point_room(lem_in, tmp->to_room);
        assign_connections(lem_in, from, to);
		tmp = tmp->next;
	}
}