/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/24 16:00:51 by vmulder        #+#    #+#                */
/*   Updated: 2019/05/28 17:05:54 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/filler.h"

int globalfd;
// check if ft_strsplit deletes the char c
// probable make the vl->field a 2d array and also make token a 2d array and finish the ft_cutpiece.
//replace filedescriptor 1 with 0

void	ft_cutpiece(t_fillstr *vl)
{
	ft_strsplit(vl->token, '\n');
}

int		ft_whileloop_get(char *condition, int *stval, int i)
{
	while (condition[i] >= '0' && condition[i] <= '9')
	{
		(*stval) = (*stval) * 10 + condition[i] - '0';
		i++;
	}
}

void	ft_getpiece(t_fillstr *vl)
{
	char	*tempvalue;
	char	*temptoken;
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

void	ft_player(t_fillstr *vl)
{
	char		*playerstring;

	globalfd = open("input.txt", O_RDONLY);
	get_next_line(globalfd, &playerstring);
	if (playerstring[10] == '1')
		vl->player = 'O';
	else
		vl->player = 'X';
}

void	ft_init(t_fillstr *vl)
{
	ft_bzero(vl, sizeof(t_fillstr));
}

void	ft_start_cond(void)
{
	t_fillstr vl;

	ft_init(&vl);
	ft_player(&vl);
	ft_getfield(&vl);
	ft_getpiece(&vl);
//	ft_cutpiece(&vl);
}

int		main(void)
{
	ft_start_cond();
	return (0);
}
