/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checkpresicion.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/25 12:08:39 by vmulder        #+#    #+#                */
/*   Updated: 2019/05/24 15:38:59 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_checkprecisionif(t_struct *val, va_list *lp)
{
	if (val->fmt[val->i] >= '0' && val->fmt[val->i] <= '9')
		val->precis = val->precis * 10 + (val->fmt[val->i] - '0');
	else if (val->fmt[val->i] == '*')
	{
		val->precis = va_arg(*lp, int);
		if (val->precis < 0)
			val->precis = -1;
	}
}

void	ft_checkprecision(t_struct *val, va_list *lp)
{
	int a;

	a = 0;
	if (val->fmt[val->i] == '.')
	{
		val->precis = 0;
		val->i++;
		while ((val->fmt[val->i] >= '0' && val->fmt[val->i] <= '9')
			|| val->fmt[val->i] == '*')
		{
			if (a == 0)
				val->precis = 0;
			ft_checkprecisionif(val, lp);
			val->i++;
			a++;
		}
	}
}
