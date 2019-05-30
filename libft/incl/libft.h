/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libft.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/12 18:22:41 by vmulder        #+#    #+#                */
/*   Updated: 2019/05/30 15:00:16 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>
# include <fcntl.h>

# define BUFF_FULL 9999
# define BUFF_SIZE 20

typedef struct		s_gnl
{
	char			buf[BUFF_SIZE + 1];
	char			*locationnl;
	char			*buf_leftover;
	char			*free1;
	int				i;
}					t_gnl;

typedef struct		s_struct {
	double			f;
	signed long		d;
	unsigned long	ud;
	int				tmpi;
	int				flagmin;
	int				flagplus;
	int				flagspace;
	int				flaghasj;
	int				flagnull;
	int				bi;
	int				i;
	const char		*fmt;
	int				width;
	int				precis;
	int				length;
	int				hh;
	int				h;
	int				l;
	int				ll;
	int				cl;
	char			specifier;
	char			buf[10000];
	int				ret;
	int				tc;
}					t_struct;

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

/*
** gnl
*/

int					get_next_line(const int fd, char **line);

/*
** libft
*/

void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putnbr(int nbr);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr(char const *s);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
int					ft_strequ(char const *s1, char const *s2);
int					ft_isdigit(int c);
int					ft_tolower(int c);
int					ft_toupper(int c);
size_t				ft_strlen(const char *s);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strdup(const char *s1);
int					ft_atoi(const char *str);
int					ft_isprint(int c);
int					ft_isascii(int c);
int					ft_isalpha(int c);
int					ft_isalnum(int c);
void				ft_bzero(void *s, size_t n);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
void				ft_strclr(char *s);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
void				*ft_memset(void *b, int c, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strtrim(char const *s);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				*ft_memalloc(size_t size);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
char				*ft_strnstr(const char *hay, const char *nee, size_t len);
char				*ft_itoa(long long n);
int					ft_getdigits(long long c);
char				**ft_strsplit(char const *s, char c);
char				**ft_strnsplit(char *s, int len);
void				ft_strdel(char **as);
char				*ft_strnew(size_t size);
void				ft_memdel(void **ap);
int					ft_skipwhite(const char *str, int i);
char				*ft_strrev(char *str);
int					ft_islower(int c);
int					ft_isupper(int c);
int					ft_atoi_base(const char *str, int base);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
char				*ft_itoa_base_u(unsigned long long n, int base, int q);
char				*ft_itoa_base(long long n, int base, int q);
int					ft_getdigits_u(unsigned long long c);

/*
**		printf
*/

int					ft_printf(const char *format, ...);
void				ft_checkflags(t_struct *val);
void				ft_checkwidth(t_struct *val, va_list *lp);
void				ft_checkprecision(t_struct *val, va_list *lp);
void				ft_checklenmod(t_struct *val);
void				ft_checkspecifier(t_struct *val, va_list *lp);
void				ft_converter_c(t_struct *val, va_list *lp);
void				ft_converter_s(t_struct *val, va_list *lp);
void				ft_converter_p(t_struct *val, va_list *lp);
void				ft_converter_di(t_struct *val, va_list *lp);
void				ft_converter_uox(t_struct *val, va_list *lp);
void				ft_converter_f(t_struct *val, va_list *lp);
void				ft_converter_perc(t_struct *val);
void				ft_cpy_to_buf(t_struct *val, char *s);
void				ft_cpy_to_buf_lft(t_struct *val, char *s);
void				put_width_buf(t_struct *val);
char				*long_to_a_string(long long l);
void				ft_cpy_to_buf_lft_int(t_struct *val);
void				ft_cpy_to_buf_int(t_struct *val);
int					ft_supersayenbased(t_struct *val);
void				ft_cpy_to_buf_lft_int_u(t_struct *val);
void				ft_cpy_to_buf_int_u(t_struct *val);
void				ft_cpy_to_buf_lft_int_f(t_struct *val);
void				ft_cpy_to_buf_int_f(t_struct *val);
void				reset_flags(t_struct *val);
void				ft_clearbuf(t_struct *val);
void				ft_while_loop(t_struct *val, char *ns);
void				while_loop_pr(int *tp, char **ns, int *i, char **s);
void				while_lp_f(t_struct *val, char **ns, char *sr, int *i);
void				while_lp_pr_neg(int *tp, char **ns, int *i, char **s);

#endif
