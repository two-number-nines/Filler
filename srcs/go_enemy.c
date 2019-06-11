/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   go_enemy.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/06 12:19:58 by vmulder        #+#    #+#                */
/*   Updated: 2019/06/11 16:11:31 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/filler.h"

/*
** play around with the -vlc el (enemy last placed) and see the impact.
** it destroys every player on big maps but map 00 is hard, try to block the walls
*/

void	calc_and_save_coor_enemy(t_fillstr *vl, t_coor vlc, int i, int d)
{
	int ti;
	int td;
	int lastxy[2];
	int temp;

	ti = 0;
	td = 0;
	lastxy[0] = 0;
	lastxy[1] = 0;
	while (ti < vl->tokenl)
	{
		while (td < vl->tokenw)
		{
			if (vl->token[ti][td] == '*')
			{
				lastxy[0] = d + td - vl->offsetw;
				lastxy[1] = i + ti - vl->offsetl;
				temp = ft_distance(vlc.el, lastxy);
			}
			if (temp < vl->distance && temp)
			{
				vl->distance = temp;
				vl->coorsave[0] = d;
				vl->coorsave[1] = i;
			}
			td++;
		}
		td = 0;
		ti++;
	}
}
