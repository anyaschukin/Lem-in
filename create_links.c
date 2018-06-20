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
	new->from = 0;
	new->to = 0;
	new->next = NULL;
	return(new);
}

void			add_links(t_lem_in *lem_in, t_link **new)
{
	t_link		*old;

	old = lem_in->link;
	if (!lem_in->link)
		lem_in->link = create_links(lem_in);
	else
	{
		if (!((*new) = (t_link *)malloc(sizeof(t_link))))
			lem_in_error(lem_in);
        (*new)->from_room = 0;
	    (*new)->to_room = 0;
	    (*new)->next = NULL;
		while (old->next != NULL)
			old = old->next;
		old->next = (*new);
		(*new)->next = NULL;
	}
}

/*
void    create_links(t_lem_in *lem_in, t_link **link)
{
    if (!((*link) = (t_link *)malloc(sizeof(t_link))))
        lem_in_error(lem_in); // lem_in_error
    (*link)->from_room = 0;
	(*link)->to_room = 0;
}*/