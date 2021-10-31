/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mem_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclam <mclam@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 21:55:02 by mclam             #+#    #+#             */
/*   Updated: 2021/10/07 21:55:02 by mclam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* The function copies bytes from string src to string dst.
** If the character c (as converted to an unsigned char) occurs in the string
** src, the copy stops and a pointer to the byte after the copy of c in the
** string dst is returned.  Otherwise, n bytes are copied, and a NULL pointer
** is returned.
** The source and destination strings should not overlap, as the behavior
** is undefined.
*/
void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (dst && src && i < n)
	{
		*(unsigned char *)(dst + i) = *(unsigned char *)(src + i);
		if (*(unsigned char *)(src + i) == (unsigned char)c)
			return (dst + i + 1);
		i++;
	}
	return (NULL);
}

/*
** The function locates the first occurrence of c (converted to an unsigned
** char) in string s.
** Return value: The function returns a pointer to the byte located, or NULL
** if no such byte exists within n bytes.
*/
void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (s && i < n)
	{
		if ((unsigned char)c == *(unsigned char *)(s + i))
			return ((void *)(s + i));
		i++;
	}
	return (NULL);
}

/*
** The function compares byte string s1 against byte string s2.
** Both strings are assumed to be n bytes long.
** Return value: The function returns zero if the two strings are identical,
** otherwise returns the difference between the first two differing bytes
** (treated as unsigned char values, so that `\200' is greater than `\0',
** for example). Zero-length strings are always identical.  This behavior
** is not required by C and portable code should only depend on the sign of the
** returned value.
*/
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (*(unsigned char *)(s1 + i) != *(unsigned char *)(s2 + i))
			return (*(unsigned char *)(s1 + i) - *(unsigned char *)(s2 + i));
		i++;
	}
	return (0);
}

/*
** The function copies len bytes from string src to string dst.
** The two strings may overlap; the copy is always done in a non-destructive
** manner.
** Return value: The function returns the original value of dst.
*/
void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	if (dst == src || len == 0 || dst == NULL || src == NULL)
		return (dst);
	else if (dst < src)
	{
		i = 0;
		while (i < len)
		{
			*(unsigned char *)(dst + i) = *(unsigned char *)(src + i);
			i++;
		}
	}
	else
	{
		while (len--)
			*(unsigned char *)(dst + len) = *(unsigned char *)(src + len);
	}
	return (dst);
}

/*
** The function writes len bytes of value c (converted to an unsigned char)
** to the string b.
** Return value: The function returns its first argument.
*/
void	*ft_memset(void *b, int c, size_t len)
{
	char	*a;

	a = b;
	while (a && len--)
		*(a++) = c;
	return (b);
}
