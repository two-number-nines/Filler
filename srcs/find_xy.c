/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   find_xy.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/31 16:02:33 by vmulder        #+#    #+#                */
/*   Updated: 2019/06/03 16:45:40 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/filler.h"
/*
void		check_space(t_fillstr *vl)
{
	
}
*/
void		ft_findcoor_xo(t_fillstr *vl)
{
	int i;
	int d;

	i = 0;
	d = 0;
	while (i < vl->fieldl)
	{
		while (d < vl->fieldw + 4)
		{
			if (vl->field[i][d] == 'O')
			{
				vl->o[0] = d;
				vl->o[1] = i;
			}
			if (vl->field[i][d] == 'X')
			{
				vl->x[0] = d;
				vl->x[1] = i;
			}
			d++;
		}
		d = 0;
		i++;
	}
	ft_printf("\nX: x=%d y=%d\n", vl->x[0], vl->x[1]);
	ft_printf("O: x=%d y=%d\n", vl->o[0], vl->o[1]);
}
