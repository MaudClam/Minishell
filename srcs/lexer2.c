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

int	checkToken_steptokenLst(t_tokenLst **tokenLst, t_ASTree **tree, \
												t_TokenType type, char *lexeme)
{
	if (tokenLst == NULL || tree == NULL || (type == 0 && lexeme == NULL))
		return (ft_error_msg(\
		"Error: bad arguments checkToken_steptokenLst()", PARSING_ERROR));
	if (*tokenLst == NULL)
		return (PARSING_ERROR);
	if ((*tokenLst)->token->type != type)
	{
		printf("Expecting <%s>, found <%s>\n", type2char(type), \
										type2char((*tokenLst)->token->type));
		return (PARSING_ERROR);
	}
	if (ft_strcmp((*tokenLst)->token->lexeme, lexeme) != SUCCESS)
	{
		printf("Expecting %s, found %s\n", lexeme, (*tokenLst)->token->lexeme);
		return (PARSING_ERROR);
	}
	*tree = alloc_ASTreeToken((*tokenLst)->token->lexeme, \
													(*tokenLst)->token->type);
	*tokenLst = (*tokenLst)->next;
	return (SUCCESS);
}

int	is_PIPE_SYMBOL(t_tokenLst **tokenLst, t_ASTree **tree)
{
	return (checkToken_steptokenLst(tokenLst, tree, PIPE_SYMBOL, NULL));
}

int	is_REDIRECT_SYMBOL(t_tokenLst **tokenLst, t_ASTree **tree)
{
	return (checkToken_steptokenLst(tokenLst, tree, REDIRECT_SYMBOL, NULL));
}

int	is_END(t_tokenLst **tokenLst, t_ASTree **tree)
{
	return (checkToken_steptokenLst(tokenLst, tree, END, NULL));
}

int	is_WORD(t_tokenLst **tokenLst, t_ASTree **tree)
{
	return (checkToken_steptokenLst(tokenLst, tree, WORD, NULL));
}
