/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_field.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/07 14:08:25 by vmulder        #+#    #+#                */
/*   Updated: 2019/06/14 19:13:39 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/filler.h"

static void	ft_split(t_fillstr *vl)
{
	vl->field = ft_strnsplit(vl->ofield, vl->fldw);
	free(vl->ofield);
}

static void	ft_get_str(t_fillstr *vl)
{
	char	*tempvalue;
	int		i;

	vl->ofield = (char *)malloc(sizeof(char) * (vl->fldw * vl->fldl) + 1);
	ft_bzero(vl->ofield, (vl->fldw * vl->fldl) + 1);
	i = 1 + vl->fldl;
	while (i)
	{
		get_next_line(0, &tempvalue);
		if (tempvalue[4] == 'O' || tempvalue[4] == 'X' || tempvalue[4] == '.'
			|| tempvalue[4] == 'o' || tempvalue[4] == 'x')
			vl->ofield = ft_strcat(vl->ofield, &tempvalue[4]);
		free(tempvalue);
		i--;
	}
}

static int	ft_get_len_wid(t_fillstr *vl)
{
	char	*tempvalue;
	int		i;
	int		ret;

	i = 8;
	ret = get_next_line(0, &tempvalue);
	if (ret)
	{
		while (tempvalue[i] >= '0' && tempvalue[i] <= '9')
		{
			vl->fldl = vl->fldl * 10 + tempvalue[i] - '0';
			i++;
		}
		i++;
		while (tempvalue[i] >= '0' && tempvalue[i] <= '9')
		{
			vl->fldw = vl->fldw * 10 + tempvalue[i] - '0';
			i++;
		}
		free(tempvalue);
	}
	return (ret);
}

int			ft_getfield(t_fillstr *vl)
{
	int ret;

	ret = ft_get_len_wid(vl);
	if (ret)
	{
		ft_get_str(vl);
		ft_split(vl);
	}
	return (ret);
}
