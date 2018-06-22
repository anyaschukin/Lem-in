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

static t_link	*create_links(t_lem_in *lem_in)
{
	t_link *new;

    if (!(new = (t_link *)malloc(sizeof(t_link))))
        lem_in_error(lem_in);
    new->from_room = NULL;
	new->to_room = NULL;
	new->next = NULL;
	return(new);
}

void			add_links(t_lem_in *lem_in, t_link **new)
{
	t_link		*tmp;

	tmp = lem_in->link;
	if (!lem_in->link)
	{
		*new = create_links(lem_in);
		lem_in->link = *new;
	}
	else
	{
		if (!((*new) = (t_link *)malloc(sizeof(t_link))))
			lem_in_error(lem_in);
        while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = (*new);
	}
}
