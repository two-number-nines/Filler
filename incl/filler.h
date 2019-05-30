/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   filler.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/24 16:22:45 by vmulder        #+#    #+#                */
/*   Updated: 2019/05/30 19:39:51 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "../libft/incl/libft.h"

/*
** field is a string with the data of the whole field
** token is the piece im going to put in
** o field is when it is just 1d string but im changing it to a 2d field
*/

typedef struct		s_fillstr
{
	char			player;

	int				fieldw;
	int				fieldl;
	char			*ofield;
	char			**field;

	int				tokenw;
	int				tokenl;
	char			*otoken;
	char			**token;

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

/*
** manipulate_data.c
*/

void				ft_cutpiece(t_fillstr *vl);

#endif
