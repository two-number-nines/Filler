/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   while_loops.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/29 14:19:54 by vmulder        #+#    #+#                */
/*   Updated: 2019/05/29 14:20:23 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/filler.h"

int		ft_whileloop_get(char *condition, int *stval, int i)
{
	while (condition[i] >= '0' && condition[i] <= '9')
	{
		(*stval) = (*stval) * 10 + condition[i] - '0';
		i++;
	}
	return (i);
}
