/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   go_enemy.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/06 12:19:58 by vmulder        #+#    #+#                */
/*   Updated: 2019/06/10 11:59:19 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/filler.h"

int			ft_sqrt(int n)
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

int			ft_distance(int *enemy, int *tokencoor)
{
	int x;
	int y;
	int dist;

	x = enemy[0] - tokencoor[0];
	y = enemy[1] - tokencoor[1];
	dist = ft_sqrt((x*x) + (y*y));
	return (dist);
}

void		ft_latest_x(t_fillstr *vl, t_coor *vlc)
{
	int i;
	int d;
	int b;

	i = 0;
	d = 0;
	b = 0;
	while (i < vl->fieldl)
	{
		while (d < vl->fieldw)
		{
			if (vl->field[i][d] == 'X')
			{
				vlc->x[0] = d;
				vlc->x[1] = i;
				b = 1;
				break ;
			}
			d++;
		}
		if (b)
			break;
		d = 0;
		i++;
	}
}

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
				temp = ft_distance(vlc.x, lastxy);
			}
			if (temp <= vl->distance)
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