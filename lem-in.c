/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 14:17:40 by aschukin          #+#    #+#             */
/*   Updated: 2018/06/05 14:17:42 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void    lemin(t_lem_in *lem_in)
{
    parse_input(lem_in);
}

int     main(int argc, char **argv)
{
    t_lem_in *lem_in;

    lem_in = NULL;
    if (argc < 2)
        return (0);
    lem_in = create__lemin(lem_in, argv);
    lemin(lem_in);
}