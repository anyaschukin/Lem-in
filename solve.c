/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 13:47:19 by aschukin          #+#    #+#             */
/*   Updated: 2018/06/26 13:47:21 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdio.h>

/*
** Takes an array of linked lists (of connections btwn rooms)
** Looks at each list, until that list is at t_room *end
** Goes to the next array element, and goes through that list
** until the array is null.
*/

static t_room   **create_mad_array(t_room **array, int rooms)
{
    t_room          **tmp;
    t_room          **new;
    t_connection    *route;
    int             i;

    i = 0;
    if (!(new = (t_room **)malloc(sizeof(t_room*) * rooms + 1)))
        return (NULL);
    ft_bzero(new, rooms + 1);
    tmp = array;
    while (*tmp) // populates the fresh array with the next layer of connecting rooms
    {
        route = (*tmp)->connect;
        while (route)
        {
            if (!route->to->occupied)
                new[i++] = route->to;
            route = route->next;
        }
        tmp++;
    }
    return (new);
}

static int    recursive_check(t_lem_in *lem_in, t_room **array)
{
    t_room          **tmp;
    t_room          **new;
    t_connection    *route;
    int             rooms;

    tmp = array;
    rooms = 0;
    while (*tmp) // looks at all the connecting rooms for t_room *end
    {
        (*tmp)->occupied = 1;
        route = (*tmp)->connect;
        while (route) // looks at each connection in the list until it finds t_room *end
        {
            rooms++; // this will be equal to the # connections all the rooms had at that level
            if (route->to == lem_in->end)
                return (1);
            route = route->next;  
        }
        tmp++;
    }
    if (!rooms)
        return (0);
    if (!(new = (create_mad_array(array, rooms))))
        return (0);
    if (!(recursive_check(lem_in, new)))
        return (0);
    return (0);
}

/*
** Mallocs for an array of rooms
** (as each room has its own linked list of connecting rooms)
** (because we need to pass an array to the recursive_check)
*/

void    solve(t_lem_in *lem_in)
{
    t_room          **array;

    if (!(array = (t_room **)malloc(sizeof(t_room*) * 2)))
        lem_in_error(lem_in);
    array[0] = lem_in->start;
    array[1] = NULL;
    !(recursive_check(lem_in, array) ? lem_in_error(lem_in) : 0;
    free(array);
}