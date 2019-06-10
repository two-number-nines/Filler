/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   find_fit_o.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/03 18:54:40 by vmulder        #+#    #+#                */
/*   Updated: 2019/06/10 10:37:49 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/filler.h"

int		ft_fitpiece_o(t_fillstr *vl, int i, int d)
{
	int ti;
	int td;
	int count;
	int temp;

	temp = d;
	ti = vl->offsetl;
	td = vl->offsetw;
	count = 0;
	while (ti < vl->tokenl)
	{
		while (td < vl->tokenw)
		{
			if (d >= vl->fieldw || i >= vl->fieldl)
				if (vl->token[ti][td] == '*')
					return (0);
			if (vl->token[ti][td] == '*' && d < vl->fieldw && i < vl->fieldl)
			{
				if (vl->field[i][d] == 'X')
					return (0);
				else if (vl->field[i][d] == 'O')
					count++;
			}
			td++;
			d++;
		}
		td = vl->offsetw;
		d = temp;
		ti++;
		i++;
	}
	if (count == 1)
		return (1);
	return (0);
}

void		ft_findplace_o(t_fillstr *vl, t_coor vlc)
{
	int i;
	int d;
	int first;

	i = 0;
	d = 0;
	first = 0;
	(void)vlc;
	ft_latest_x(vl, &vlc);
	while (i < vl->fieldl)
	{
		while (d < vl->fieldw)
		{
			if (ft_fitpiece_o(vl, i, d))
			{
				if (!first)
				{
					vl->coorsave[0] = d;
					vl->coorsave[1] = i;
				}
				first = 1;
				calc_and_save_coor_enemy(vl, vlc, i, d);
			}
			d++;
		}
		d = 0;
		i++;
	}
}

void		ft_placepiece(t_fillstr *vl, t_coor vlc)
{
	ft_findplace_o(vl, vlc);
	ft_write(*vl);
}