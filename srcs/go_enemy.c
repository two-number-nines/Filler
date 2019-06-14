/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   go_enemy.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/06 12:19:58 by vmulder        #+#    #+#                */
/*   Updated: 2019/06/14 19:28:05 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/filler.h"

static void	init_calc_and_save(int *ti, int *td, int *lastxy, int *temp)
{
	(*ti) = 0;
	(*td) = 0;
	(*temp) = 0;
	(*lastxy) = 0;
	(*++lastxy) = 0;
}

static void	save_the_coor(t_fillstr *vl, int i, int d, int temp)
{
	if (temp < vl->distance && temp)
	{
		vl->distance = temp;
		ft_return_coor(vl, i, d);
	}
}

void		calc_save_co_en(t_fillstr *vl, t_coor vlc, int i, int d)
{
	int ti;
	int td;
	int lastxy[2];
	int temp;

	init_calc_and_save(&ti, &td, lastxy, &temp);
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
			save_the_coor(vl, i, d, temp);
			td++;
		}
		td = 0;
		ti++;
	}
}
