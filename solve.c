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

/*
** Takes an array of linked lists (of connections btwn rooms)
** Looks at each list, until that list is at the end
** Goes to the next array element, and goes through that list
** until the array is null.
*/

void    create_mad_array(t_lem_in *lem_in, t_connection **array, int size)
{

}

void    recursive_check(t_lem_in *lem_in, t_connection **array)
{
    t_connection    **tmp_ptr;
    int             rooms_in_list;

    tmp_ptr = array;
    rooms_in_list = 0;
    while (tmp_ptr) // looks at the next list in the array
    {
        while (*tmp_ptr->to) // looks at the list until it finds t_room *end
        {
            rooms_in_list++;
            if (*tmp_ptr->to == lem_in->end)
                return ;
            *tmp_ptr->to = *tmp_ptr->to->next;
        }
        tmp_ptr++;
        
    }
}

/*
** Mallocs for an array of connections
** As each room has its own linked list of connections
*/

void    solve(t_lem_in *lem_in)
{
    t_room          *start;
    t_connection    **array;

    if (!(array = (**t_connection)malloc(sizeof(*t_connection) * 2)))
        lem_in_error(lem_in);
    array[0] = start;
    array[1] = NULL;
    recursive_check(lem_in, array);
    free(array);
}