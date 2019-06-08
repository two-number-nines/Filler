/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnsplit.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/30 14:58:08 by vmulder        #+#    #+#                */
/*   Updated: 2019/06/08 16:03:17 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** only works correctly with stringlengths that can be exactly divided.
*/

static void	ft_init_strnspl(int *len, int *place, int *temp)
{
	(*place) = 0;
	if ((*temp) != 0 && (*len) != 0)
		(*temp) = (*temp) / (*len);
}

char		**ft_strnsplit(char *s, int len)
{
	char	**ns;
	int		temp;
	int		i;
	int		place;

	i = 0;
	temp = (int)ft_strlen(s);
	ft_init_strnspl(&len, &place, &temp);
	ns = (char **)malloc(sizeof(char *) * temp); 
	while (temp)
	{
		ns[i] = ft_strnew(len);
		ft_strncpy(ns[i], &s[place], len);
		ns[i][len] = '\0';
		place += len;
		i++;
		temp--;
	}
	return (ns);
}
