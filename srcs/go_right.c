/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   go_right.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/09 17:12:47 by vmulder        #+#    #+#                */
/*   Updated: 2019/06/10 09:41:49 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/filler.h"

void	calc_and_save_coor_gr(t_fillstr *vl, int i, int d)
{
	int ti;
	int td;
	int temp;

	ti = 0;
	td = 0;
	temp = 0;
	while (ti < vl->tokenl)
	{
		while (td < vl->tokenw)
		{
			if (vl->token[ti][td] == '*')
			{
				temp = d + td - vl->offsetw;
			}
			if (temp >= vl->mostx)
			{
				vl->mostx = temp;
				vl->coorsave[0] = d;
				vl->coorsave[1] = i;
			}
			td++;
		}
		td = 0;
		ti++;
	}
}
