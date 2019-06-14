/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_utils2.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/03 18:54:40 by vmulder        #+#    #+#                */
/*   Updated: 2019/06/14 17:43:59 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/filler.h"

int			ft_return(int count)
{
	if (count == 1)
		return (1);
	return (0);
}

void		ft_fit_piece_compare(char one, char two, int *count)
{
	if (one == two)
		(*count)++;
}

void		ft_fit_piece_incr(int *td, int *d)
{
	(*td)++;
	(*d)++;
}

void		ft_fit_piece_init(int *temp, int d, int *count)
{
	(*temp) = d;
	(*count) = 0;
}

void		ft_fit_piece_help(int *temp, int *i, int *d, int *ti)
{
	(*d) = (*temp);
	(*ti)++;
	(*i)++;
}
