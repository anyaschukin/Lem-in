/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 15:29:19 by aschukin          #+#    #+#             */
/*   Updated: 2018/06/30 14:01:13 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	free_ants(t_ants *ant)
{
	t_ants			*tmp;
	t_ants			*delete;

	if (ant)
	{
		tmp = ant;
		while (tmp->next != NULL)
		{
			delete = tmp;
			tmp = tmp->next;
			free(delete);
		}
		free(tmp);
	}
}

static void	free_connections(t_connection *connect)
{
	t_connection	*tmp;
	t_connection	*delete;

	if (connect)
	{
		tmp = connect;
		while (tmp->next != NULL)
		{
			delete = tmp;
			tmp = tmp->next;
			free(delete);
		}
		free(tmp);
	}
}

static void	free_rooms(t_room *room)
{
	t_room			*tmp;
	t_room			*delete;

	if (room)
	{
		tmp = room;
		while (tmp->next != NULL)
		{
			delete = tmp;
			tmp = tmp->next;
			free(delete->name);
			delete->connect ? free_connections(delete->connect) : 0;
			free(delete);
		}
		free(tmp->name);
		free_connections(tmp->connect);
		free(tmp);
	}
}

static void	free_links(t_link *link)
{
	t_link			*tmp;
	t_link			*delete;

	if (link)
	{
		tmp = link;
		while (tmp->next != NULL)
		{
			delete = tmp;
			tmp = tmp->next;
			free(delete->from_room);
			free(delete->to_room);
			free(delete);
		}
		free(tmp->from_room);
		free(tmp->to_room);
		free(tmp);
	}
}

void		lem_in_free(t_lem_in *lem_in)
{
	unsigned int	i;

	i = 0;
	if (lem_in)
	{
		free(lem_in->line);
		free(lem_in->str);
		if (lem_in->room)
			free_rooms(lem_in->room);
		if (lem_in->link)
			free_links(lem_in->link);
		if (lem_in->table)
		{
			while (i < lem_in->room_count * 1000)
				free(lem_in->table[i++]);
		}
		free(lem_in->table);
		free_ants(lem_in->ants);
		free(lem_in);
	}
}
