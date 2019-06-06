/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   write_coor.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/06 18:18:46 by vmulder        #+#    #+#                */
/*   Updated: 2019/06/06 19:30:14 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/filler.h"

void	ft_write(t_fillstr vl)
{
	vl.coorsave[0] -= vl.offseth;
	vl.coorsave[1] -= vl.offsetva;

	ft_printf("%d %d", vl.coorsave[0], vl.coorsave[1]);
}