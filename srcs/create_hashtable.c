/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashing_function.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/17 14:07:46 by aschukin          #+#    #+#             */
/*   Updated: 2018/06/17 14:07:49 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <unistd.h>

/*
** DBJ2 hash function
** (room_count * 100) guarantees that there are 100 hashes per room,
** to reduce # of collisions.
** (key * 33) changes the values of each bit
** after you've shifted them by the prime number
*/

unsigned long		generate_hash(char *str, unsigned int room_count)
{
	int				i;
	int				c;
	unsigned long	key;

	i = 0;
	c = str[i];
	key = 7919;
	while ((c = str[i++]))
		key += (key * 33) + c;
	return (key % (room_count * 100));
}

static t_hashtable	*create_bucket(t_lem_in *lem_in, t_room *room)
{
	t_hashtable	*new;

	if (!(new = (t_hashtable*)malloc(sizeof(*new))))
		lem_in_error(lem_in, 1);
	new->ptr = room;
	return (new);
}

/*
** Adds new_room (the collision) to the head of the bucket
** New_room->collision points to the old room
*/

static void			collision_handling(t_lem_in *lem_in, t_room *new_room,
unsigned long key)
{
	new_room->collision = lem_in->table[key]->ptr;
	lem_in->table[key]->ptr = new_room;
	if (!(ft_strcmp(new_room->name, lem_in->table[key]->ptr->name)))
		lem_in_error(lem_in, 16);
}

static void			fill_hashtable(t_lem_in *lem_in)
{
	t_room			*tmp;
	unsigned long	key;

	tmp = lem_in->room;
	key = 0;
	while (tmp != NULL)
	{
		key = generate_hash(tmp->name, lem_in->room_count);
		if (lem_in->table[key] != NULL)
			collision_handling(lem_in, tmp, key);
		else
			lem_in->table[key] = create_bucket(lem_in, tmp);
		tmp = tmp->next;
	}
}

void				create_hashtable(t_lem_in *lem_in)
{
	unsigned int	i;

	i = 0;
	if (!(lem_in->table = (t_hashtable**)malloc(sizeof(t_hashtable)
	* lem_in->room_count * 1000)))
		lem_in_error(lem_in, 1);
	while (i < lem_in->room_count * 1000)
		lem_in->table[i++] = NULL;
	fill_hashtable(lem_in);
}
