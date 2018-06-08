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
    long    test_int_size;

    str = lem_in->line;
    j = 0;
    while (str)
    {
    //    while (j != 0 && *str && *str == ' ')
    //        str++;
        while (*(str + j) && (*(str + j) == '-' || *(str + j) == '+' || ft_isdigit(*(str + j))))
            j++;
        if (!*str)
            break;
        test_int_size = atoi_thingy;
        if (test_int_size > 2147483647 || test_int_size < -2147483648)
            lem_in_error(lem_in);
        str += j;
    }
}

static void is_command_comment(t_lem_in *lem_in)
{
    int i;

    i = 0;
    if (strcmp(lem_in->line, "##start"))
        lem_in->end_c = 1;
    else if (strcmp(lem_in->line, "##end"))
        lem_in->start_c = 1;
    else if (lem_in->line[i] == '#' && (lem_in->start_c || lem_in->end_c) && 
        !(strcmp(lem_in->line, "##start") && !(strcmp(lem_in->line, "##end"))))
        lem_in_error(lem_in);
    else if (lem_in->line[i] == '#' && !(strcmp(lem_in->line, "##start") 
        && !(strcmp(lem_in->line, "##end"))))
        break ;
}

static void is_room(t_lem_in *lem_in)
{
    char    *str;

    str = lem_in->line;
        
}

void        parse_input(t_lem_in *lem_in)
{
    int i;

    i = 0;
    lem_in->line = lem_in->argv[i];
    while (get_next_line(0, &lem_in->line) == 1) // 1 or 0?
    {
        if (ft_isdigit(lem_in->line[0])) // put if (is_ant), since ants won't necessarily be on line[0]
            is_ant(lem_in);
        if (lem_in->line[i] == '#')
            is_command_comment(lem_in);
        else if (lem_in->room) // string + 2 spaces + 2 coordinates
        {
            if (!lem_in->ants)
                lem_in_error(lem_in);
            is_room(lem_in);
        }
        else if (link)
        {
            if (!lem_in->start_c || !lem_in->end_c || !lem_in->start || !lem_in->end)
                lem_in_error(lem_in);
            is_link();
        }
    }
}

