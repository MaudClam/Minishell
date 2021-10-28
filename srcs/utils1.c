/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclam <mclam@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 03:39:53 by mclam             #+#    #+#             */
/*   Updated: 2021/10/24 03:39:53 by mclam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

char	*type2char(t_TokenType type)
{
	static char		**tokenTypes;
	static size_t	arrsize;

	if (!tokenTypes)
	{
		tokenTypes = ft_splitset_lc(TOKEN_TYPES_SET, ",; |");
		if (tokenTypes)
			arrsize = ft_arrsize((const void **)tokenTypes);
	}
	if (tokenTypes && type >= 0 && type < arrsize)
		return (tokenTypes[type]);
	else if (!tokenTypes)
		err_exit(MEMORY_ERROR, errno);
	ft_errmsg(TYPE2CHAR_ERROR, ERROR);
	return (NULL);
}
