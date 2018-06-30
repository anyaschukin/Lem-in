/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_ants.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 13:49:36 by aschukin          #+#    #+#             */
/*   Updated: 2018/06/30 13:49:38 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_ants	*create_ants(t_lem_in *lem_in)
{
	t_ants		*new;

	if (!(new = (t_ants *)malloc(sizeof(t_ants))))
		lem_in_error(lem_in);
	ft_bzero(new, sizeof(t_ants));
	return (new);
}

void			add_ants(t_lem_in *lem_in)
{
	t_ants		*tmp;
	long		i;

	i = 1;
	while (lem_in->ant_c--)
	{
		tmp = create_ants(lem_in);
		tmp->ant_n = lem_in->ant_c + 1;
		tmp->next = lem_in->ants;
		lem_in->ants = tmp;
	}
	lem_in->start->ant_here = lem_in->ants;
}
