/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 11:01:49 by aschukin          #+#    #+#             */
/*   Updated: 2018/07/11 14:40:00 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "ft_printf.h"

void			free_map(t_map *map)
{
	t_map	*tmp;
	t_map	*delete;

	if (map)
	{
		tmp = map;
		while (tmp->next != NULL)
		{
			delete = tmp;
			tmp = tmp->next;
			free(delete->line);
			free(delete);
		}
		free(tmp->line);
		free(tmp);
	}
}

void			print_map(t_lem_in *lem_in)
{
	t_map	*tmp;

	tmp = lem_in->map;
	while (tmp)
	{
		ft_printf("%s\n", tmp->line);
		tmp = tmp->next;
	}
	write(1, "\n", 1);
}

static t_map	*new_map(t_lem_in *lem_in)
{
	t_map	*tmp;

	if (!(tmp = (t_map *)malloc(sizeof(t_map))))
		lem_in_error(lem_in, 1);
	ft_bzero(tmp, sizeof(t_map));
	return (tmp);
}

void			add_map(t_lem_in *lem_in, t_map **map)
{
	t_map	*tmp;

	tmp = lem_in->map;
	if (!lem_in->map)
	{
		*map = new_map(lem_in);
		lem_in->map = *map;
		if (!(lem_in->map->line = ft_strdup(lem_in->line)))
			lem_in_error(lem_in, 1);
		lem_in->map->line_num = 1;
	}
	else
	{
		if (!((*map) = new_map(lem_in)))
			lem_in_error(lem_in, 1);
		if (!((*map)->line = ft_strdup(lem_in->line)))
			lem_in_error(lem_in, 1);
		(*map)->line_num = tmp->line_num++;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = (*map);
	}
}
