/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 15:27:15 by aschukin          #+#    #+#             */
/*   Updated: 2018/06/30 13:56:50 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	lem_in_error(t_lem_in *lem_in)
{
	write(1, "Error\n", 6);
	lem_in_free(lem_in);
	exit(-1);
}
