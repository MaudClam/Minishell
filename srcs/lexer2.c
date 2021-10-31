/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclam <mclam@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 03:49:50 by mclam             #+#    #+#             */
/*   Updated: 2021/10/24 03:49:50 by mclam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int	checkToken_stepTokenList(t_TokenList **tokenList, t_ASTree **tree, \
												t_TokenType type, char *lexeme)
{
	if (!tokenList || !tree || (!type && !lexeme))
		return (ft_error_msg(\
		"Error: bad arguments checkToken_stepTokenList()", PARSING_ERROR));
	if (*tokenList == NULL)
		return (PARSING_ERROR);
	if ((*tokenList)->token->type != type)
	{
		printf("Expecting <%s>, found <%s>\n", type2char(type), \
										type2char((*tokenList)->token->type));
		return (PARSING_ERROR);
	}
	if (ft_strcmp((*tokenList)->token->lexeme, lexeme) != SUCCESS)
	{
		printf("Expecting %s, found %s\n", lexeme, (*tokenList)->token->lexeme);
		return (PARSING_ERROR);
	}
	*tree = alloc_ASTree();
	(*tree)->data = new_token((*tokenList)->token->lexeme, \
													(*tokenList)->token->type);
	*tokenList = (*tokenList)->next;
	return (SUCCESS);
}

int	is_PIPE_SYMBOL(t_TokenList **tokenList, t_ASTree **tree)
{
	return (checkToken_stepTokenList(tokenList, tree, PIPE_SYMBOL, NULL));
}

int	is_REDIRECT_SYMBOL(t_TokenList **tokenList, t_ASTree **tree)
{
	return (checkToken_stepTokenList(tokenList, tree, REDIRECT_SYMBOL, NULL));
}

int	is_END(t_TokenList **tokenList, t_ASTree **tree)
{
	return (checkToken_stepTokenList(tokenList, tree, END, NULL));
}

int	is_WORD(t_TokenList **tokenList, t_ASTree **tree)
{
	return (checkToken_stepTokenList(tokenList, tree, WORD, NULL));
}











