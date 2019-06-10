/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   go_midfield.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/10 09:42:26 by vmulder        #+#    #+#                */
/*   Updated: 2019/06/10 09:48:09 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/filler.h"

void	calc_and_save_coor_mf(t_fillstr *vl, t_coor vlc, int i, int d)
{
	int ti;
	int td;
	int lastxy[2];

	ti = 0;
	td = 0;
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
}