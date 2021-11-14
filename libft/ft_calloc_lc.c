/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc_lc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclam <mclam@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 19:46:03 by mclam             #+#    #+#             */
/*   Updated: 2021/10/07 19:46:03 by mclam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The function contiguously allocates enough space for count objects that are
** size bytes of memory each and returns a pointer to the allocated memory.
** The allocated memory is filled with bytes of value zero.
** Return value: If successful, the function return a pointer to allocated
** memory. If there is an error, they return a NULL pointer and issue an error
** message "malloc() error in ft_calloc_lc() function" with the value errno
** and errno is set to ENOMEM.
*/
void	*ft_calloc_lc(size_t count, size_t size)
{
	void	*ptr;

	ptr = lc(malloc(count * size));
	if (!ptr)
		ft_error_exit("libft: Cannot allocate memory inft_calloc_lc()", ENOMEM);
	ft_bzero(ptr, count * size);
	return (ptr);
}
