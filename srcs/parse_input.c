/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 13:34:20 by aschukin          #+#    #+#             */
/*   Updated: 2018/06/05 13:34:21 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "ft_printf.h"

static void	is_ant(t_lem_in *lem_in)
{
	char	*str;
	int		j;

	str = lem_in->line;
	j = 0;
	while (*str)
	{
		if (lem_in->ant_c)
			break ;
		if (*str && (*str == ' '))
			lem_in_error(lem_in, 5);
		if (*str && (*str == '-'))
			lem_in_error(lem_in, 3);
		while (*(str + j) && (*(str + j) == '+' || ft_isdigit(*(str + j))))
			j++;
		lem_in->ant_c = ft_atol(str);
		if (str[j] != '\0' || lem_in->ant_c <= 0 || lem_in->ant_c > MAX_ANTS)
			lem_in_error(lem_in, 3);
	}
}

static void	is_command_comment(t_lem_in *lem_in)
{
	int i;

	i = 0;
	if ((lem_in->start_c || lem_in->end_c) && !lem_in->ant_c)
		lem_in_error(lem_in, 3);
	if (ft_strcmp(lem_in->line, "##start") == 0)
		lem_in->start_c++;
	else if (ft_strcmp(lem_in->line, "##end") == 0)
		lem_in->end_c++;
	else if (lem_in->line[i] == '#' && (lem_in->start_c || lem_in->end_c)
	&& (ft_strcmp(lem_in->line, "##start") != 0)
	&& (ft_strcmp(lem_in->line, "##end") != 0)
	&& !COMMENTS)
		lem_in_error(lem_in, 4);
	else if (lem_in->line[i] == '#' && (ft_strcmp(lem_in->line, "##start") != 0
		&& (ft_strcmp(lem_in->line, "##end") != 0)))
		;
}

static void	is_room(t_lem_in *lem_in)
{
	t_room	*room;
	char	*str;
	char	*str_start;

	str = lem_in->line;
	str_start = str;
	(str[0] == 'L' || str[0] == '#') ? lem_in_error(lem_in, 6) : 0;
	add_rooms(lem_in, &room);
	while (*str != '\0')
		str++;
	str--;
	while (ft_isdigit(*str))
		str--;
	room->y = ft_atoi(str);
	str--;
	while (ft_isdigit(*str))
		str--;
	room->x = ft_atoi(str);
	room->name = ft_strndup(str_start, str - str_start);
	(!NAME_SPACE && ft_strchr(room->name, ' ')) ? lem_in_error(lem_in, 15) : 0;
	lem_in->room_count++;
	if (lem_in->start_c == 1 || lem_in->end_c == 1)
		start_or_end_room(lem_in, room);
	(lem_in->start_c > 2 || lem_in->end_c > 2) ? lem_in_error(lem_in, 7) : 0;
	room->room_num = lem_in->room_count;
}

static void	is_link(t_lem_in *lem_in)
{
	t_link	*link;
	char	*str;
	char	*dash;

	(lem_in->room_count == 0) ? lem_in_error(lem_in, 11) : 0;
	(!lem_in->start || !lem_in->end) ? lem_in_error(lem_in, 8) : 0;
	(lem_in->start == lem_in->end) ? lem_in_error(lem_in, 9) : 0;
	str = lem_in->line;
	dash = ft_strchr(str, '-');
	add_links(lem_in, &link);
	link->from_room = ft_strndup(str, dash - str);
	link->to_room = ft_strdup((dash + 1));
	if (!LINK_SELF && ft_strcmp(link->from_room, link->to_room) == 0)
		lem_in_error(lem_in, 10);
}

void		parse_input(t_lem_in *lem_in)
{
	print_options(lem_in);
	while (get_next_line(0, &lem_in->line) == 1)
	{
		if ((ft_isdigit(lem_in->line[0]) || ft_isdigit(lem_in->line[1]))
		&& !lem_in->ant_c)
			is_ant(lem_in);
		else if (lem_in->line[0] == '#')
			is_command_comment(lem_in);
		else if (ft_strchr(lem_in->line, ' ') && !(ft_strchr(lem_in->line, '-'))
		&& !(ft_strchr(lem_in->line, '#')))
			is_room(lem_in);
		else if (ft_strchr(lem_in->line, '-'))
			is_link(lem_in);
		else
			lem_in_error(lem_in, 0);
		if (!lem_in->flag_p && !lem_in->flag_r)
			ft_printf("%s\n", lem_in->line);
		free(lem_in->line);
		lem_in->line = NULL;
	}
	(!lem_in->flag_p && !lem_in->flag_r) ? ft_printf("\n") : 0;
	lem_in->link == NULL ? lem_in_error(lem_in, 12) : 0;
	create_hashtable(lem_in);
}
