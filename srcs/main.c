/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/24 16:00:51 by vmulder        #+#    #+#                */
/*   Updated: 2019/06/14 19:18:51 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/filler.h"

void	ft_write(t_fillstr vl)
{
	vl.coorsave[0] -= vl.offsetw;
	vl.coorsave[1] -= vl.offsetl;
	ft_printf("%d %d\n", vl.coorsave[1], vl.coorsave[0]);
}

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
	t_fillstr	vl;
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
				ft_findcoor_xo(&vlc, vl);
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
