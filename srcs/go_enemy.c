/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   go_enemy.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/06 12:19:58 by vmulder        #+#    #+#                */
/*   Updated: 2019/06/10 17:48:56 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/filler.h"

/*
** this function checks if there are already a o and x on the left side or
** on the ceiling of the field
*/

/*
** play around with the -vlc xl and see the impact.
** it destroys every player on big maps but map 00 is hard, try to block the walls
*/

int		ft_check_rightwall(t_fillstr *vl)
{
	int d;
	int o;
	int x;

	d = 0;
	o = 0;
	x = 0;
	while (d < vl->fieldl)
	{
		if (vl->field[d][vl->fieldl] == 'o' || vl->field[d][vl->fieldl] == 'O')
			o = 1;
		d++;
	}
	if (o)
		return (1);
	return (0);
}

int		ft_check_leftwall(t_fillstr *vl)
{
	int d;
	int o;
	int x;

	d = 0;
	o = 0;
	x = 0;
	while (d < vl->fieldl)
	{
		if (vl->field[d][0] == 'x' || vl->field[d][0] == 'X')
			x = 1;
		if (vl->field[d][0] == 'o' || vl->field[d][0] == 'O')
			o = 1;
		d++;
	}
	if (x && o)
		return (1);
	if (o)
		return (2);
	return (0);
}

int		ft_check_ceiling(t_fillstr *vl)
{
	int d;
	int o;
	int x;

	d = 0;
	o = 0;
	x = 0;
	while (d < vl->fieldw)
	{
		if (vl->field[0][d] == 'o' || vl->field[0][d] == 'O')
			o = 1;
		d++;
	}
	if (o)
		return (1);
	return (0);
}
//now it should go in the ffff else if
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
				if ((ft_check_ceiling(vl) || ft_check_leftwall(vl)) || (
					ft_check_leftwall(vl) == 2 && ft_check_ceiling(vl)) ||
					ft_check_rightwall(vl))
				{
					temp = ft_distance(vlc.x, lastxy);
				}
				//else if ((ft_check_ceiling(vl) || ft_check_rightwall(vl)) &&
			//				!ft_check_leftwall(vl))
			//	{
			//		vlc.x[0] = 0;
			//		vlc.x[1] = vlc.lo;
			//		temp = ft_distance(vlc.xl, lastxy);
		//		}
				else
				{
					temp = ft_distance(vlc.xl, lastxy);
				}
				// ft_printf("temp: %d\n", temp);
				// if (temp == 2)
				// 	ft_printf("the x and y: x: %d y: %d\n", lastxy[0], lastxy[1]);
				// ft_printf("distance: %d\n", vl->distance);
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
