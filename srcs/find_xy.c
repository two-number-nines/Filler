/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   find_xy.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/31 16:02:33 by vmulder        #+#    #+#                */
/*   Updated: 2019/06/14 19:15:36 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/filler.h"

void		ft_latest_e(t_fillstr *vl, t_coor *vlc)
{
	if (vlc->playc[1] > vlc->compc[1])
	{
		if (ft_check_ceiling(vl, *vlc))
		{
			if (ft_check_bottom(vl, *vlc))
				ft_el_help(vl, vlc, 1);
			else
				ft_el_help(vl, vlc, 2);
		}
		else
			ft_el_help(vl, vlc, 3);
	}
	else
	{
		if (!ft_check_ceiling(vl, *vlc))
			ft_last_enemy_when_ph(vl, vlc);
		else
			ft_last_enemy_when_pl(vl, vlc);
	}
}

void		ft_findcoor_xo(t_coor *vlc, t_fillstr vl)
{
	int i;
	int d;

	i = 0;
	d = 0;
	while (i < vl.fldl)
	{
		while (d < vl.fldw)
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
