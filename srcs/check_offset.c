/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_offset.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/07 19:06:09 by vmulder        #+#    #+#                */
/*   Updated: 2019/06/08 13:42:31 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/filler.h"

void	ft_check_offset_l(t_fillstr *vl)
{
	int i;
	int d;
	int a;

	i = 0;
	d = 0;
	a = 0;
	while (i < vl->tokenl)
	{
		while (d < vl->tokenw)
		{
			if (vl->token[i][d] == '*')
			{
				a = 1;
				break ;
			}
			d++;
		}
		if (a == 1)
		{
			vl->offsetl = i;
			break ;
		}
		i++;
		d = 0;
	}
//	ft_printf("offsetl: %d\n", vl->offsetl);
}

void	ft_check_offset_w(t_fillstr *vl)
{
	int i;
	int d;
	int a;

	i = 0;
	d = 0;
	a = 0;
	while (d < vl->tokenw)
	{
		while (i < vl->tokenl)
		{
			if (vl->token[i][d] == '*')
			{
				a = 1;
				break ;
			}
			i++;
		}
		if (a == 1)
		{
			vl->offsetw = d;
			break ;
		}
		i = 0;
		d++;
	}
//	ft_printf("offsetw: %d\n", vl->offsetw);
}