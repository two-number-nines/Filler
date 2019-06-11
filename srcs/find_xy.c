/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   find_xy.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/31 16:02:33 by vmulder        #+#    #+#                */
/*   Updated: 2019/06/11 15:46:01 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/filler.h"
/*
void		ft_findmidfield(t_coor *vlc, t_fillstr vl)
{
	vlc->midfield[1] = vl.fieldw / 2;
	vlc->midfield[0] = vl.fieldl / 2;

//ft_printf("midfield: y=%d x=%d\n", vl->midfield[0], vl->midfield[1]);
}
*/
void		ft_findcoor_xo(t_coor *vlc, t_fillstr vl)
{
	int i;
	int d;

	i = 0;
	d = 0;
	while (i < vl.fieldl)
	{
		while (d < vl.fieldw)
		{
			if (vl.field[i][d] == vlc->player)
			{
				vlc->playc[0] = d;
				vlc->playc[1] = i;
			}
			if (vl.field[i][d] == vlc->comp)
			{
				vlc->compc[0] = d;
				vlc->compc[1] = i;
			}
			d++;
		}
		d = 0;
		i++;
	}
}

void		ft_findcoor(t_coor *vlc, t_fillstr vl)
{
	ft_findcoor_xo(vlc, vl);
	//ft_findmidfield(vlc, vl);
}