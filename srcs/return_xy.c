/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   return_xy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/03 18:54:40 by vmulder        #+#    #+#                */
/*   Updated: 2019/06/06 12:10:16 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/filler.h"
// door het hele field gaan en alle plekken waarbij de token en field 1 ster overlappen 
// de afstand van midfield onthouden en als we door het hele veld zijn gegaan returnen we 
// de x and y met de waarde het dichts bij nul (verste x en y - midfield) zo gaan we asap
// daarna shiss maken voor als midfield bereikt is.

int		calc_coor(t_fillstr *vl, int lastx, int lasty)
{
	if (lastx - vl->midfield[0] < vl->coorsave[0] && lasty - vl->midfield[1] < vl->coorsave[1])
	{
		return (1);
	}
	return (0);
}

void	calc_and_save_coor(t_fillstr *vl, int i, int d)
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
	if (calc_coor(vl, lastxy[0], lastxy[1]))
	{
		vl->coorsave[0] = d;
		vl->coorsave[1] = i;
		ft_printf("calc_coor was true ---- ");
		ft_printf("it will go y: %d, and x: %d\n", i, d);
	}
	//ft_printf("this is the coor closest to mid: x: %d y: %d\n", vl->coorsave[0], vl->coorsave[1]);
}

int		ft_fitpiece_o(t_fillstr *vl, int i, int d)
{
	int ti;
	int td;
	int counter;

	ti = 0;
	td = 0;
	counter = 0;
	while (ti < vl->tokenl)
	{
		while (td < vl->tokenw)
		{
			if (vl->token[ti][td] == '*' && (i + ti) < vl->fieldl && (d + td) < vl->fieldw)
			{
				if (vl->field[i + ti][d + td] == 'O')
					counter++;
				else if (vl->field[i + ti][d + td] == 'X')
					return (0);
			}
			td++;
		}
		td = 0;
		ti++;
	}
	if (counter == 1)
		return (1);
	return (0);
}

void	ft_findplace_o(t_fillstr *vl)
{
	int i;
	int d;
	int mp;

	i = 0;
	d = 4;
	mp = 0;
	if (vl->field[vl->midfield[0]][vl->midfield[1]] == '.')
		mp = 1;
	while (i < vl->fieldl)
	{
		while (d < vl->fieldw)
		{
			if (ft_fitpiece_o(vl, i, d) && mp)
			{
				calc_and_save_coor(vl, i, d);
			}
			d++;
		}
		d = 4;
		i++;
	}
}

void	ft_placepiece(t_fillstr *vl)
{
	vl->tokenl -= vl->offsetv;
	vl->tokenw -= vl->offseth;
	ft_findplace_o(vl);
}