/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   find_fit.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/03 18:54:40 by vmulder        #+#    #+#                */
/*   Updated: 2019/06/14 11:40:51 by vmulder       ########   odam.nl         */
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

	i = vl->fieldl - 1;
	d = vl->fieldw - 1;
	b = 0;
	while (0 < i)
	{
		while (0 < d)
		{
			if (vl->field[i][d] == vlc->comp)
			{
				if (d + 2 < vl->fieldw)
					vlc->el[0] = d + 2;
				else
					vlc->el[0] = d;
				if (i > 0)
					vlc->el[1] = i - 1;
				else
					vlc->el[1] = i;
				
				b = 1;
				break ;
			}
			d--;
		}
		if (b)
			break;
		d = vl->fieldw - 1;
		i--;
	}
//	ft_printf("the enemy x and y: %d, %d\n", vlc->el[0], vlc->el[1]);
}

void		ft_last_enemy_when_ph(t_fillstr *vl, t_coor *vlc)
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
			if (vl->field[i][d] == vlc->comp)
			{
			//	if (d + 2 < vl->fieldw)
			//		vlc->el[0] = d + 2;
			//	else
					vlc->el[0] = d;
			//	if (i > 0)
			//		vlc->el[1] = i - 1;
			//	else
					vlc->el[1] = i;
				
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
	//ft_printf("the enemy x and y: %d, %d\n", vlc->el[0], vlc->el[1]);
}

/*
** check the latest enemy piece on the board.
** (if) is for as the player begins lower in the field.
*/

void		ft_latest_e(t_fillstr *vl, t_coor *vlc)
{
	if (vlc->playc[1] > vlc->compc[1]) // als player onder start.
	{
	//	ft_printf("de verkeerde if\n");
		if (ft_check_ceiling(vl, *vlc)) // als we naar beneden moeten
		{
			if (ft_check_bottom(vl, *vlc)) // als we ook beneden zijn geweest en naar midden willen
			{
				vlc->el[0] = 0;
				vlc->el[1] = vl->fieldl - (vl->fieldl / 3);
			}
			else
			{
				vlc->el[0] = (vl->fieldw / 2);
				vlc->el[1] = vl->fieldl;
			}
		}
		else
		{
			//ft_last_enemy_when_ph(vl, vlc);
			vlc->el[0] = (vl->fieldw / 2 + (vl->fieldw / 5));
			vlc->el[1] = 0;
		}
	}
	else
	{
		if (ft_check_bottom(vl, *vlc)) // als we onder zijn is het true.
			ft_last_enemy_when_ph(vl, vlc);
		else
			ft_last_enemy_when_pl(vl, vlc);
	}
	// //	ft_printf("de eerste juiste else\n");
	// 	if (ft_check_bottom(vl, *vlc)) // als we naar boven moeten
	// 	{
	// 	//	ft_printf("de tweede juiste else\n");
	// 		if (ft_check_ceiling(vl, *vlc)) // als we ook boven zijn geweest en naar midden willen
	// 		{
	// 			vlc->el[0] = vl->fieldw - (vl->fieldw / 3);
	// 			vlc->el[1] = (vl->fieldl / 2);
	// 		}
	// 		else
	// 		{
	// 		//	ft_printf("de derde juiste else\n");
	// 			vlc->el[0] = (vl->fieldw / 2);
	// 			vlc->el[1] = 0;
	// 		}
	// 	}
	// 	else
	// 	{
	// 		//ft_last_enemy_when_ph(vl, vlc);
	// 	//	ft_printf("de tweede juiste else\n");
	// 		vlc->el[0] = (vl->fieldw / 2 - (vl->fieldw / 5));
	// 		vlc->el[1] = vl->fieldl;
	// 	//	ft_printf("the el[0]: %d\n the el[1]: %d\n", vlc->el[0], vlc->el[1]);
	// 	}
	// }
// 	{
// 		//here i could just switch up the above code then it will win ///////////////////////
// 		if (ft_check_bottom(vl, *vlc)) // als we onder zijn is het true.
// 			ft_last_enemy_when_ph(vl, vlc);
// 		else
// 			ft_last_enemy_when_pl(vl, vlc);
// 	}
// //	ft_printf("the the enemy position: x:%d, y:%d\n", vlc->el[0], vlc->el[1]);
}

int		ft_fitpiece(t_fillstr *vl, t_coor vlc, int i, int d)
{
	int ti;
	int td;
	int count;
	int temp;

	temp = d;
	ti = vl->offsetl;
	td = vl->offsetw;
	count = 0;
	while (ti < vl->tokenl)
	{
		while (td < vl->tokenw)
		{
			if (d >= vl->fieldw || i >= vl->fieldl)
				if (vl->token[ti][td] == '*')
					return (0);
			if (vl->token[ti][td] == '*' && d < vl->fieldw && i < vl->fieldl)
			{
				if (vl->field[i][d] == vlc.comp)
					return (0);
				else if (vl->field[i][d] == vlc.player)
					count++;
			}
			td++;
			d++;
		}
		td = vl->offsetw;
		d = temp;
		ti++;
		i++;
	}
	if (count == 1)
		return (1);
	return (0);
}

void		ft_findplace(t_fillstr *vl, t_coor vlc)
{
	int i;
	int d;
	int first;
	int wall;

	i = 0;
	d = 0;
	first = 0;
	wall = 0;
	ft_latest_e(vl, &vlc);
	while (i < vl->fieldl)
	{
		while (d < vl->fieldw)
		{
			if (ft_fitpiece(vl, vlc, i, d))
			{
				if (!first)
				{
					vl->coorsave[0] = d;
					vl->coorsave[1] = i;
				}
				first = 1;
				if (calc_and_go_wall(vl, vlc, i, d))
				{
					wall = 1;
				}
				else if (!wall)	
					calc_and_save_coor_enemy(vl, vlc, i, d);
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