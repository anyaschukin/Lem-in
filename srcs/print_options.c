/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_options.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 22:19:38 by aschukin          #+#    #+#             */
/*   Updated: 2018/07/10 22:19:40 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "ft_printf.h"

void	print_path(t_lem_in *lem_in)
{
	t_room	*tmp;

	tmp = lem_in->end;
	while (tmp && tmp->path_prev && tmp->path_prev != lem_in->start)
	{
		tmp->path_prev->path_next = tmp;
		tmp = tmp->path_prev;
	}
	tmp = lem_in->start;
	if (lem_in->flag_p)
	{
		ft_printf("Path:\n");
		while (tmp && tmp != lem_in->end)
		{
			ft_printf("%s -> ", tmp->name);
			tmp = tmp->path_next;
		}
		ft_printf("%s\n", lem_in->end->name);
	}
}

void	print_rooms(t_lem_in *lem_in)
{
	t_room	*tmp;

	tmp = lem_in->room;
	if (lem_in->flag_r)
	{
		ft_printf("Rooms:\n");
		while (tmp)
		{
			ft_printf("%s\n", tmp->name);
			tmp = tmp->next;
		}
	}
}

void	print_options(t_lem_in *lem_in)
{
	int		count;

	count = 0;
	while (*lem_in->argv)
	{
		if (!ft_strcmp(*lem_in->argv, "-p"))
			lem_in->flag_p = 1;
		if (!ft_strcmp(*lem_in->argv, "-r"))
			lem_in->flag_r = 1;
		lem_in->argv++;
		count++;
	}
	if (!lem_in->flag_p && !lem_in->flag_r && count > 1)
		lem_in_error(lem_in, 18);
	if ((lem_in->flag_p || lem_in->flag_r) && count > 2)
		lem_in_error(lem_in, 18);
}
