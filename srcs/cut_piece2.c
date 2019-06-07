/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cut_piece2.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/29 15:55:32 by vmulder        #+#    #+#                */
/*   Updated: 2019/06/07 22:30:49 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/filler.h"

void	new_token(t_fillstr *vl)
{
	int i;
	int d;
	int c;

	i = 0;
	d = 0;
	c = 0;
	while (i < vl->tokenl)
	{
		while (d < vl->tokenw)
		{
			if (vl->token[i][d] == '*' || vl->token[i][d] == '.')
				c = 1;
			d++;
		}
		if (!c)
			ft_strdel(&vl->token[i]);
		d = 0;
		c = 0;
		i++;
	}
}