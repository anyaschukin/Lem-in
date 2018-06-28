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

static void     find_path(t_lem_in *lem_in, t_room **array)
{
    t_room          **tmp;
    t_connection    *route;

    tmp = array;
    while (*tmp)
    {
        route = (*tmp)->connect;
        while (route)
        {
            if (route->to == lem_in->reverse_path && route->to != *tmp)
            {
                (*tmp)->path_next = lem_in->reverse_path;
                lem_in->reverse_path->path_prev = *tmp;
                lem_in->reverse_path = *tmp;
            }
            route = route->next;  
        }
        tmp++;
    }
}

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
    if (!(new = (t_room **)malloc(sizeof(t_room*) * (rooms + 1))))
        return (NULL);
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
    new[i] = NULL;
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
            {	
                (*tmp)->path_next = lem_in->end;
                lem_in->end->path_prev = *tmp;
                lem_in->reverse_path = *tmp;
                return (1);
            }
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
    find_path(lem_in, array);
    return (1);
}

/*
** Mallocs for an array of rooms
** (as each room has its own linked list of connecting rooms)
** (because we need to pass a first array to the recursive_check)
*/

void    solve(t_lem_in *lem_in)
{
    t_room          **array;

    if (!(array = (t_room **)malloc(sizeof(t_room*) * 2)))
        lem_in_error(lem_in);
    array[0] = lem_in->start;
    array[1] = NULL;
    !(recursive_check(lem_in, array)) ? lem_in_error(lem_in) : 0;
//    while (lem_in->start)
  //  {
    //    printf("%s\n", lem_in->start->name);
      //  lem_in->start = lem_in->start->path_next;
    //}
    free(array);
}

// -p flag for printing the path