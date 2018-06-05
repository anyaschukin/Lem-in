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

static void free_lem_in(t_lem_in *lem_in)
{
    if (lem_in)
    {
        if (line)
            free(line);
        if (str)
            free(str);
        if (start)
            free (start);
        if (end)
            free (end);
        if (room) // create a separate function to free this linked list?
            free (room);
        free (lem_in);
    }
}

void lem_in_free(t_lem_in *lem_in)
{
    free_lem_in(lem_in);
}
