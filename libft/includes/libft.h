/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 23:17:45 by qle-bevi          #+#    #+#             */
/*   Updated: 2017/04/30 21:12:07 by qle-bevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define BOOL char
# define TRUE 1
# define FALSE 0
# include <string.h>
# include <wchar.h>

/*
****  IS
*/
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isescaped(int c);
int				ft_isprint(int c);
/*
****  MEMORY
*/
void			*ft_memalloc(size_t size);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memdel(void **ap);
void			*ft_memset(void *dest, int c, size_t n);
void			ft_bzero(void *s, size_t n);
void			ft_free_str_array(char ***array);

/*
****  STRINGS
*/
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strchr(const char *s, int c);
void			ft_strclr(char *s);
int				ft_strcmp (const char *s1, const char *s2);
char			*ft_strcpy(char *dst, const char *src);
int				ft_strequ(const char *s1, const char *s2);
char			*ft_strncpy(char *dst, const char *src, size_t n);
int				ft_strncmp (const char *s1, const char *s2, size_t n);
char			*ft_strdup(const char *s1);
char			*ft_strredup(char *orig, char *str);
int				ft_strnequ(const char *s1, const char *s2, size_t n);
char			*ft_strrchr(const char *s, int c);
char			*ft_strncat(char *s1, const char *s2, size_t n);
size_t			ft_strlcat(char *dest, const char *src, size_t size);
char			*ft_strmap(const char *s, char (*f)(char));
char			*ft_strnew(size_t size);
void			ft_strdel(char **as);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_pushchar(char *s, char c);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			*ft_strnstr(const char *s1, const char *s2, size_t n);
size_t			ft_strlen(const char *s);
char			*ft_strstr(const char *s1, const char *s2);
int				ft_countwords(const char *s1, char c);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			**ft_strsplit(char const *s, char c);
char			**ft_strsplitif(char const *s, BOOL (*f)(char));
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strrejoin(char *orig, char *s1, char *s2);
char			*ft_jointab(char **array);
char			*ft_jointab_sep(char **array, char *sep);
char			*ft_strtrim(const char *s);
char			*ft_str_replace(char *s1, char *pattern, char *s2, int free_s1);
/*
****  PUT
*/
void			ft_putnbr(int n);
void			ft_putnbr_fd(int n, int fd);
void			ft_putchar(char c);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr(char const *s);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl(char const *s);
void			ft_putendl_fd(char const *s, int fd);
void			ft_puttab(char **tbl);
void			ft_putstr_color(char *str, int color);
int				ft_putwchar(wchar_t c);
void			ft_putwstr(wchar_t const *str);
/*
****  TO
*/
int				ft_tolower(int c);
int				ft_toupper(int c);
/*
****  OTHER
*/
void			ft_errexit(int code, char *str);
void			ft_free_tab(char ***s);
void			ft_freetab(void **arr);
void			ft_rfreetab(void ***arr);
int				ft_atoi(const char *str);
int				ft_getdecade(int nb);
char			*ft_itoa(int n);
int				ft_pow(int nb, int power);
int				ft_tablen(char **tabl);
/*
**** T_LIST
*/
typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;
t_list			*ft_lstnew(void const *content, size_t content_size);
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
t_list			*ft_lstadd(t_list **alst, t_list *new);
t_list			*ft_lstpop(t_list **alst);
t_list			*ft_lstpush(t_list **begin, void const *content, size_t size);
t_list			*ft_lstpush2(t_list **begin, t_list *new);
int				ft_lstsort(t_list **begin, BOOL (*cmp)(void *a, void *b));
t_list			*ft_lstrev(t_list **begin);
int				ft_lstsize(t_list *list);
void			ft_lstiter(t_list *list, void (*f)(t_list *elem));
void			ft_lstiter2(t_list *list, void (*f)(void *elem));
void			ft_lstiter3(t_list *list, void *ptr,
void (*f)(void *ptr, t_list *elem));
t_list			*ft_lstselect(t_list *list, BOOL (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
BOOL			ft_lstgot(t_list *list, t_list *elem);
#endif
