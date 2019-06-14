/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   write_coor.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/06 18:18:46 by vmulder        #+#    #+#                */
/*   Updated: 2019/06/14 13:01:12 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/filler.h"

void	ft_write(t_fillstr vl)
{
	vl.coorsave[0] -= vl.offsetw;
	vl.coorsave[1] -= vl.offsetl;
	ft_printf("%d %d\n", vl.coorsave[1], vl.coorsave[0]);
}
