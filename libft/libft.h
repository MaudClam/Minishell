/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclam <mclam@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 01:30:59 by mclam             #+#    #+#             */
/*   Updated: 2021/09/19 01:30:59 by mclam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <errno.h>
# include <stdint.h>
# include <stdio.h>//FIXME

# define FREE_TO_FIX	(void *)1
# define FREE_ALL		NULL
# define FIX_POINTER	(void *)-1
# define U_INT			unsigned int

typedef struct s_list	t_list;
typedef struct s_lc		t_lc;

int		ft_atoi(const char *str);
void	ft_bzero(void *s, size_t n);
int		ft_error_msg(char *str, int err);
int		ft_error_exit(char *str, int err);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isinset(const char c, const char *set);
int		ft_isprint(int c);
int		ft_isspace(char c);
void	*ft_memccpy(void *dst, const void *src, int c, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memset(void *b, int c, size_t len);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
char	*ft_strdup(const char *s1);
char	*ft_strchr(const char *s, int c);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strcpy(char *dst, const char *src);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strrchr(const char *s, int c);
char	*ft_substr(const char *s, unsigned int start, size_t len);
int		ft_tolower(int c);
int		ft_toupper(int c);

struct					s_list
{
	void				*content;
	struct s_list		*next;
};

void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstdelone(t_list *lst, void (*del)(void*));
t_list	*ft_lstcopy(t_list *lst, void *(*cmp)(void *), void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list	*ft_lstnew(void *content);
int		ft_lstsize(t_list *lst);

struct s_lc
{
	char				flag;
	void				*ptr;
	struct s_lc			*next;
};

void	*lc(void *ptr);
char	*ft_itoa_lc(int n);
char	**ft_splitset_lc(char const *s, char const *set);
char	*ft_strdup_lc(const char *s1);
void	*ft_calloc_lc(size_t count, size_t size);
char	*ft_strjoin_lc(char const *s1, char const *s2);
char	*ft_strtrim_lc(char const *s1, char const *set);
char	*ft_indexname_lc(char const *name, int index, char const *extension);
t_list	*ft_lstnew_lc(void *content);
char	*ft_strmapi_lc(char const *s, char (*f)(unsigned int, char));
char	*ft_substr_lc(const char *s, unsigned int start, size_t len);

char	fic(char condition, char then, char otherwise_then);
int		fii(char condition, int then, int otherwise_then);
size_t	fis(char condition, size_t then, size_t otherwise_then);
U_INT	fiu(char condition, U_INT then, U_INT otherwise_then);

size_t	ft_arrsize(const void **arr);

#endif
