/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_player.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/29 14:21:58 by vmulder        #+#    #+#                */
/*   Updated: 2019/06/11 18:31:48 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/filler.h"

int globalfd = 0;

void	ft_getplayer(t_coor *vl)
{
	char		*playerstring;

//	globalfd = open("input.txt", O_RDONLY);
	get_next_line(globalfd, &playerstring);
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
