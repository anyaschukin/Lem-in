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
        if (lem_in->line)
            free(lem_in->line);
        if (lem_in->str)
            free(lem_in->str);
        if (lem_in->start)
            free (lem_in->start);
        if (lem_in->end)
            free (lem_in->end);
        if (lem_in->room) // create a separate function to free this linked list?
            free (lem_in->room);
        free (lem_in);
    }
}

void lem_in_free(t_lem_in *lem_in)
{
    free_lem_in(lem_in);
}
