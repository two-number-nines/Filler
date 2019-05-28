/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   filler.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/24 16:22:45 by vmulder        #+#    #+#                */
/*   Updated: 2019/05/28 16:53:45 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

#include "../libft/incl/libft.h"

/*
** field is a string with the data of the whole field
** token is the piece im going to put in
*/

typedef struct		s_fillstr
{
	char			player;

	/*
	**	variables used for the field, w = width l = length
	*/

	int				fieldw;
	int				fieldl;
	char			*field;

	/*
	** variables used for the token, w = width l = length
	*/

	int				tokenw;
	int				tokenl;
	char			*token;
	
}					t_fillstr;

int			main(void);

#endif