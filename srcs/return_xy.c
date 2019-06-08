/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   return_xy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/03 18:54:40 by vmulder        #+#    #+#                */
/*   Updated: 2019/06/08 15:01:21 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/filler.h"
// i worked on the return value, return value is now not yet prototyped correctly
// then its ok and start testing for player is o.
/*
int		calc_coor_to_midfield(t_fillstr *vl, int lastx, int lasty)
{
	int i;

	i = (lastx + lasty) - (vl->midfield[1] + vl->midfield[0]);
//	ft_printf("this is the value: %d\n", i);
	if (i <= (vl->coorsave[1] + vl->coorsave[0]))
	{
		return (1);
	}
	return (0);
}

void	calc_and_save_coor_mf(t_fillstr *vl, int i, int d)
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
//	ft_printf("mf the field coor if the last * would be there: %d, %d\n", lastxy[0], lastxy[1]);
	if (calc_coor_to_midfield(vl, lastxy[0], lastxy[1]))
	{
		vl->coorsave[0] = d;
		vl->coorsave[1] = i;
	//	ft_printf("calc_coor was true ---- ");
//	ft_printf("it will go y: %d, and x: %d\n", i, d);
	}
}
*/
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
		td = 0;
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
	//int mp;

	i = 0;
	d = 0;
//	mp = 1;
//	if (vl->field[vl->midfield[0]][vl->midfield[1]] == '.')
//		mp = 1;
	while (i < vl->fieldl)
	{
		while (d < vl->fieldw)
		{
			if (ft_fitpiece_o(vl, i, d))
			{
				vl->coorsave[0] = d;
				vl->coorsave[1] = i;
				//ft_printf("y: %d\nx: %d\n\n", i, d);
				calc_and_save_coor_enemy(vl, vlc, i, d);
				//calc_and_save_coor_mf(vl, i, d);
			}
			// else if (ft_fitpiece_o(vl, i, d) && !mp)
			// {
			// }
			d++;
		}
		d = 0;
		i++;
	}
}

void		ft_placepiece(t_fillstr *vl, t_coor vlc)
{
//	vl->tokenl -= vl->offsetw;
//	vl->tokenw -= vl->offsetl;
	ft_findplace_o(vl, vlc);
	ft_write(*vl);
}