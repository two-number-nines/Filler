/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   filler.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/24 16:22:45 by vmulder        #+#    #+#                */
/*   Updated: 2019/06/11 16:43:27 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "../libft/incl/libft.h"
# include <stdio.h>

/*
** player and comp are the char that match the player and comp
** o and x are int arrays where the starting x and y is saved
** midfield is the middle of the map
** ofield is when it is just 1d string but im changing it to a 2d field
** field is a string with the data of the whole field
** otoken is when it is just 1d string but im changing it to a 2d token
** token is the piece im going to put in
** offset is how many empty rows exist in the tokenfield va is above the first *
** coorsave is where i save my coor where the midfield is most close
*/

typedef struct		s_fillstr
{
	int				fieldw;
	int				fieldl;
	char			*ofield;
	char			**field;

	int				tokenw;
	int				tokenl;
	int				offsetw;
	int				offsetl;
	char			*otoken;
	char			**token;
	char			**ntoken;

	int				coorsave[2];
	int				mostx;
	int				distance;
}					t_fillstr;

typedef struct		s_coor
{
	char			player;
	char			comp;

	int				playc[2];
	int				compc[2];
	int				el[2];

}					t_coor;

int					main(void);

/*
** get_data
*/

void				ft_getpiece(t_fillstr *vl);
int					ft_getfield(t_fillstr *vl);
void				ft_getplayer(t_coor *vl);

/*
** while_loops
*/

int					ft_whileloop_get(char *condit, int *stval, int i);
void				ft_wlp_get_sd(char **condit, char **stval, int i, int fd);

/*
** check and replace 1 and 2
*/

void				ft_check_offset_l(t_fillstr *vl);
void				ft_check_offset_w(t_fillstr *vl);
void				ft_cutpiece(t_fillstr *vl);
void				new_token(t_fillstr *vl);

/*
**	find_xy
*/

void		ft_findcoor(t_coor *vlc, t_fillstr vl);

/*
**	return_xy
*/

void				ft_placepiece(t_fillstr *vl, t_coor vlc);
void				calc_and_save_coor_enemy(t_fillstr *vl, t_coor vlc, int i, int d);
void				calc_and_save_coor_mf(t_fillstr *vl, t_coor vlc, int i, int d);

/*
** write_coor
*/

void				ft_write(t_fillstr vl);

/*
** go_right
*/

void	calc_and_save_coor_gr(t_fillstr *vl, int i, int d);
void		ft_latest_x(t_fillstr *vl, t_coor *vlc);

int			ft_distance(int *enemy, int *tokencoor);

/*
**	check_walls
*/

int		ft_check_ceiling(t_fillstr *vl, t_coor vlc);
int		ft_check_leftwall(t_fillstr *vl, t_coor vlc);
int		ft_check_rightwall(t_fillstr *vl, t_coor vlc);
int		ft_check_bottom(t_fillstr *vl, t_coor vlc);

/*
**	go walls
*/

int		calc_and_go_wall(t_fillstr *vl, t_coor vlc, int i, int d);

#endif
