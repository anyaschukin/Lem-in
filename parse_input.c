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
ants
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
		if (*str && (*str == ' ' || *str == '-')) // spaces before ants are counted as error
			lem_in_error(lem_in);
		while (*(str + j) && (*(str + j) == '+' || ft_isdigit(*(str + j))))
			j++;
		lem_in->ants = ft_atol(str);
		if (*str != '\0' || lem_in->ants <= 0 || lem_in->ants > 2147483647) // Yunus segfaults at 20,000 ants
			lem_in_error(lem_in);
	}
	printf("%ld\n", lem_in->ants);
}

static void is_command_comment(t_lem_in *lem_in)
{
	int i;

	i = 0;
	if (ft_strcmp(lem_in->line, "##start"))
		lem_in->start_c++;
	else if (ft_strcmp(lem_in->line, "##end"))
		lem_in->end_c++;
	else if (lem_in->line[i] == '#' && (lem_in->start_c || lem_in->end_c) && 
		!(ft_strcmp(lem_in->line, "##start") && !(ft_strcmp(lem_in->line, "##end")))) // comment following ##start/##end
		lem_in_error(lem_in);
	else if (lem_in->line[i] == '#' && !(ft_strcmp(lem_in->line, "##start") 
		&& !(ft_strcmp(lem_in->line, "##end"))))
		;
	(lem_in->start_c > 1 || lem_in->end_c > 1) ? lem_in_error(lem_in) : 0;
}

static void is_room(t_lem_in *lem_in)
{
	char    *str;
	int		i;

	str = lem_in->line;
	i = 0;
	if (str[i] == 'L' || str[i] == '#')
		lem_in_error(lem_in);
	while (str[i] != '\0')
		i++;
	while (ft_isdigit(str[i]))
		i--;
	

	// work backwards from here (while(isidigit) then ' ' then while(isdigit) then ' ' then everything after is room) 
//	else
//		create_rooms(lem_in);
	printf("is_room is unfinished\n");
	lem_in->room_count++;
}

static void	is_link(t_lem_in *lem_in)
{
	printf("this is not a link\n");
	lem_in->room_count++;
}

void        parse_input(t_lem_in *lem_in)
{
	int i;

	i = 0;
	lem_in->line = lem_in->argv[1];
	while (get_next_line(0, &lem_in->line) != 0)
	{
		if (ft_isdigit(lem_in->line[i]) && !lem_in->ants)
			is_ant(lem_in);
		else if (lem_in->line[i] == '#')
			is_command_comment(lem_in);
		else if (ft_strchr(lem_in->line, ' ') && !(ft_strchr(lem_in->line, '-')) && ft_strchr(lem_in->line, '#'))
		{
			!lem_in->ants ?	lem_in_error(lem_in) : 0;
			is_room(lem_in);
		}
		else if (ft_strchr(lem_in->line, '-'))
		{
			(!lem_in->start || !lem_in->end) ? lem_in_error(lem_in) : 0;
			is_link(lem_in);
		}
		else
			lem_in_error(lem_in);
	}
}

