/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_lc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclam <mclam@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 20:14:23 by mclam             #+#    #+#             */
/*   Updated: 2021/10/07 20:14:23 by mclam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Allocates (with malloc(3)) and returns a new string, which is the result
** of the concatenation of ’s1’ and ’s2’.
** Return value: If insufficient memory is available, NULL is returned,
** issue an error message "malloc() error in ft_strjoin_lc() function" with the
** value errno and errno is set to ENOMEM.
*/
static int	str_j_copy(char *str, char const *s, int j)
{
	int		i;

	i = 0;
	while (s[i])
		str[j++] = s[i++];
	str[j] = '\0';
	return (j);
}

char	*ft_strjoin_lc(char const *s1, char const *s2)
{
	int		j;
	char	*str;

	j = 0;
	str = lc(malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1)));
	if (!str)
	{
		ft_error_msg("malloc() error in ft_strjoin_lc() function", ENOMEM);
		errno = ENOMEM;
		return (NULL);
	}
	if (s1)
		j = str_j_copy(str, s1, j);
	if (s2)
		str_j_copy(str, s2, j);
	return (str);
}
