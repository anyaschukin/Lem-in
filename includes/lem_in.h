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

/* 
** Debug macros
** (set to 0 as standard, and corrector can change to try various maps)
*/

# define LINK_SELF 1 // 1 makes OK, 0 makes error
# define MAX_ANTS 99999

typedef struct  s_lem_in
{
	char            **argv;
	char            *line;
	char            *str;

	int				line_count;

	long            ant_c; // unsigned?
	int             start_c;
	int             end_c;
	unsigned int	room_count;

	struct s_room 	*start;
	struct s_room 	*end;
	struct s_room 	*room;
	struct s_room 	*reverse_path;
	struct s_link	*link;
	struct s_hashtable **table;
	struct s_ants	*ants;
}               t_lem_in;

typedef struct  s_room
{
	char            *name;
	int             room_num;
	int             x;
	int             y;
	int				occupied;
	struct s_room   *next;
	struct s_room   *collision;
	struct s_room	*path_next;
	struct s_room	*path_prev;
	struct  s_connection *connect;
}               t_room;

typedef struct  s_link
{
	char			*from_room;
	char			*to_room;
	struct s_link	*next;
}               t_link;

typedef struct  s_hashtable
{
	unsigned int	key;
	struct s_room	*ptr;
}               t_hashtable;

typedef struct  s_connection //
{
//	t_room			*from;
	t_room			*to;
	struct  s_connection *next;
}               t_connection;

typedef struct	s_ants
{
	long			ant_n;
	struct s_ants	*next;
}			t_ants;

void			create_hashtable(t_lem_in *lem_in);
void			create_lem_in(t_lem_in **lem_in, char **argv);
void    		add_ants(t_lem_in *lem_in);
void    		add_rooms(t_lem_in *lem_in, t_room **new);
void			add_links(t_lem_in *lem_in, t_link **new);
void			do_connections(t_lem_in *lem_in);
unsigned long	generate_hash(char *str, unsigned int room_count);
void    		lem_in(t_lem_in *lem_in);
void    		lem_in_error(t_lem_in *lem_in);
void    		lem_in_free(t_lem_in *lem_in);
void    		parse_input(t_lem_in *lem_in);
t_room  		*point_room(t_lem_in *lem_in, char *str);
void			start_or_end_room(t_lem_in *lem_in, t_room *room);
void    		solve(t_lem_in *lem_in);

#endif
// create an int on/off, so as you go through the rooms,
// you turn the room "on" to indicate it's occupied