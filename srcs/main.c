/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/24 16:00:51 by vmulder        #+#    #+#                */
/*   Updated: 2019/06/10 11:56:45 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/filler.h"

void	ft_init_vl(t_fillstr *vl)
{
	ft_bzero(vl, sizeof(t_fillstr));
	vl->distance = 1000;
}

void	ft_init(t_coor *vlc, t_players *vlp)
{
	ft_bzero(vlc, sizeof(t_coor));
	ft_bzero(vlp, sizeof(t_players));
}

void	ft_start_cond(void)
{
	t_fillstr 	vl;
	t_players	vlp;
	t_coor		vlc;
	int			i;
	int			ret;

	ft_init(&vlc, &vlp);
	ft_getplayer(&vlp);
	i = 0;
	ret = 1;
	while (ret)
	{
	//	ft_printf("\n\nround nr :%d\n", loop);
		ft_init_vl(&vl);
		// ft_printf("getplayer\n");
		// ft_printf("----------\n");
		// ft_printf("\n\ngetfield\n");
		// ft_printf("----------\n");
		ret = ft_getfield(&vl);
		if (ret)
		{
			if (!i)
				ft_findcoor(&vlc, vl);
			// ft_printf("\n\nfind_coor\n");
			// ft_printf("----------\n");
			// ft_printf("\n\ngetpiece\n");
			// ft_printf("----------\n");
			ft_getpiece(&vl);
			// ft_printf("\n\nplacepiece\n");
			// ft_printf("----------\n");
			ft_placepiece(&vl, vlc);
		}
		 //while (1);
		 i = 1;
	}
}

int		main(void)
{
	ft_start_cond();
	return (0);
}
