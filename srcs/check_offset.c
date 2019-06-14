/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_offset.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/07 19:06:09 by vmulder        #+#    #+#                */
/*   Updated: 2019/06/14 19:10:04 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/filler.h"

static void	ft_init_offsets(int *i, int *d, int *a)
{
	(*i) = 0;
	(*d) = 0;
	(*a) = 0;
}

void		ft_check_offset_l(t_fillstr *vl)
{
	int i;
	int d;
	int a;

	ft_init_offsets(&i, &d, &a);
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
}

void		ft_check_offset_w(t_fillstr *vl)
{
	int i;
	int d;
	int a;

	ft_init_offsets(&i, &d, &a);
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
}
