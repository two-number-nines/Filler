/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_piece.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/07 19:06:09 by vmulder        #+#    #+#                */
/*   Updated: 2019/06/07 19:21:56 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/filler.h"

int globalfd;

static void	ft_split(t_fillstr *vl)
{
	int i;

	i = 0;
	vl->token = ft_strnsplit(vl->otoken, vl->tokenw);
	while (i < vl->tokenl)
	{
		ft_printf("%s\n", vl->token[i]);
		i++;
	}
	free(vl->otoken);
}

static void		ft_get_str(t_fillstr *vl)
{
	char	*tempvalue;
	int		i;
	
	vl->otoken = (char *)malloc(sizeof(char) * (vl->tokenw * vl->tokenl) + 1);
	ft_bzero(vl->otoken, (vl->tokenw * vl->tokenl) + 1);
	i = vl->tokenl;
	while (i)
	{
		get_next_line(globalfd, &tempvalue);
		vl->otoken = ft_strcat(vl->otoken, tempvalue);
		free(tempvalue);
		i--;
	}
	ft_printf("fieldstr: %s\n", vl->otoken);
	ft_printf("strlen: %d\n", ft_strlen(vl->otoken));
}

static void		ft_get_len_wid(t_fillstr *vl)
{
	char	*tempvalue;
	int		i;

	i = 6;
	get_next_line(globalfd, &tempvalue);
	while (tempvalue[i] >= '0' && tempvalue[i] <= '9')
	{
		vl->tokenl = vl->tokenl * 10 + tempvalue[i] - '0';
		i++;
	}
	i++;
	while (tempvalue[i] >= '0' && tempvalue[i] <= '9')
	{
		vl->tokenw = vl->tokenw * 10 + tempvalue[i] - '0';
		i++;
	}
	free(tempvalue);
	ft_printf("tl: %d\ntw: %d\n", vl->tokenl, vl->tokenw);
}

void			ft_getpiece(t_fillstr *vl)
{
	ft_get_len_wid(vl);
	ft_get_str(vl);
	ft_split(vl);
//	ft_cutpiece(vl);
}