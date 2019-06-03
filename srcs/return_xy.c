/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   return_xy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/03 18:54:40 by vmulder        #+#    #+#                */
/*   Updated: 2019/06/03 19:07:31 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/filler.h"
// door het hele field gaan en alle plekken waarbij de token en field 1 ster overlappen 
// de afstand van midfield onthouden en als we door het hele veld zijn gegaan returnen we 
// de x and y met de waarde het dichts bij nul (verste x en y - midfield) zo gaan we asap
// daarna shiss maken voor als midfield bereikt is.

void	ft_fitpiece_o(t_fillstr *vl)
{
	int i;
	int d;

	i = 0;
	d = 0;
	while (vl->field);
}

void	ft_placepiece(t_fillstr *vl)
{
	ft_fitpiece_o(vl);
}