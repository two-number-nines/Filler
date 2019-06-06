/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/24 16:00:51 by vmulder        #+#    #+#                */
/*   Updated: 2019/06/04 14:29:40 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/filler.h"

// check if ft_strsplit deletes the char c
// probable make the vl->field a 2d array and also make token a 2d array and finish the ft_cutpiece.
//replace filedescriptor 1 with 0
// waar de eerste ster linksboven bevind moet je de x y meegeven
// mag er maar 1 overlappen
// -> going to work on a check if i can place the token in a certain spot, after that make a algorithm

void	ft_init(t_fillstr *vl)
{
	ft_bzero(vl, sizeof(t_fillstr));
	vl->offseth = -1;
}

void	ft_start_cond(void)
{
	t_fillstr 	vl;
	int			i;

	i = 0;
	ft_init(&vl);
	ft_getplayer(&vl);
	// the following maybe in a while loop
	ft_getfield(&vl);
	if (!i)
	{
		ft_findcoor(&vl);
		i = 1;
	}
	ft_getpiece(&vl);
	ft_placepiece(&vl);
}

int		main(void)
{
	ft_start_cond();
	return (0);
}
