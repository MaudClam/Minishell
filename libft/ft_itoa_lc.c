/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_lc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclam <mclam@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 13:25:29 by mclam             #+#    #+#             */
/*   Updated: 2021/10/08 00:50:49 by mclam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Allocates (with malloc(3)) and returns a string representing the integer
** received as an argument. Negative processing numbers.
** Memory leaks monitored by the lc() function.
** Return value: The string representing the integer. NULL if the
** allocation fails.
*/
static size_t	itoa_counter(U_INT nb, U_INT *divider)
{
	size_t		i;

	i = 1;
	while (nb > 9)
	{
		*divider = *divider * 10;
		nb = nb / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa_lc(int n)
{
	U_INT	nb;
	U_INT	divider;
	size_t	dgts;
	char	*str_itoa;

	nb = fiu(n < 0, (U_INT)(-(n + 1)) + 1, (U_INT)n);
	divider = 1;
	dgts = itoa_counter(nb, &divider);
	str_itoa = (char *)ft_calloc_lc((dgts + fis(n < 0, 2, 1)), sizeof(char));
	if (!str_itoa)
		return (NULL);
	dgts = 0;
	if (n < 0)
		*(str_itoa + dgts++) = '-';
	while (divider)
	{
		*(str_itoa + dgts++) = nb / divider + '0';
		nb = nb % divider;
		divider = divider / 10;
	}
	return (str_itoa);
}
