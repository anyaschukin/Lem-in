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
#include <stdio.h>

/*
ant_c
rooms – put the rooms in a struct and parse for errors in another function
links – check the links btwn the rooms last
start-end
*/

static void is_ant(t_lem_in *lem_in)
{
	char    *str;
	int     j;

	str = lem_in->line;
	j = 0;
	while (*str) 
	{
		if (lem_in->ant_c)
			break ;
		if (*str && (*str == ' ' || *str == '-'))
			lem_in_error(lem_in);
		while (*(str + j) && (*(str + j) == '+' || ft_isdigit(*(str + j))))
			j++;
		lem_in->ant_c = ft_atol(str);
		if (str[j] != '\0' || lem_in->ant_c <= 0 || lem_in->ant_c > MAX_ANTS) // Yunus segfaults at 20,000 ants
			lem_in_error(lem_in);
	}
}

static void is_command_comment(t_lem_in *lem_in)
{
	int i;

	i = 0;
	if (ft_strcmp(lem_in->line, "##start") == 0)
		lem_in->start_c++;
	else if (ft_strcmp(lem_in->line, "##end") == 0)
		lem_in->end_c++;
	else if (lem_in->line[i] == '#' && (lem_in->start_c || lem_in->end_c) && 
		(ft_strcmp(lem_in->line, "##start") != 0) && (ft_strcmp(lem_in->line, "##end") != 0)) // comment following ##start/##end
		lem_in_error(lem_in);
	else if (lem_in->line[i] == '#' && (ft_strcmp(lem_in->line, "##start") != 0 
		&& (ft_strcmp(lem_in->line, "##end") != 0)))
		;
}

static void is_room(t_lem_in *lem_in)
{
	t_room	*room;
	char    *str;
	char	*str_start;

	str = lem_in->line;
	str_start = str;
	(str[0] == 'L' || str[0] == '#') ? lem_in_error(lem_in) : 0; // && ft_isprint(str)?
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
	room->name = strndup(str_start, str - str_start); // create ft_strndup
	lem_in->room_count++;
	(lem_in->start_c == 1 || lem_in->end_c == 1)? start_or_end_room(lem_in, room) : 0;
	(lem_in->start_c > 2 || lem_in->end_c > 2)? lem_in_error(lem_in) : 0;
	room->room_num = lem_in->room_count;
}

static void	is_link(t_lem_in *lem_in)
{
	t_link	*link;
	char	*str;
	char	*dash;

	str = lem_in->line;
	dash = ft_strchr(str, '-');
	add_links(lem_in, &link); //
	link->from_room = strndup(str, dash - str);
	link->to_room = ft_strdup((dash + 1));
	(!LINK_SELF && ft_strcmp(link->from_room, link->to_room) == 0) ? lem_in_error(lem_in) : 0;
}

void        parse_input(t_lem_in *lem_in)
{
	int i;

	i = 0;
	while (get_next_line(0, &lem_in->line) == 1)
	{
		if (ft_isdigit(lem_in->line[i]) && !lem_in->ant_c)
			is_ant(lem_in);
		else if (lem_in->line[i] == '#')
			is_command_comment(lem_in);
		else if (ft_strchr(lem_in->line, ' ') && !(ft_strchr(lem_in->line, '-')) && !(ft_strchr(lem_in->line, '#')))
		{
			!lem_in->ant_c ? lem_in_error(lem_in) : 0;
			is_room(lem_in);
		}
		else if (ft_strchr(lem_in->line, '-'))
		{
			(!lem_in->start || !lem_in->end) ? lem_in_error(lem_in) : 0;
			is_link(lem_in);
		}
		else
		{
			printf("cry cry babyyyyy\n");
			lem_in_error(lem_in);
		} 
		lem_in->line_count++;
	}
	create_hashtable(lem_in);
}

