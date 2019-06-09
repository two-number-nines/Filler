/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   go_right.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/09 17:12:47 by vmulder        #+#    #+#                */
/*   Updated: 2019/06/09 18:30:31 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/filler.h"

int		calc_coor_to_right(t_fillstr *vl, int mostx)
{
	int i;

	i = mostx - (vl->fieldw);
	if (i > (vl->coorsave[1] + vl->coorsave[0]))
	{
		return (1);
	}
	return (0);
}

void	calc_and_save_coor_gr(t_fillstr *vl, int i, int d)
{
	int ti;
	int td;
	int mostx;

	ti = 0;
	td = 0;
	mostx = 0;
	while (ti < vl->tokenl)
	{
		while (td < vl->tokenw)
		{
			if (vl->token[ti][td] == '*' && mostx < td)
			{
				mostx = d + td - vl->offsetw;
			}
			td++;
		}
		td = 0;
		ti++;
	}
//	ft_printf("mf the field coor if the last * would be there: %d, %d\n", lastxy[0], lastxy[1]);
	if (calc_coor_to_right(vl, mostx))
	{
		vl->coorsave[0] = d;
		vl->coorsave[1] = i;
	//	ft_printf("calc_coor was true ---- ");
//	ft_printf("it will go y: %d, and x: %d\n", i, d);
	}
}