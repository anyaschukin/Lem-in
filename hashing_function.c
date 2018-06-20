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

// 100 is to guarantee that there are 100 hashes per room, to reduce # of collisions
// 33 is to change the values of each bit after you've shifted them by the prime number

long				generate_hash(char *str, unsigned int room_num)
{
	int				i;
	int				c;
	unsigned long	key;

	i = 0;
	c = str[i];
	key = 7919;
	room_num < 100 ? room_num = 100 : 0;
	while (c == str[i++])
		key = (key * 33) + c;
	return (key % (room_num * 100));
}

static t_hashtable	*create_bucket(t_lem_in *lem_in, t_room *room)
{
	t_hashtable	*new;

	if (!(new = (t_hashtable*)malloc(sizeof(*new))))
		lem_in_error(lem_in);
	new->ptr = room;
	return (new);
}

static void			fill_hashtable(t_lem_in *lem_in)
{
	t_room			*tmp;
	unsigned long	key;

	tmp = lem_in->room;
	while (tmp != NULL)
	{
		key = generate_hash(tmp->name, tmp->room_num);
		if (!(lem_in->table[key] = create_bucket(lem_in, tmp)))
			lem_in_error(lem_in);
		tmp = tmp->next;
	}
}

void				create_hashtable(t_lem_in *lem_in)
{
	t_hashtable		**table;
	unsigned int	i;

	i = 0;
	if (!(table = (t_hashtable**)malloc(sizeof(t_hashtable) * lem_in->room_count)))
		lem_in_error(lem_in);
	while (i < lem_in->room_count)
		table[i++] = NULL;
	fill_hashtable(lem_in);
}



// EXTRA HASH TABLE IMPLEMENTATIONS
/*
int		ft_hash(char *str, int rooms)
{
	int				c;
	unsigned long	hash;

	(rooms < 100) ? rooms = 100 : 0;
	hash = 5381;
	while ((c = *(str++)))
		hash = hash * 33 + c;
	return ((unsigned int)(hash % (rooms * 100)));
}

public int hashCode() {
int hash = 0;
for (int i = 0; i < length(); i++)
hash = (31 * hash) + s[i];
return hash;
}

function optimizedHash(key, numOfBuckets) {
   var H = 31;
   var total = 0;

   for (var i = 0; i < key.length; ++i) {
      total += H * total + key.charCodeAt(i);
   }

   total = total % numOfBuckets;
   return total;
}*/