/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_lem_in.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 14:33:26 by aschukin          #+#    #+#             */
/*   Updated: 2018/06/05 14:33:27 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void    create_lem_in(t_lem_in **lem_in, char **argv)
{
    if (!((*lem_in) = (t_lem_in *)malloc(sizeof(t_lem_in))))
        exit(1);
    (*lem_in)->argv = argv;   // since it **lem_in is passed at a 2 star pointer
    (*lem_in)->line = NULL;     // need to dereference it using 1 star, hence (*lem_in)
    (*lem_in)->str = NULL;    // otherwise, plain lem_in->line dereferences line
    (*lem_in)->line_count = 0;
    (*lem_in)->ants = 0;
    (*lem_in)->start_c = 0;
    (*lem_in)->end_c = 0;
    (*lem_in)->room_count = 0;
    (*lem_in)->start = NULL;
    (*lem_in)->end = NULL;
    (*lem_in)->room = NULL;
}
