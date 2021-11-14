/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclam <mclam@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 13:43:50 by mclam             #+#    #+#             */
/*   Updated: 2021/10/07 13:43:50 by mclam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The function allocates sufficient memory for a copy of the string s1, does
** the copy, and returns a pointer to it. The ft_strndup() function copies
** at most n characters from the string s1 always NUL terminating the copied
** string. Memory leaks monitored by the lc() function.
** Return value: If insufficient memory is available, NULL is returned,
** issue an error message "malloc() error in ft_strdup_lc() function" with the
** value errno and errno is set to ENOMEM.
*/
char	*ft_strdup_lc(const char *s1)
{
	size_t	n;
	char	*s2;

	n = ft_strlen(s1) + 1;
	s2 = lc(malloc(sizeof(char) * n));
	if (!s2)
		ft_error_exit("libft: Cannot allocate memory ft_strdup_lc()", ENOMEM);
	ft_memcpy(s2, s1, n);
	*(s2 + n - 1) = '\0';
	return (s2);
}
