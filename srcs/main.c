/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/24 16:00:51 by vmulder        #+#    #+#                */
/*   Updated: 2019/06/07 20:27:18 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/filler.h"

void	ft_init(t_fillstr *vl)
{
	ft_bzero(vl, sizeof(t_fillstr));
	//vl->offseth = -1;
}

void	ft_start_cond(void)
{
	t_fillstr 	vl;

		ft_init(&vl);
		ft_printf("getplayer\n");
		ft_printf("----------\n");
		ft_getplayer(&vl);
		ft_printf("\n\ngetfield\n");
		ft_printf("----------\n");
		ft_getfield(&vl);
		ft_printf("\n\nfind_coor\n");
		ft_printf("----------\n");
		ft_findcoor(&vl);
		ft_printf("\n\ngetpiece\n");
		ft_printf("----------\n");
		ft_getpiece(&vl);
		ft_printf("\n\nplacepiece\n");
		ft_printf("----------\n");
		ft_placepiece(&vl);
	// while (1);
}

int		main(void)
{
	ft_start_cond();
	return (0);
}
