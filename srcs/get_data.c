/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_data.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/29 14:21:58 by vmulder        #+#    #+#                */
/*   Updated: 2019/05/29 14:27:20 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/filler.h"

int globalfd;

void	ft_getpiece(t_fillstr *vl)
{
	char	*tempvalue;
	char	*temptoken;
	int		i;

	i = 6;
	get_next_line(globalfd, &tempvalue);
	i = ft_whileloop_get(tempvalue, &vl->tokenl, i);
	i++;
	i = ft_whileloop_get(tempvalue, &vl->tokenw, i);
	vl->token = (char *)malloc(sizeof(char) * (vl->tokenw + 1) * vl->tokenl);
	ft_bzero(vl->token, (vl->tokenw + 1) * vl->tokenl);
	i = vl->tokenl;
	while (i)
	{
		get_next_line(globalfd, &temptoken);
		vl->token = ft_strcat(vl->token, temptoken);
		i--;
	}
	free(tempvalue);
	free(temptoken);
}

void	ft_getfield(t_fillstr *vl)
{
	char	*tempvalue;
	char	*tempfield;
	int		i;

	i = 8;
	get_next_line(globalfd, &tempvalue);
	i = ft_whileloop_get(tempvalue, &vl->fieldl, i);
	i++;
	i = ft_whileloop_get(tempvalue, &vl->fieldw, i);
	vl->field = (char *)malloc(sizeof(char) * (vl->fieldw + 5) * vl->fieldl);
	ft_bzero(vl->field, (vl->fieldw + 5) * vl->fieldl);
	i = 1 + vl->fieldl;
	while (i)
	{
		get_next_line(globalfd, &tempfield);
		if (tempfield[0] >= '0' && tempfield[0] <= '9')
			vl->field = ft_strcat(vl->field, tempfield);
		i--;
	}
	free(tempvalue);
	free(tempfield);
}

void	ft_getplayer(t_fillstr *vl)
{
	char		*playerstring;

	globalfd = open("input.txt", O_RDONLY);
	get_next_line(globalfd, &playerstring);
	if (playerstring[10] == '1')
		vl->player = 'O';
	else
		vl->player = 'X';
}
