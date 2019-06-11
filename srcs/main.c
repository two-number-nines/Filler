/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/24 16:00:51 by vmulder        #+#    #+#                */
/*   Updated: 2019/06/11 14:32:03 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/filler.h"

void	ft_init_vl(t_fillstr *vl)
{
	ft_bzero(vl, sizeof(t_fillstr));
	vl->distance = 1000;
}

void	ft_init(t_coor *vlc)
{
	ft_bzero(vlc, sizeof(t_coor));
}

void	ft_start_cond(void)
{
	t_fillstr 	vl;
	t_coor		vlc;
	int			i;
	int			ret;

	ft_init(&vlc);
	ft_getplayer(&vlc);
	i = 0;
	ret = 1;
	while (ret)
	{

		ft_init_vl(&vl);
		ret = ft_getfield(&vl);
		if (ret)
		{
			if (!i)
				ft_findcoor(&vlc, vl);
			ft_getpiece(&vl);
			ft_placepiece(&vl, vlc);
		}
		 i = 1;
	}
}

int		main(void)
{
	ft_start_cond();
	return (0);
}
