/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   filler.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/24 16:22:45 by vmulder        #+#    #+#                */
/*   Updated: 2019/05/27 14:56:57 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

#include "../libft/incl/libft.h"

typedef struct		s_struct
{
	int				fieldwidth;
	int				fieldlength;
	char			player;
	char			*field;
	char			*token;
	
}					t_struct;

int			main(void);

#endif