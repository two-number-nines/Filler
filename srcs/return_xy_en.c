/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   return_xy_en.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/06 12:19:58 by vmulder        #+#    #+#                */
/*   Updated: 2019/06/06 18:15:03 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/filler.h"

int		calc_coor_to_enemy(t_fillstr *vl, int lastx, int lasty)
{
	if ((lastx + lasty) - (vl->x[1] + vl->x[0]) <= (vl->coorsave[1] + vl->coorsave[0]))
	{
		return (1);
	}
	return (0);
}

void	calc_and_save_coor_enemy(t_fillstr *vl, int i, int d)
{
	int ti;
	int td;
	int lastxy[2];

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
				lastxy[0] = d + td;
				lastxy[1] = i + ti;
			}
			td++;
		}
		td = 0;
		ti++;
	}
	ft_printf("the field coor if the last * would be there: %d, %d\n", lastxy[0], lastxy[1]);
	if (calc_coor_to_enemy(vl, lastxy[0], lastxy[1]))
	{
		vl->coorsave[0] = d;
		vl->coorsave[1] = i;
		ft_printf("calc_coor was true ---- ");
		ft_printf("it will go y: %d, and x: %d\n", i, d);
	}
}