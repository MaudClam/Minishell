/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclam <mclam@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 17:35:54 by mclam             #+#    #+#             */
/*   Updated: 2021/10/31 17:35:54 by mclam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int			is_COMMAND_WORD(t_TokenList **tokenList, t_ASTree **tree)
{
	if (!tokenList || !tree)
		return (ft_error_msg("Bad arguments is_COMMAND_WORD()", ERROR));
	*tree = alloc_ASTree();
	(*tree)->data = new_token(NULL, COMMAND_WORD);
	return (PARSING_ERROR);
}

int			is_COMMAND_SUFFIX(t_TokenList **tokenList, t_ASTree **tree)
{
	if (!tokenList || !tree)
		return (ft_error_msg("Bad arguments is_COMMAND_SUFFIX)", ERROR));
	*tree = alloc_ASTree();
	(*tree)->data = new_token(NULL, COMMAND_SUFFIX);
	return (PARSING_ERROR);
}
