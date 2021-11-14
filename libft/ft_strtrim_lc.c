/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim_lc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclam <mclam@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 20:39:31 by mclam             #+#    #+#             */
/*   Updated: 2021/10/07 20:39:31 by mclam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Allocates (with malloc(3)) and returns a copy of ’s1’ with the characters
** specified in ’set’ removed from the beginning and the end of the string.
** Memory leaks monitored by the lc() function.
** Return value: The trimmed string. If insufficient memory is available,
** NULL is returned, issue an error message "malloc() error in ft_strtrim_lc()
** function" with the value errno and errno is set to ENOMEM.
*/
char	*ft_strtrim_lc(char const *s1, char const *set)
{
	size_t	left;
	size_t	right;
	char	*strtrim;
	size_t	i;

	left = 0;
	while (s1 && s1[left] && ft_isinset(s1[left], set))
		left++;
	right = ft_strlen(s1);
	while (s1 && left < right && ft_isinset(s1[right - 1], set))
		right--;
	strtrim = lc(malloc(sizeof(char) * (right - left + 1)));
	if (!strtrim)
		ft_error_exit("libft: Cannot allocate memory ft_strtrim_lc()", ENOMEM);
	i = 0;
	while (s1 && left < right)
		strtrim[i++] = s1[left++];
	strtrim[i] = '\0';
	return (strtrim);
}
