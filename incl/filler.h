/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   filler.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/24 16:22:45 by vmulder        #+#    #+#                */
/*   Updated: 2019/06/04 14:03:14 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "../libft/incl/libft.h"

/*
** player and comp are the char that match the player and comp
** o and x are int arrays where the starting x and y is saved
** midfield is the middle of the map
** ofield is when it is just 1d string but im changing it to a 2d field
** field is a string with the data of the whole field
** otoken is when it is just 1d string but im changing it to a 2d token
** token is the piece im going to put in
** offset is how many empty rows exist in the tokenfield
** coorsave is where i save my coor where the midfield is most close
*/

typedef struct		s_fillstr
{
	char			player;
	char			comp;

	int				o[2];
	int				x[2];
	int				midfield[2];
	
	int				fieldw;
	int				fieldl;
	char			*ofield;
	char			**field;

	int				tokenw;
	int				tokenl;
	int				offseth;
	int				offsetv;
	char			*otoken;
	char			**token;

	int				coorsave[2];

}					t_fillstr;

int					main(void);

/*
** get_data
*/

void				ft_getpiece(t_fillstr *vl);
void				ft_getfield(t_fillstr *vl);
void				ft_getplayer(t_fillstr *vl);

/*
** while_loops
*/

int					ft_whileloop_get(char *condit, int *stval, int i);
void				ft_wlp_get_sd(char **condit, char **stval, int i, int fd);

/*
** check and replace 1 and 2
*/

void				ft_cutpiece(t_fillstr *vl);
void				save_token(t_fillstr *vl, char **tempstr);
void				ft_check_offset(t_fillstr *vl, char **tempstr);

/*
**	find_xy
*/

void				ft_findcoor(t_fillstr *vl);

/*
**	return_xy
*/

void				ft_placepiece(t_fillstr *vl);

#endif
