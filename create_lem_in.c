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

void    create_lem_in(lem_in, **argv)
{
    if (!(lem_in = (t_lem_in *)malloc(sizeof(t_lem_in)))
        exit(1);
    lem_in->argv = argv;
    lem_in->line = NULL;
    lem_in->str = NULL;
    lem_in->ants = 0;
    lem_in->start = NULL;
    lem_in->end = NULL;
    lem_in->room = NULL;
}
