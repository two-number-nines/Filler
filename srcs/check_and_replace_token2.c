/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_and_replace_token2.c                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/31 13:54:56 by vmulder        #+#    #+#                */
/*   Updated: 2019/06/03 14:46:16 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/filler.h"
#include <stdio.h>

void	ft_check_offset(t_fillstr *vl, char **tempstr)
{
	int i;
	int d;
	int a;

	i = 0;
	d = 0;
	a = -1;
	while (tempstr[i])
	{
		while (tempstr[i][d])
		{
			if (tempstr[i][d] == '*')
			{
				a = 1;
				if (vl->offseth > d || vl->offseth == -1)
					vl->offseth = d;
			}
			d++;
		}
		if (a == -1)
			vl->offsetv++;
		a = -1;
		d = 0;
		i++;
	}
	ft_printf("\noff set horizon: %d\n", vl->offseth);
	ft_printf("off set vertical: %d\n", vl->offsetv);
}

void		save_token_line(char *tempstr, t_fillstr *vl, int a)
{
	int i;
	int d;


	i = 0;
	d = 0;
	while (tempstr[i])
	{
		if (tempstr[i] == '*' || tempstr[i] == '.')
		{
			vl->token[a][d] = tempstr[i];
			d++;
		}
		i++;
	}
}
void	save_token(t_fillstr *vl, char **tempstr)
{
	int i;
	int d;
	int a;

	i = vl->offseth -1;
	d = 0;
	a = 0;
	vl->token = (char **)malloc(sizeof(char *) * vl->tokenl + 1);
	ft_bzero(vl->token, vl->tokenl + 1);
	while (tempstr[i])
	{
		vl->token[a] = (char *)malloc(sizeof(char) * vl->tokenw + 1);
		ft_bzero(vl->token[a], vl->tokenw + 1);
		save_token_line(tempstr[i], vl, a);
		i++;
		a++;
	}
	free(tempstr);
	i = vl->offseth -1;
	a = 0;
	ft_printf("\n--------------\n");
	ft_printf("the cut token:\n");
	while (i < vl->tokenl)
	{
		ft_printf("%s\n", vl->token[a]);
		i++;
		a++;
	}
}