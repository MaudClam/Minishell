/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclam <mclam@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 19:36:13 by mclam             #+#    #+#             */
/*   Updated: 2021/10/08 10:53:49 by mclam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The function locates the first occurrence of c (converted to a char)
** in the string pointed to by s.  The terminating null character is considered
** to be part of the string; therefore if c is `\0', the functions locate the
** terminating `\0'.
** Return value: The functions return a pointer to the located character,
** or NULL if the character does not appear in the string.
*/
char	*ft_strchr(const char *s, int c)
{
	return (ft_memchr(s, c, ft_strlen(s) + 1));
}

/*
** The function copy the string src to dst (including the terminating `\0'
** character.) The source and destination strings should not overlap, as the
** behavior is undefined.
** Return value: The function return dst.
*/
char	*ft_strcpy(char *dst, const char *src)
{
	size_t	i;

	i = 0;
	while (dst && src && dst[i] && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	return (dst);
}

/*
** The function appends string src to the end of dst.  It will append at most
** dstsize - ft_strlen(dst) - 1 characters.  It will then NUL-terminate, unless
** dstsize is 0 or the original dst string was longer than dstsize (in practice
** this should not happen as it means that either dstsize is incorrect or that
** dst is not a proper string).
** Return value: The total length of the string they tried to create. If the
** return value is >= dstsize, the output string has been truncated. It is the
** caller's responsibility to handle this.
*/
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dstlen;
	size_t	srclen;
	size_t	i;

	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	if (dstsize <= dstlen)
		return (dstsize + srclen);
	if (NULL == dst || NULL == src)
		return (0);
	i = 0;
	while (i + dstlen < dstsize - 1 && src[i] != '\0')
	{
		dst[i + dstlen] = src[i];
		i++;
	}
	dst[i + dstlen] = '\0';
	return (dstlen + srclen);
}

/*
** The function copies up to dstsize - 1 characters from the string src to dst,
** NUL-terminating the result if dstsize is not 0. Memory leaks monitored by the
** lc() function.
** Return value: The total length of the string they tried to create. If the
** return value is >= dstsize, the output string has been truncated. It is the
** caller's responsibility to handle this.
*/
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	if (!src)
		return (0);
	if (dstsize && dst)
	{
		i = 0;
		while (i < dstsize - 1 && src[i] != '\0')
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}

/*
** The function computes the length of the string s.
** Return value: The number of characters that precede the terminating
** NUL character.
*/
size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s && s[len])
		len++;
	return (len);
}
