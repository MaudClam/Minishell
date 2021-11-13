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

int	check_token_step_tokenlst(t_TokenLst **tokenLst, t_ASTree **tree, \
												t_TokenType type, char *lexeme)
{
	if (tokenLst == NULL || tree == NULL || (type == 0 && lexeme == NULL))
		return (ft_error_msg(\
		"Error: bad arguments check_token_step_tokenlst()", PARSING_ERROR));
	if (*tokenLst == NULL)
		return (PARSING_ERROR);
	if ((*tokenLst)->token->type != type)
	{
		printf("expecting <%s>, found <%s>\n", type2char(type), \
										type2char((*tokenLst)->token->type));
		return (PARSING_ERROR);
	}
	if (lexeme != NULL)
	{
		if (ft_strcmp((*tokenLst)->token->lexeme, lexeme) != SUCCESS)
		{
			printf("expecting '%s', found '%s'\n", lexeme, \
													(*tokenLst)->token->lexeme);
			return (PARSING_ERROR);
		}
	}
	*tree = alloc_ast_token((*tokenLst)->token->lexeme, \
													(*tokenLst)->token->type);
	*tokenLst = (*tokenLst)->next;
	return (SUCCESS);
}

int	is_word(t_TokenLst **tokenLst, t_ASTree **tree)
{
	return (check_token_step_tokenlst(tokenLst, tree, WORD, NULL));
}

int	is_pipe_symbol(t_TokenLst **tokenLst, t_ASTree **tree)
{
	return (check_token_step_tokenlst(tokenLst, tree, PIPE_SYMBOL, NULL));
}

int	is_redirect_symbol(t_TokenLst **tokenLst, t_ASTree **tree)
{
	return (check_token_step_tokenlst(tokenLst, tree, REDIRECT_SYMBOL, NULL));
}

int	is_end(t_TokenLst **tokenLst, t_ASTree **tree)
{
	return (check_token_step_tokenlst(tokenLst, tree, END, NULL));
}
