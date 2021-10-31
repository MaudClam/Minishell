/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_indexname_lc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclam <mclam@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 23:04:03 by mclam             #+#    #+#             */
/*   Updated: 2021/10/07 23:04:03 by mclam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_indexname_lc(char const *name, int index, char const *extension)
{
	char	*str;

	if (index < 1)
		str = ft_strjoin_lc(name, extension);
	else
		str = ft_strjoin_lc(ft_strjoin_lc(name, ft_itoa_lc(index)), extension);
	return (str);
}
