/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   manipulate_data.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/29 15:55:32 by vmulder        #+#    #+#                */
/*   Updated: 2019/05/29 15:56:21 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/filler.h"

void	ft_cutpiece(t_fillstr *vl)
{
	ft_strsplit(vl->token, '\n');
}
