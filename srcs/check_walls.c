/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_walls.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/11 10:01:25 by vmulder        #+#    #+#                */
/*   Updated: 2019/06/14 19:06:37 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/filler.h"

/*
** those functions checks if there are already a o and x on the left side or
** on the ceiling of the field
*/

int		ft_check_rightwall(t_fillstr *vl, t_coor vlc)
{
	int d;
	int o;

	d = 0;
	o = 0;
	while (d < vl->fldl)
	{
		if (vl->field[d][vl->fldw - 1] == vlc.player)
			o = 1;
		d++;
	}
	if (o)
		return (1);
	return (0);
}

int		ft_check_leftwall(t_fillstr *vl, t_coor vlc)
{
	int d;
	int o;

	d = 0;
	o = 0;
	while (d < vl->fldl)
	{
		if (vl->field[d][0] == vlc.player)
			o = 1;
		d++;
	}
	if (o)
		return (1);
	return (0);
}

int		ft_check_ceiling(t_fillstr *vl, t_coor vlc)
{
	int d;
	int o;

	d = 0;
	o = 0;
	while (d < vl->fldw)
	{
		if (vl->field[0][d] == vlc.player)
			o = 1;
		d++;
	}
	if (o)
		return (1);
	return (0);
}

int		ft_check_bottom(t_fillstr *vl, t_coor vlc)
{
	int d;
	int o;

	d = 0;
	o = 0;
	while (d < vl->fldw)
	{
		if (vl->field[vl->fldl - 1][d] == vlc.player ||
			(vl->field[vl->fldl - 1][d] == vlc.comp &&
				vlc.playc[1] > vlc.compc[1]))
			o = 1;
		d++;
	}
	if (o)
		return (1);
	return (0);
}
