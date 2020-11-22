/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rokupin <rokupin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 14:39:45 by rokupin           #+#    #+#             */
/*   Updated: 2019/12/22 14:01:33 by rokupin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stddef.h>

/*
** math
*/
char			*ft_convert_base(char *nbr, char *base_from, char *base_to);
/*
** memo
*/
void			*ft_memset(void *b, int c, size_t len);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_calloc(size_t count, size_t size);
void			ft_bzero(void *s, size_t n);
void			ft_swap(char *a, char *b);
/*
** String
*/

size_t			ft_strlen(const char *s);
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t			ft_strlcat(char *dst, const char *src, size_t dstsize);
char			*ft_strcat(char *src, char *dst);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strnstr(
					const char *haystack, const char *needle, size_t len);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_strequals(char *s1, char *s2);
char			*ft_strndup(char *s, int len);
int				ft_atoi(const char *str);
double			ft_atod(char *str);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isdigit_non_zero(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);
char			*ft_strdup(const char *s1);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *set);
char			**ft_split(char const *s, char c);
char			*ft_itoa(long long n);
char			*ft_dtoa(double d, int prec);
char			*ft_strmapi(char *s, char (*f)(unsigned int, char));
int				get_range(long n, int negative);
char			*dec_to_any(long dec, char *base, int base_val);
/*
** FD output
*/
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
/*
** list
*/
typedef struct	s_list
{
	struct s_list	*next;
	void			*content;
}				t_list;

t_list			*ft_lstnew(void *content);
void			ft_lstadd_front(t_list **alst, t_list *neww);
void			ft_lstadd_back(t_list **alst, t_list *neww);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstiter(t_list *lst, void (*f)(void *));
int				ft_lstsize(t_list *lst);
void			ft_lstdelone(t_list *lst, void (*del)(void*));
void			ft_lstclear(
						t_list **lst, void (*del)(void*));
t_list			*ft_lstmap(
						t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif
