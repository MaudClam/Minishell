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

int	is_COMMAND_PREFIX(t_tokenLst **tokenLst, t_ASTree **tree)
{
	*tree = alloc_ASTreeToken(NULL, COMMAND_PREFIX);
	if ((*tokenLst)->token->type == REDIRECT_SYMBOL)
	{
		if (is_IO_REDIRECT(tokenLst, &(*tree)->chld) == SUCCESS)
		{
			if (is_COMMAND_PREFIX(tokenLst, &(*tree)->chld->sibl) == SUCCESS)
				return (SUCCESS);
			return (SUCCESS);
		}
	}
	*tree = NULL;
	return (PARSING_ERROR);
}

int	is_COMMAND_WORD(t_tokenLst **tokenLst, t_ASTree **tree)
{
	*tree = alloc_ASTreeToken(NULL, COMMAND_WORD);
	if ((*tokenLst)->token->type == WORD)
		if (is_WORD(tokenLst, &(*tree)->chld) == SUCCESS)
			return (SUCCESS);
	*tree = NULL;
	return (PARSING_ERROR);
}

int	is_COMMAND_SUFFIX(t_tokenLst **tokenLst, t_ASTree **tree)
{
	*tree = alloc_ASTreeToken(NULL, COMMAND_SUFFIX);
	if ((*tokenLst)->token->type == REDIRECT_SYMBOL)
	{
		if (is_IO_REDIRECT(tokenLst, &(*tree)->chld) == SUCCESS)
		{
			if (is_COMMAND_SUFFIX(tokenLst, &(*tree)->sibl) == SUCCESS)
				return (SUCCESS);
			return (SUCCESS);
		}
	}
	if ((*tokenLst)->token->type == WORD)
	{
		if (is_WORD(tokenLst, &(*tree)->chld) == SUCCESS)
		{
			if (is_COMMAND_SUFFIX(tokenLst, &(*tree)->sibl) == SUCCESS)
				return (SUCCESS);
			return (SUCCESS);
		}
	}
	*tree = NULL;
	return (PARSING_ERROR);
}

int	is_IO_REDIRECT(t_tokenLst **tokenLst, t_ASTree **tree)
{
	*tree = alloc_ASTreeToken(NULL, IO_REDIRECT);
	if (is_IO_FILE(tokenLst, &(*tree)->chld) == SUCCESS)
		return (SUCCESS);
	if (is_IO_NUMBER(tokenLst, &(*tree)->chld) == SUCCESS)
		if (is_IO_FILE(tokenLst, &(*tree)->sibl) == SUCCESS)
			return (SUCCESS);
	if (is_IO_HERE(tokenLst, &(*tree)->chld) == SUCCESS)
		return (SUCCESS);
	if (is_IO_NUMBER(tokenLst, &(*tree)->chld) == SUCCESS)
		if (is_IO_HERE(tokenLst, &(*tree)->sibl) == SUCCESS)
			return (SUCCESS);
	*tree = NULL;
	return (PARSING_ERROR);
}

int	is_IO_FILE(t_tokenLst **tokenLst, t_ASTree **tree)
{
	*tree = alloc_ASTreeToken(NULL, IO_FILE);
	if (ft_strcmp((*tokenLst)->token->lexeme, "<") == SUCCESS)
		if (is_REDIRECT_SYMBOL(tokenLst, &(*tree)->chld) == SUCCESS)
			if (is_FILENAME(tokenLst, &(*tree)->chld->sibl) == SUCCESS)
				return (SUCCESS);
	if (ft_strcmp((*tokenLst)->token->lexeme, ">") == SUCCESS)
		if (is_REDIRECT_SYMBOL(tokenLst, &(*tree)->chld) == SUCCESS)
			if (is_FILENAME(tokenLst, &(*tree)->chld->sibl) == SUCCESS)
				return (SUCCESS);
	if (ft_strcmp((*tokenLst)->token->lexeme, ">>") == SUCCESS)
		if (is_REDIRECT_SYMBOL(tokenLst, &(*tree)->chld) == SUCCESS)
			if (is_FILENAME(tokenLst, &(*tree)->chld->sibl) == SUCCESS)
				return (SUCCESS);
	*tree = NULL;
	return (PARSING_ERROR);
}
