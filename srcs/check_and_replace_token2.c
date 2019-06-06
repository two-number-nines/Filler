/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_and_replace_token2.c                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/31 13:54:56 by vmulder        #+#    #+#                */
/*   Updated: 2019/06/06 19:25:42 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/filler.h"
#include <stdio.h>

void	ft_check_offset(t_fillstr *vl, char **tempstr)
{
	int i;
	int d;
	int a;
	int e;

	i = 0;
	d = 0;
	a = -1;
	e = 0;
	while (tempstr[i])
	{
		while (tempstr[i][d])
		{
			if (tempstr[i][d] == '*')
			{
				e = 1;
				a = 1;
				if (vl->offseth > d || vl->offseth == -1)
					vl->offseth = d;
			}
			d++;
		}
		if (a == -1)
			vl->offsetv++;
		if (!e)
			vl->offsetva++;
			a = -1;
		d = 0;
		i++;
	}
	ft_printf("\noff set horizon: %d\n", vl->offseth);
	ft_printf("off set vertical: %d\n", vl->offsetv);
}

int		save_token_line(char *tempstr, t_fillstr *vl, int a)
{
	int i;
	int d;
	int ret;


	i = 0;
	d = 0;
	ret = 0;
	while (tempstr[i])
	{
		if (tempstr[i] == '*' || tempstr[i] == '.')
		{
			vl->token[a][d] = tempstr[i];
			ret = 1;
			d++;
		}
		i++;
	}
	return (ret);
}
void	save_token(t_fillstr *vl, char **tempstr)
{
	int i;
	int d;
	int a;

	i = 0;
	d = 0;
	a = 0;
	vl->token = (char **)malloc(sizeof(char *) * vl->tokenl + 1);
	ft_bzero(vl->token, vl->tokenl + 1);
	while (tempstr[i])
	{
		vl->token[a] = (char *)malloc(sizeof(char) * vl->tokenw + 1);
		ft_bzero(vl->token[a], vl->tokenw + 1);
		if (save_token_line(tempstr[i], vl, a))
			a++;
		i++;
	}
	free(tempstr);
	a = 0;
	ft_printf("\n--------------\n");
	ft_printf("the cut token:\n");
	while (a < 3)
	{
		ft_printf("%s\n", vl->token[a]);
		a++;
	}
}
