/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_utils.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/10 13:03:25 by vmulder        #+#    #+#                */
/*   Updated: 2019/06/14 13:22:06 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/filler.h"

static int	ft_sqrt(int n)
{
	int count;
	int x;
	int i;

	x = 0;
	count = 0;
	i = 1;
	while (x < n)
	{
		x = x + i;
		count++;
		i += 2;
	}
	return (count);
}

void		ft_init_walls(t_fillstr *vl, int *ti, int *td)
{
	(*ti) = vl->offsetl;
	(*td) = vl->offsetw;
}

int			ft_return_coor(t_fillstr *vl, int i, int d)
{
	vl->coorsave[0] = d;
	vl->coorsave[1] = i;
	return (1);
}

int			ft_distance(int *enemy, int *tokencoor)
{
	int x;
	int y;
	int dist;

	x = enemy[0] - tokencoor[0];
	y = enemy[1] - tokencoor[1];
	dist = ft_sqrt((x * x) + (y * y));
	return (dist);
}
