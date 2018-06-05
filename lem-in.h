/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
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
#include <fnctl.h> 

typedef struct  s_lem_in
{
    char    **argv;
    char    *line;
    char    *str;

    int     ants;
    t_room  *start;
    t_room  *end;
    t_room  *room;

}               t_lem_in;

typedef struct  s_hashtable
{
    int     size;
    int     count;
    char    **rooms;
}               t_hashtable;


typedef struct  s_room
{
    char    *key;
    char    *name;
    int     x;
    int     y;
    char    *link1;
    char    *link2;
    t_room  *next;
}