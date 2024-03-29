/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aollero- <aollero@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 15:12:34 by aollero-          #+#    #+#             */
/*   Updated: 2020/10/12 18:30:08 by aollero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <mlx.h>
# include <math.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <errno.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2048
# endif
# ifndef MAX_FD
#  define MAX_FD 512
# endif

typedef u_char	t_byte;

enum			e_types{
	e_char = 0,
	e_int = 1,
	e_float = 2,
	e_void = 3,
	e_ptr = 4,
	e_uchar = 5,
	e_uint = 6,
	e_sint = 7,
	e_suint = 8,
	e_lint = 9,
	e_luint = 10,
	e_dbl = 11,
	e_ldbl = 12
};

typedef struct	s_array {
	enum e_types	type;
	size_t			usz;
	size_t			m;
	size_t			n;
	void			*cset;
	size_t			setsz;
}				t_array;

typedef	struct	s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

void			*ft_memset(void *s, int c, size_t n);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memccpy(void *dest, const void *src, int c, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
size_t			ft_strlen(const char *s);
size_t			ft_strlcpy(char *dst, const char *src, size_t size);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strnstr(const char *big, const char *little, size_t len);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_atoi(const char *nptr);
int				ft_atoi_adv(char **nptr);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_isspace(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);
void			adv_spaces(char **str);
void			*ft_calloc(size_t nmemb, size_t size);
char			*ft_strdup(const char *s);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strjoin_ult(ssize_t sz, char const **strs, const char *sep);
char			*ft_strtrim(char const *s1, char const *set);
char			**ft_split(char const *s, char c);
char			**ft_split_ultimate(char const *s, char *charset);
char			*ft_itoa(int n);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
t_list			*ft_lstnew(void *content);
void			ft_lstadd_front(t_list **lst, t_list *new);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstdelone(t_list *lst, void (*delcnt)(void*),
							void (*delnde)(void*));
void			ft_lstclear(t_list **lst, void (*delcnt)(void*),
							void (*delnde)(void*));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*delcnt)(void *), void (*delnde)(void *));
int				get_next_line(int fd, char **line);
void			ft_lstdelmany(t_list **lst, int (*comp)(), void (*del)(void *),
													void *param);
void			**ft_lsttoarr(t_list *list, int *size);
t_list			*ft_arrtolst(void **array, int size, void *(*alloc)());
int				ft_findptrinarray(void **array, void *key, int size);
int				ft_lstcullpat(t_list **list, int *mask, void (*delcnt)(void *),
								void (*delnde)(void *));
int				ft_lstdeldup(t_list **list, void (*delnde)(void *));
void			*my_alloc(void *param);
void			**my2alloc(void **param, int size);
void			my_free(void *ptr);
void			my_exit(char *error, int errnbr);
void			ptrlstclear(void);
void			*my_malloc(size_t size);
void			*my_mlx(void *ptr);
t_array			*alloc_matrix(size_t m, size_t n, enum e_types tpe, t_byte *st);
void			ft_wrtptr(char *c, char *str);
void			*elem(t_array *array, size_t i, size_t j);
void			*ft_arrbyte(t_array *a, void *key);
void			rotvect2(double *vector[2], double len, double angle);

#endif
