/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclam <mclam@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 13:33:37 by mclam             #+#    #+#             */
/*   Updated: 2021/10/07 13:33:37 by mclam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The function copies n bytes from memory area src to memory area dst.
** If dst and src overlap, behavior is undefined.  Applications in which
** dst and src might overlap should use ft_memmove() instead.
** Return value: The original value of dst.
*/
void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	if (dst && src)
		while (n--)
			*(char *)(dst + n) = *(char *)(src + n);
	return (dst);
}
