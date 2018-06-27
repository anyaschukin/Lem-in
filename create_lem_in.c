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
    ft_bzero(*lem_in, sizeof(t_lem_in));
    (*lem_in)->argv = argv;
}
