/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/24 16:00:51 by vmulder        #+#    #+#                */
/*   Updated: 2019/05/29 14:31:20 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/filler.h"

// check if ft_strsplit deletes the char c
// probable make the vl->field a 2d array and also make token a 2d array and finish the ft_cutpiece.
//replace filedescriptor 1 with 0

void	ft_cutpiece(t_fillstr *vl)
{
	ft_strsplit(vl->token, '\n');
}

void	ft_init(t_fillstr *vl)
{
	ft_bzero(vl, sizeof(t_fillstr));
}

void	ft_start_cond(void)
{
	t_fillstr vl;

	ft_init(&vl);
	ft_getplayer(&vl);
	ft_getfield(&vl);
	ft_getpiece(&vl);
//	ft_cutpiece(&vl);
}

int		main(void)
{
	ft_start_cond();
	return (0);
}
