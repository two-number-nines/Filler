/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_field.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/07 14:08:25 by vmulder        #+#    #+#                */
/*   Updated: 2019/06/07 19:14:47 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/filler.h"

int globalfd;

/*
** i is the index to check the line, it will give back te fieldl and the fieldw
** then 
*/

void	ft_split(t_fillstr *vl)
{
	int i;

	i = 0;
	vl->field = ft_strnsplit(vl->ofield, vl->fieldw);
	while (i < vl->fieldl)
	{
		ft_printf("%s\n", vl->field[i]);
		i++;
	}
	free(vl->ofield);
}

void	ft_get_str(t_fillstr *vl)
{
	char	*tempvalue;
	int		i;
	
	vl->ofield = (char *)malloc(sizeof(char)* (vl->fieldw * vl->fieldl) + 1);
	ft_bzero(vl->ofield, (vl->fieldw * vl->fieldl) + 1);
	i = 1 + vl->fieldl;
	while (i)
	{
		get_next_line(globalfd, &tempvalue);
		if (tempvalue[4] == 'O' ||  tempvalue[4] == 'X' || tempvalue[4] == '.')
			vl->ofield = ft_strcat(vl->ofield, &tempvalue[4]);
		free(tempvalue);
		i--;
	}
	ft_printf("fieldstr: %s\n", vl->ofield);
	ft_printf("strlen: %d\n", ft_strlen(vl->ofield));
}

static void	ft_get_len_wid(t_fillstr *vl)
{
	char	*tempvalue;
	int		i;

	i = 8;

	get_next_line(globalfd, &tempvalue);
	while (tempvalue[i] >= '0' && tempvalue[i] <= '9')
	{
		vl->fieldl = vl->fieldl * 10 + tempvalue[i] - '0';
		i++;
	}
	i++;
	while (tempvalue[i] >= '0' && tempvalue[i] <= '9')
	{
		vl->fieldw = vl->fieldw * 10 + tempvalue[i] - '0';
		i++;
	}
	free(tempvalue);
	ft_printf("fl: %d\nfw: %d\n", vl->fieldl, vl->fieldw);
}

void	ft_getfield(t_fillstr *vl)
{
	ft_get_len_wid(vl);
	ft_get_str(vl);
	ft_split(vl);
}