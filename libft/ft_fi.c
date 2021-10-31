/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fi.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclam <mclam@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 01:00:48 by mclam             #+#    #+#             */
/*   Updated: 2021/10/08 01:00:48 by mclam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Following functions instead of ternary operator.
*/
char	fic(char condition, char then, char otherwise_then)
{
	if (condition)
		return (then);
	else
		return (otherwise_then);
}

int	fii(char condition, int then, int otherwise_then)
{
	if (condition)
		return (then);
	else
		return (otherwise_then);
}

size_t	fis(char condition, size_t then, size_t otherwise_then)
{
	if (condition)
		return (then);
	else
		return (otherwise_then);
}

U_INT	fiu(char condition, U_INT then, U_INT otherwise_then)
{
	if (condition)
		return (then);
	else
		return (otherwise_then);
}
