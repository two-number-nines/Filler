/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/24 16:00:51 by vmulder        #+#    #+#                */
/*   Updated: 2019/05/27 14:54:55 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/filler.h"

ft_getpiece(t_struct *vl)
{
	char	*temp;

	while (get_next_line(0, &temp) == 1)
	{
		if (temp[0] >= '.')
			vl->token = ft_strjoin(vl->token, temp);
	}
}

void	ft_getfield(t_struct *vl)
{
	char	*temp;
	int		i;

	i = 8;
	get_next_line(0, &temp);
	while(temp[i] >= '0' && temp[i] <= '9')
	{
		vl->fieldlength = vl->fieldlength * 10 + temp[i] - '0';
		i++;
	}
	i++;
	while(temp[i] >= '0' && temp[i] <= '9')
	{
		vl->fieldwidth = vl->fieldwidth * 10 + temp[i] - '0';
		i++;
	}
	i = 1 + vl->fieldlength;
	while (i)
	{
		if (temp[0] >= '0' && temp[0] <= '9')
			vl->field = ft_strjoin(vl->field, temp);
	}
}

void	ft_player(t_struct *vl)
{
	char		*playerstring;
	int			linenbr;

	get_next_line(0, &playerstring);
	if (playerstring[10] == '1')
		vl->player = 'O';
	else
		vl->player = 'X';
}

void	ft_start_cond(void)
{
	t_struct vl;

	ft_player(&vl);
	ft_getfield(&vl);
	ft_getpiece(&vl);
}

int		main(void)
{
	ft_start_cond();
	return (0);
}
