/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/27 14:36:15 by vmulder        #+#    #+#                */
/*   Updated: 2019/05/27 14:56:42 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		main(void)
{
	char *temp = "12 121";
	int i = 0;
	int boardlines = 0;
	int board = 0;
	while(temp[i] >= '0' && temp[i] <= '9')
	{
		boardlines = boardlines * 10 + temp[i] - '0';
		i++;
	}
	i++;
	while(temp[i] >= '0' && temp[i] <= '9')
	{
		board = board * 10 + temp[i] - '0';
		i++;
	}
	printf("%d", board);
}
