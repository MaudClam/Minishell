/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_functions1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclam <mclam@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 15:27:43 by mclam             #+#    #+#             */
/*   Updated: 2021/10/08 15:27:43 by mclam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The function fpplies the function ’f’ to each character of the string ’s’ to
** create a new string (with malloc(3)) resulting from successive applications
** of ’f’.
** Return value: The string created from the successive applications of ’f’.
** Returns NULL if the allocation fails.
*/
char	*ft_strmapi_lc(char const *s, char (*f)(unsigned int, char))
{
	char			*map;
	unsigned int	i;

	map = ft_strdup_lc(s);
	i = 0;
	while (map && map[i])
	{
		map[i] = f(i, map[i]);
		i++;
	}
	return (map);
}

/*
** The function lexicographically compare the null-terminated strings s1 and s2.
** Because function is designed for comparing strings rather than binary data,
** characters that appear after a `\0' character are not compared.
** Return value: The function return an integer greater than, equal to, or less
** than 0, according as the string s1 is greater than, equal to, or less than
** the string s2.  The comparison is done using unsigned characters, so that
** `\200' is greater than `\0'.
*/
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	ln_s1;
	size_t	ln_s2;

	if ((!s1 && !s2) || (s1 && s2 && !s1[0] && !s2[0]) || n == 0)
		return (0);
	ln_s1 = ft_strlen(s1) + 1;
	ln_s2 = ft_strlen(s2) + 1;
	if (n > ln_s1 && n > ln_s2 && ln_s1 > ln_s2)
		return (ft_memcmp(s1, s2, ln_s1));
	else if (n > ln_s1 && n > ln_s2)
		return (ft_memcmp(s1, s2, ln_s2));
	return (ft_memcmp(s1, s2, n));
}

/*
** The function locates the first occurrence of the null-terminated string
** needle in the string haystack, where not more than len characters are
** searched.  Characters that appear after a `\0' character are not searched.
** Return value: If needle is an empty string, haystack is returned; if needle
** occurs nowhere in haystack, NULL is returned; otherwise a pointer to the
** first character of the first occurrence of needle is returned.
*/
char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	haystack_len;
	size_t	needle_len;
	size_t	i;
	size_t	j;

	haystack_len = ft_strlen(haystack);
	needle_len = ft_strlen(needle);
	if (0 == needle_len || NULL == needle)
		return ((char *)haystack);
	if (0 == haystack_len || NULL == haystack)
		return (NULL);
	i = 0;
	while (i + needle_len < len + 1 && i + needle_len < haystack_len + 1)
	{
		j = 0;
		while (needle[j] && haystack[i + j] == needle[j])
			j++;
		if (needle[j] == '\0')
			return ((char *)haystack + i);
		i++;
	}
	return (NULL);
}

/*
** The function locates the last occurrence of c (converted to a char) in the
** string pointed to by s.  The terminating null character is considered to be
** part of the string; therefore if c is `\0', the functions locate the
** terminating `\0'.
** Return value: The function return a pointer to the located character, or NULL
** if the character does not appear in the string.
*/
char	*ft_strrchr(const char *s, int c)
{
	size_t	i;

	i = ft_strlen(s) + 1;
	while (i--)
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
	}
	return (NULL);
}

/*
** The function lexicographically compare the null-terinated strings s1 and s2.
** Return value: The function return an integer greater than, equal to, or less\
** than 0, according as the string s1 is greater than, equal to, or less than\
** the string s2.  The comparison is done using unsigned characters, so that\
** `\200' is greater than `\0'.
*/
int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	if (!s1 || !s2)
		return (0);
	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] - s2[i])
			break ;
		i++;
	}
	return (s1[i] - s2[i]);
}
