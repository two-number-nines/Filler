/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_and_replace_token2.c                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/31 13:54:56 by vmulder        #+#    #+#                */
/*   Updated: 2019/05/31 15:19:16 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/filler.h"

void	save_token_line(char *tempstr, t_fillstr *vl, int a)
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

	i = 0;
	d = 0;
	vl->token = (char **)malloc(sizeof(char *) * vl->tokenl + 1);
	ft_bzero(vl->token, vl->tokenl + 1);
	while (tempstr[i])
	{
		vl->token[i] = (char *)malloc(sizeof(char) * vl->tokenw + 1);
		ft_bzero(vl->token[i], vl->tokenw + 1);
		save_token_line(tempstr[i], vl, i);
		i++;
	}
	free(tempstr);
	i = 0;
	ft_printf("\n--------------\n");
	while (i < vl->tokenl)
	{
		ft_printf("%s\n", vl->token[i]);
		i++;
	}
}