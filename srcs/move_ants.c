/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 12:01:26 by aschukin          #+#    #+#             */
/*   Updated: 2018/06/30 14:02:04 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "ft_printf.h"

void	move_ants(t_lem_in *lem_in)
{
	t_room	*tmp;

	while (1 && !lem_in->flag_p && !lem_in->flag_r)
	{
		tmp = lem_in->end;
		if (tmp->ant_here != NULL && tmp->ant_here->next == NULL)
			return ;
		while (tmp)
		{
			if (tmp->path_prev && tmp->path_prev->ant_here && !tmp->ant_here)
			{
				tmp->ant_here = tmp->path_prev->ant_here;
				ft_printf("L%ld-%s ", tmp->ant_here->ant_n, tmp->name);
			}
			else if (tmp->ant_here)
			{
				tmp->ant_here = tmp->ant_here->next;
				if (tmp != lem_in->start && tmp->ant_here)
					ft_printf("L%ld-%s ", tmp->ant_here->ant_n, tmp->name);
			}
			tmp = tmp->path_prev;
		}
		ft_printf("\n");
	}
}
