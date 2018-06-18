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
/*
long	generate_hash(char *str, int room_num)
{
	int				i;
	int				c;
	unsigned long	hash;

	i = 0;
	hash = 7919;
	room_num < 100 ? room_num = 100 : 0;
	while (c = str[i++]))
		hash = (hash * 33) + c;
	return (hash % (room_num * 100));
}

t_hashtable	*create_entry(t_room *room)
{
	t_hashtable	*new;

	if (!(new = (t_hashtable*)malloc(sizeof(*new))))
		return (NULL);
	new->ptr = ptr;
	return (new);
}

void	create_hashtable(t_lem_in *lem_in, t_hashtable **hash)
{
	int			i;

	i = 0;
	if (!(hash = (t_hashtable**)malloc(sizeof(t_hashtable) * t_lem_in->room_count)))
		return (NULL);
	while (i < t_lem_in->room_count)
		hash[i++] = NULL;
	return (hash);
}

void		fill_hashtable(t_lem_in *lem_in, t_room *room)
{

}

void		free_hashtable()
{

}


// EXTRA HASH TABLE IMPLEMENTATIONS

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