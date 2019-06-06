/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_data.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/29 14:21:58 by vmulder        #+#    #+#                */
/*   Updated: 2019/06/04 14:32:33 by vmulder       ########   odam.nl         */
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
	vl->otoken = (char *)malloc(sizeof(char) * (vl->tokenw + 1) * vl->tokenl);
	ft_bzero(vl->otoken, (vl->tokenw + 1) * vl->tokenl);
	i = vl->tokenl;
	ft_wlp_get_sd(&temptoken, &vl->otoken, i, 0);
	ft_printf("\ntokenlength: %d", vl->tokenl);
	ft_printf("\ntokenwidth: %d", vl->tokenw);
	ft_printf("\nthe token: %s", vl->otoken);
	free(tempvalue);
	free(temptoken);
	ft_cutpiece(vl);
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
	vl->ofield = (char *)malloc(sizeof(char) * (vl->fieldw + 5) * vl->fieldl);
	ft_bzero(vl->ofield, (vl->fieldw + 5) * vl->fieldl);
	i = 1 + vl->fieldl;
	ft_wlp_get_sd(&tempfield, &vl->ofield, i, 1);
	ft_printf("the field: %s", vl->ofield);
	free(tempvalue);
	free(tempfield);
	vl->field = ft_strnsplit(vl->ofield, vl->fieldw + 4);
}

void	ft_getplayer(t_fillstr *vl)
{
	char		*playerstring;

	globalfd = open("input.txt", O_RDONLY);
	get_next_line(globalfd, &playerstring);
	if (playerstring[10] == '1')
	{
		vl->player = 'O';
		vl->comp = 'X';
	}
	else
	{
		vl->player = 'X';
		vl->comp = 'O';
	}
	ft_printf("the player: %c\nthe comp: %c\n", vl->player, vl->comp);
}
