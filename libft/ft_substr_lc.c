/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr_lc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclam <mclam@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 21:11:00 by mclam             #+#    #+#             */
/*   Updated: 2020/11/19 00:15:04 by mclam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The function allocates (with malloc(3)) and returns a substring from the
** string ’s’. The substring begins at index ’start’ and is of maximum size
** ’len’.  Memory leaks monitored by the lc() function.
** Return value: The substring. NULL if the allocation fails.
*/
char	*ft_substr_lc(const char *s, unsigned int start, size_t len)
{
	size_t	len_s;
	size_t	n;
	void	*substr;

	len_s = ft_strlen(s);
	n = fis(len + start > len_s, fis(len_s > start, len_s - start, 0), len);
	substr = lc(malloc(sizeof(char) * (n + 1)));
	if (!substr)
	{
		ft_error_msg("malloc() error in ft_substr() function", ENOMEM);
		errno = ENOMEM;
		return (NULL);
	}
	if (start < len_s)
		ft_memcpy(substr, (const void *)(s + start), n);
	*(char *)(substr + n) = '\0';
	return (substr);
}
