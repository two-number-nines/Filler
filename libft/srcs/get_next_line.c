/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/04 10:56:18 by vmulder        #+#    #+#                */
/*   Updated: 2019/06/08 15:36:24 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	set_the_line(char **tmp, char **line, t_gnl *all)
{
	(*all->locationnl) = '\0';
	*line = ft_strdup(*tmp);
	all->buf_leftover = ft_strdup(all->locationnl + 1);
	free(*tmp);
	*tmp = all->buf_leftover;
}

void	be_while(char **tmp, char *buf, char **free1, char **locationnl)
{
	*free1 = *tmp;
	*tmp = ft_strjoin(*tmp, buf);
	free(*free1);
	*locationnl = ft_strchr(*tmp, '\n');
}

int		before_read(char **tmp, char **line, t_gnl *all)
{
	all->locationnl = ft_strchr(*tmp, '\n');
	if ((all->locationnl && ft_strlen(*tmp) > 0))
	{
		set_the_line(tmp, line, all);
		return (1);
	}
	return (0);
}

int		read_this(char **tmp, char **line, t_gnl *all, int fd)
{
	while (all->i > 0 || **tmp != 0)
	{
		all->buf[all->i] = '\0';
		be_while(tmp, all->buf, &all->free1, &all->locationnl);
		if ((all->locationnl && ft_strlen(*tmp) > 0))
		{
			set_the_line(tmp, line, all);
			return (1);
		}
		if (!(ft_strchr(*tmp, '\n')) && all->i == 0 && ft_strlen(*tmp) > 0)
		{
			tmp[0][ft_strlen(*tmp)] = '\0';
			*line = ft_strdup(*tmp);
			*tmp = NULL;
			return (1);
		}
		all->i = read(fd, all->buf, BUFF_SIZE);
	}
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	static char		*tmp;
	t_gnl			all;

	all.i = 0;
	if (fd < 0 || line == NULL || BUFF_SIZE < 1 || read(fd, all.buf, 0) < 0)
		return (-1);
	if (!tmp)
		tmp = (char *)malloc(sizeof(char) * 1);
	if (*tmp != '\0')
		if (before_read(&tmp, line, &all) == 1)
			return (1);
	all.i = read(fd, all.buf, BUFF_SIZE);
	if (all.i == -1)
		return (-1);
	if (read_this(&tmp, line, &all, fd) == 1)
		return (1);
	tmp = NULL;
	return (0);
}
