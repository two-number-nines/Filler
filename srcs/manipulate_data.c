/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   manipulate_data.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/29 15:55:32 by vmulder        #+#    #+#                */
/*   Updated: 2019/05/30 19:48:44 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/filler.h"

//ft cechk horizon should be called in the while loop of ft_cutpiece and then
//check if it goes  to the end and then call replace symbol.

char	*ft_replace_sym(char *tempstr)
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
			tempstr = ft_replace_sym(tempstr);
	}
	return (tempstr);
}

void	ft_cutpiece(t_fillstr *vl)
{
	char	**tempstr;
	int		i;

	i = 0;
	tempstr = ft_strnsplit(vl->otoken, vl->tokenw);
	free(vl->otoken);
	while (tempstr[i])
	{
		ft_check_horizon(vl, tempstr[i]);
		i++;
	}
	for(int b = 0; b < 2; b++)
	{
		ft_printf("\n%s\n", tempstr[b]);
	}
}
