/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   write_coor.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/06 18:18:46 by vmulder        #+#    #+#                */
/*   Updated: 2019/06/07 12:43:41 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/filler.h"

void	ft_write(t_fillstr vl)
{
	// FILE	*target;

	// target = fopen("target", "a+");
	// fprintf(target, "%d, %d\n", (vl.coorsave[0] -= vl.offseth + 4), (vl.coorsave[1] -= vl.offsetva));
	// fflush(target);
	//vl.coorsave[0];
	//vl.coorsave[1];

	ft_printf("%d %d", vl.coorsave[1], vl.coorsave[0]);
}