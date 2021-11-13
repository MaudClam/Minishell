/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclam <mclam@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 17:36:30 by mclam             #+#    #+#             */
/*   Updated: 2021/11/02 17:36:30 by mclam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	is_io_here(t_TokenLst **tokenLst, t_ASTree **tree)
{
	*tree = alloc_ast_token(NULL, IO_HERE);
	if ((*tokenLst)->token->lexeme != NULL)
		if (ft_strcmp((*tokenLst)->token->lexeme, "<<") == SUCCESS)
			if (is_redirect_symbol(tokenLst, &(*tree)->chld) == SUCCESS)
				if (is_here_end(tokenLst, &(*tree)->sibl) == SUCCESS)
					return (SUCCESS);
	*tree = NULL;
	return (PARSING_ERROR);
}

int	is_here_end(t_TokenLst **tokenLst, t_ASTree **tree)
{
	*tree = alloc_ast_token(NULL, HERE_END);
	if ((*tokenLst)->token->type == WORD)
		if (is_word(tokenLst, &(*tree)->chld) == SUCCESS)
			return (SUCCESS);
	syntax_errmsg((*tokenLst)->token->lexeme);
	*tree = NULL;
	return (PARSING_ERROR);
}

int	is_filename(t_TokenLst **tokenLst, t_ASTree **tree)
{
	*tree = alloc_ast_token(NULL, FILENAME);
	if ((*tokenLst)->token->type == WORD)
	{
		if (is_word(tokenLst, &(*tree)->chld) == SUCCESS)
			return (SUCCESS);
	}
	syntax_errmsg((*tokenLst)->token->lexeme);
	*tree = NULL;
	return (PARSING_ERROR);
}

int	is_io_number(t_TokenLst **tokenLst, t_ASTree **tree)
{
	int	i;

	i = 0;
	if ((*tokenLst)->token->type == WORD && (*tokenLst)->next && \
							(*tokenLst)->next->token->type == REDIRECT_SYMBOL)
	{
		while ((*tokenLst)->token->lexeme[i] != '\0')
			if (ft_isdigit((*tokenLst)->token->lexeme[i++]) != TRUE)
				return (PARSING_ERROR);
		*tree = alloc_ast_token(NULL, IO_NUMBER);
		if (is_word(tokenLst, &(*tree)->chld) == SUCCESS)
			return (SUCCESS);
		else
			*tree = NULL;
	}
	return (PARSING_ERROR);
}

size_t	ast_counter(t_ASTree *node, size_t *i, t_TokenType type, \
														t_TokenType excl_type)
{
	if (node != NULL && node->data->type != excl_type)
	{
		if (node->data->type == type)
			(*i)++;
		ast_counter(node->chld, i, type, excl_type);
		ast_counter(node->sibl, i, type, excl_type);
	}
	return (*i);
}
