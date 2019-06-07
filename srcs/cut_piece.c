/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cut_piece.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/29 15:55:32 by vmulder        #+#    #+#                */
/*   Updated: 2019/06/07 22:27:14 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/filler.h"

//ft cechk horizon should be called in the while loop of ft_cutpiece and then
//check if it goes  to the end and then call replace symbol.
// void	ft_check_offset(t_fillstr *vl)

void	ft_replace_sym_w(char **tempstr)
{
	int i;

	i = 0;
	while ((*tempstr)[i])
	{
		(*tempstr)[i] = '!';
		i++;
	}
}

void	ft_replace_sym_l(char ***tempstr, int d, int tokenl)
{
	int i;

	i = 0;
	while (i < tokenl)
	{
		(*tempstr)[i][d] = '!';
		i++;
	}
}

void	ft_check_l(t_fillstr *vl)
{
	int i;
	int d;
	int c;

	i = 0;
	d = 0;
	c = 0;
	while (d < vl->tokenw)
	{
		while (i < vl->tokenl)
		{
			if (vl->token[i][d] == '*')
				c = 1;
			i++;
		}
		if (c == 0)
			ft_replace_sym_l(&vl->token, d, vl->tokenl);
		c = 0;
		i = 0;
		d++;
	}
}

void	ft_check_w(t_fillstr *vl)
{
	int i;
	int d;
	int c;

	i = 0;
	d = 0;
	c = 0;
	while (i < vl->tokenl)
	{
		while (d < vl->tokenw)
		{
			if (vl->token[i][d] == '*')
				c = 1;
			d++;
		}
		if (c == 0)
			ft_replace_sym_w(&vl->token[i]);
		c = 0;
		d = 0;
		i++;
	}
}

void			ft_cutpiece(t_fillstr *vl)
{
	int i;

	i = 0;
	ft_check_w(vl);
	ft_check_l(vl);
	new_token(vl);

	while (i < vl->tokenl)
	{
		ft_printf("%s\n", vl->token[i]);
		i++;
	}
}