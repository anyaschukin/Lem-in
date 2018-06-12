/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 14:44:43 by aschukin          #+#    #+#             */
/*   Updated: 2018/06/04 14:44:45 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "libft.h"

typedef struct  s_lem_in
{
	char            **argv;
	char            *line;
	char            *str;

	int				line_count;

	long            ants;
	int             start_c;
	int             end_c;
	int				room_count;

	struct t_room  *start;
	struct t_room  *end;
	struct t_room  *room;

}               t_lem_in;

typedef struct  s_hashtable
{
	int             size;
	int             count;
	char            **rooms;
}               t_hashtable;


typedef struct  s_room_key
{
	char            *key;
	struct t_room   *room;
}               t_room_key;

typedef struct  s_room
{
	char            *name;
	int             room_num;
	int             x;
	int             y;
	struct t_room   *next;
}               t_room;

typedef struct  s_links
{
	struct t_room   *from_room;
	struct t_room   *to_room;
}               t_links;

void	create_lem_in(t_lem_in **lem_in, char **argv);
void    create_rooms(t_lem_in *lem_in, t_room **room);
void    lem_in(t_lem_in *lem_in);
void    lem_in_error(t_lem_in *lem_in);
void    lem_in_free(t_lem_in *lem_in);
void    parse_input(t_lem_in *lem_in);

#endif
// create an int on/off, so as you go through the rooms,
// you turn the room "on" to indicate it's occupied