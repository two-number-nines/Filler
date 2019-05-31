/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_and_replace_token.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/29 15:55:32 by vmulder        #+#    #+#                */
/*   Updated: 2019/05/31 15:30:01 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/filler.h"

//ft cechk horizon should be called in the while loop of ft_cutpiece and then
//check if it goes  to the end and then call replace symbol.

char	*ft_replace_sym_hor(char *tempstr)
{
	int i;

	i = 0;
	while (tempstr[i])
	{
		tempstr[i] = '!';
		i++;
	}
	return (tempstr);
}

char	**ft_replace_sym_ver(char **tempstr, int b, int d)
{
	int i;

	i = 0;
	while (i < d)
	{
		tempstr[i][b] = '!';
		i++;
	}
	return (tempstr);
}

char	*ft_check_horizon(t_fillstr *vl, char *tempstr)
{
	int i;
	
	i = 0;
	while (tempstr[i])
	{
		if (tempstr[i] == '*')
			break ;
		i++;
		if (i == vl->tokenw)
			tempstr = ft_replace_sym_hor(tempstr);
	}
	return (tempstr);
}

char	**ft_check_vertical(t_fillstr *vl, char **tempstr)
{
	int i;
	int	b;
	int d;
	
	i = 0;
	b = 0;
	d = vl->tokenl;
	while (b <= d)
	{
		while (i <= vl->tokenw)
		{
			if (i < d && tempstr[i][b] == '*')
			{
				i = -1;
				b++;
			}
			i++;
		}
		if (i == d)
			tempstr = ft_replace_sym_ver(tempstr, b, d);
		i = 0;
		b++;
	}
	return (tempstr);
}

void	ft_cutpiece(t_fillstr *vl)
{
	char	**tempstr;
	int		i;
	int		b;

	b = 0;
	i = 0;
	tempstr = ft_strnsplit(vl->otoken, vl->tokenw);
	free(vl->otoken);
	while (tempstr[i])
	{
		ft_check_horizon(vl, tempstr[i]);
		i++;
	}
	ft_check_vertical(vl, tempstr);
	save_token(vl, tempstr);
}
