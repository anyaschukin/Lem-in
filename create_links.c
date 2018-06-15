/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_links.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 16:19:40 by aschukin          #+#    #+#             */
/*   Updated: 2018/06/12 16:19:42 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void    create_links(t_lem_in *lem_in, t_link **link)
{
    if (!((*link) = (t_link *)malloc(sizeof(t_link))))
        lem_in_error(lem_in); // lem_in_error
    (*link)->from_room = 0;
	(*link)->to_room = 0;
}
