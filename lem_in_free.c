/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 15:29:19 by aschukin          #+#    #+#             */
/*   Updated: 2018/06/05 15:29:21 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdio.h>

//static void free_connections(t_connection *connect)

static void free_rooms(t_room *room)
{
    t_room  *tmp;
    t_room  *delete;

    if (room)
    {
        tmp = room->next;
        while (tmp->next != NULL)
        {
            delete = tmp;
            tmp = tmp->next;
            free(delete);
        }
        free(tmp); // do I need to free collision? connect?
    }
}

static void free_links(t_link *link)
{
    t_link  *tmp;
    t_link  *delete;

    if (link)
    {
        tmp = link->next;
        while (tmp->next != NULL)
        {
            delete = tmp;
            tmp = tmp->next;
            free(delete);
        }
        free(tmp);
    }
}

static void free_hashtable(t_lem_in *lem_in)
{
    t_room          *tmp;
    unsigned int    hash;

    if (lem_in->table)
    {
        tmp = lem_in->room;
        while (lem_in->table)
        {
            hash = generate_hash(tmp->name, tmp->room_num);
            free(lem_in->table[hash]);
            tmp = tmp->next;
        }
        free(lem_in->table);
    }
}

void lem_in_free(t_lem_in *lem_in)
{
    if (lem_in)
    {
        if (lem_in->line)
            free(lem_in->line);
        if (lem_in->str)
            free(lem_in->str);
        if (lem_in->start)
            free(lem_in->start);
        if (lem_in->end)
            free(lem_in->end);
        if (lem_in->room)
            free_rooms(lem_in->room);
        if (lem_in->link)
            free_links(lem_in->link);
        if (lem_in->table)
            free_hashtable(lem_in);
        free(lem_in);
    }
}