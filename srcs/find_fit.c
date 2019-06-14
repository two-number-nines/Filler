/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   find_fit.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/03 18:54:40 by vmulder        #+#    #+#                */
/*   Updated: 2019/06/14 19:28:05 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/filler.h"

/*
** find the position of enemy in field.
*/

void		ft_last_enemy_when_pl(t_fillstr *vl, t_coor *vlc)
{
	int i;
	int d;
	int b;

	i = vl->fldl - 1;
	d = vl->fldw - 1;
	b = 0;
	while (0 < i)
	{
		while (0 < d)
		{
			if (vl->field[i][d] == vlc->comp)
			{
				vlc->el[0] = d;
				vlc->el[1] = i;
				b = 1;
				break ;
			}
			d--;
		}
		if (b)
			break ;
		d = vl->fldw - 1;
		i--;
	}
}

void		ft_last_enemy_when_ph(t_fillstr *vl, t_coor *vlc)
{
	int i;
	int d;
	int b;

	i = 0;
	d = 0;
	b = 0;
	while (i < vl->fldl)
	{
		while (d < vl->fldw)
		{
			if (vl->field[i][d] == vlc->comp)
			{
				vlc->el[0] = d + (vl->fldw / 4);
				vlc->el[1] = i - (vl->fldl / 4);
				b = 1;
				break ;
			}
			d++;
		}
		if (b)
			break ;
		d = 0;
		i++;
	}
}

/*
** check the latest enemy piece on the board.
** (if) is for as the player begins lower in the field.
*/

int			ft_fitpiece(t_fillstr *vl, t_coor vlc, int i, int d)
{
	int ti;
	int td;
	int count;
	int temp;

	ft_init_offset(vl, &ti, &td);
	ft_fit_piece_init(&temp, d, &count);
	while (ti < vl->tokenl)
	{
		while (td < vl->tokenw)
		{
			if ((d >= vl->fldw || i >= vl->fldl) && vl->token[ti][td] == '*')
				return (0);
			if (vl->token[ti][td] == '*' && d < vl->fldw && i < vl->fldl)
			{
				if (vl->field[i][d] == vlc.comp)
					return (0);
				ft_fit_piece_compare(vl->field[i][d], vlc.player, &count);
			}
			ft_fit_piece_incr(&td, &d);
		}
		td = vl->offsetw;
		ft_fit_piece_help(&temp, &i, &d, &ti);
	}
	return (ft_return(count));
}

void		ft_findplace(t_fillstr *vl, t_coor vlc)
{
	int i;
	int d;
	int wall;

	i = 0;
	d = 0;
	wall = 0;
	ft_latest_e(vl, &vlc);
	while (i < vl->fldl)
	{
		while (d < vl->fldw)
		{
			if (ft_fitpiece(vl, vlc, i, d))
			{
				if (calc_and_go_wall(vl, vlc, i, d))
					wall = 1;
				else if (!wall)
					calc_save_co_en(vl, vlc, i, d);
			}
			d++;
		}
		d = 0;
		i++;
	}
}

void		ft_placepiece(t_fillstr *vl, t_coor vlc)
{
	ft_findplace(vl, vlc);
	ft_write(*vl);
}
