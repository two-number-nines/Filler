/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_player.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/29 14:21:58 by vmulder        #+#    #+#                */
/*   Updated: 2019/06/10 10:15:07 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/filler.h"

int globalfd;

void	ft_getplayer(t_players *vl)
{
	char		*playerstring;

	globalfd = open("input.txt", O_RDONLY);
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
//	ft_printf("the player: %c\nthe comp: %c\n", vl->player, vl->comp);
}
