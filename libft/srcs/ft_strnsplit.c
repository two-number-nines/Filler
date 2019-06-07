/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnsplit.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/30 14:58:08 by vmulder        #+#    #+#                */
/*   Updated: 2019/06/07 19:03:49 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** only works correctly with stringlengths with 0 mod
*/

static void	ft_init_strnspl(int *len, int *place, int *mod, int *temp)
{
	(*place) = 0;
	(*mod) = (*temp) % (*len);
	(*temp) = (*temp) / (*len);
	if ((*mod))
		(*temp)++;
}

char		**ft_strnsplit(char *s, int len)
{
	char	**ns;
	int		temp;
	int		mod;
	int		i;
	int		place;

	i = 0;
	temp = (int)ft_strlen(s);
	ft_init_strnspl(&len, &place, &mod, &temp);
	ns = (char **)malloc(sizeof(char *) * temp); 
	while (temp)
	{
		ns[i] = ft_strnew(len);
		ft_strncpy(ns[i], &s[place], len);
		ns[i][len] = '\0';
		i++;
		temp--;
	if (!temp && mod)
		ns[i - 1][mod] = '\0';
		place += len;
	}
	return (ns);
}
