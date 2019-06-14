/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_player.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/29 14:21:58 by vmulder        #+#    #+#                */
/*   Updated: 2019/06/14 19:12:24 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/filler.h"

void	ft_getplayer(t_coor *vl)
{
	char		*playerstring;

	get_next_line(0, &playerstring);
	if (playerstring[10] == '1')
	{
		vl->player = 'O';
		vl->comp = 'X';
	}
	else
	{
		vl->player = 'X';
		vl->comp = 'O';
	}
	free(playerstring);
}
