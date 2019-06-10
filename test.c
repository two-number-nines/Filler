/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/27 14:36:15 by vmulder        #+#    #+#                */
/*   Updated: 2019/06/10 11:36:48 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include	<stdio.h>
#include	<string.h>
#include	"./libft/incl/libft.h"

int			ft_sqrt(int n)
{
		int count;
		int x;
		int i;

		printf("n: %d\n", n);
		x = 0;
		count = 0;
		i = 1;
		while (x < n)
		{
			x = x + i;
			count++;
			i += 2;
		}
		printf("count: %d\n", count);
	return (count);
}

int			ft_distance(void)
{
	int x;
	int y;
	int dist;

	x = 1;
	y = 2;
	dist = ft_sqrt(25);
	return (dist);
}

int main(void)
{
	ft_distance();
}
