/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnsplit.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/30 14:58:08 by vmulder        #+#    #+#                */
/*   Updated: 2019/05/30 15:00:03 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_init_strnspl(int *len, int *place, int *mod, int *temp)
{
	(*place) = 0;
	(*mod) = (*temp) % (*len);
	if ((*mod))
		(*temp)++;
	(*temp) = (*temp) / (*len);
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
	ns = (char **)malloc(sizeof(char *) * temp + 1);
	while (temp)
	{
		ns[i] = ft_strnew(len + 1);
		ft_strncpy(ns[i], &s[place], len);
		ns[i][len + 1] = '\0';
		i++;
		temp--;
		if (!temp && mod)
			ns[i - 1][mod] = '\0';
		place += len;
	}
	ns[i] = NULL;
	return (ns);
}
