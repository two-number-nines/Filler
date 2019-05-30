/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   filler.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/24 16:22:45 by vmulder        #+#    #+#                */
/*   Updated: 2019/05/29 14:50:44 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "../libft/incl/libft.h"

/*
** field is a string with the data of the whole field
** token is the piece im going to put in
*/

typedef struct		s_fillstr
{
	char			player;

	int				fieldw;
	int				fieldl;
	char			*field;

	int				tokenw;
	int				tokenl;
	char			*token;

}					t_fillstr;

int					main(void);

/*
** get_data.c
*/

void				ft_getpiece(t_fillstr *vl);
void				ft_getfield(t_fillstr *vl);
void				ft_getplayer(t_fillstr *vl);

/*
** while_loops.c
*/

int					ft_whileloop_get(char *condit, int *stval, int i);
void				ft_wlp_get_sd(char **condit, char **stval, int i, int fd);

#endif
