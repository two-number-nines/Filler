/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   while_loops.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/29 14:19:54 by vmulder        #+#    #+#                */
/*   Updated: 2019/06/07 14:08:09 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/filler.h"

/*
** stval is the structvalue im changing within the whileloops.
** ft_whileloop_get is for the integer values.
** ft_wlp_get_sd is for strings that gnl just gets and concats them in 1 str.
*/

int		ft_whileloop_get(char *condit, int *stval, int i)
{
	while (condit[i] >= '0' && condit[i] <= '9')
	{
		(*stval) = (*stval) * 10 + condit[i] - '0';
		i++;
	}
	return (i);
}

void	ft_wlp_get_sd(char **condit, char **stval, int i, int ifs)
{
	while (i)
	{
		get_next_line(fd, condit);
		if (ifs)
		{
			if ((*condit)[0] >= '0' && (*condit)[0] <= '9')
				(*stval) = ft_strcat((*stval), (*condit));
		}
		else
			(*stval) = ft_strcat((*stval), (*condit));
		i--;
	}
}
