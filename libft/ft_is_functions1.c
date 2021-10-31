/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_functions1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclam <mclam@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 19:31:16 by mclam             #+#    #+#             */
/*   Updated: 2021/09/29 19:31:16 by mclam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == '\r' \
					|| c == '\v' || c == '\f' || c == ' ')
		return (1);
	return (0);
}

int	ft_isinset(const char c, const char *set)
{
	int	i;

	i = 0;
	while (set && set[i])
		if (c == set[i++])
			return (1);
	return (0);
}
