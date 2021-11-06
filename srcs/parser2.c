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

int	is_IO_HERE(t_TokenLst **tokenLst, t_ASTree **tree)
{
	*tree = alloc_ASTreeToken(NULL, IO_HERE);
	if ((*tokenLst)->token->lexeme != NULL)
		if (ft_strcmp((*tokenLst)->token->lexeme, "<<") == SUCCESS)
			if (is_REDIRECT_SYMBOL(tokenLst, &(*tree)->chld) == SUCCESS)
				if (is_HERE_END(tokenLst, &(*tree)->sibl) == SUCCESS)
					return (SUCCESS);
	*tree = NULL;
	return (PARSING_ERROR);
}

int	is_HERE_END(t_TokenLst **tokenLst, t_ASTree **tree)
{
	*tree = alloc_ASTreeToken(NULL, HERE_END);
	if ((*tokenLst)->token->type == WORD)
		if (is_WORD(tokenLst, &(*tree)->chld) == SUCCESS)
			return (SUCCESS);
	print_errsyntax((*tokenLst)->token->lexeme);
	*tree = NULL;
	return (PARSING_ERROR);
}

int	is_FILENAME(t_TokenLst **tokenLst, t_ASTree **tree)
{
	*tree = alloc_ASTreeToken(NULL, FILENAME);
	if ((*tokenLst)->token->type == WORD)
	{
		if (is_WORD(tokenLst, &(*tree)->chld) == SUCCESS)
			return (SUCCESS);
	}
	print_errsyntax((*tokenLst)->token->lexeme);
	*tree = NULL;
	return (PARSING_ERROR);
}

int	is_IO_NUMBER(t_TokenLst **tokenLst, t_ASTree **tree)
{
	int	i;

	i = 0;
	if ((*tokenLst)->token->type == WORD && (*tokenLst)->next && \
							(*tokenLst)->next->token->type == REDIRECT_SYMBOL)
	{
		while ((*tokenLst)->token->lexeme[i] != '\0')
			if (ft_isdigit((*tokenLst)->token->lexeme[i++]) != TRUE)
				return (PARSING_ERROR);
		*tree = alloc_ASTreeToken(NULL, IO_NUMBER);
		if (is_WORD(tokenLst, &(*tree)->chld) == SUCCESS)
			return (SUCCESS);
		else
			*tree = NULL;
	}
	return (PARSING_ERROR);
}
