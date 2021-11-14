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

int	is_command_prefix(t_TokenLst **tokenLst, t_ASTree **tree)
{
	*tree = alloc_ast_token(NULL, command_prefix);
	if ((*tokenLst)->token->type == REDIRECT_SYMBOL)
	{
		if (is_io_redirect(tokenLst, &(*tree)->chld) == SUCCESS)
		{
			if (is_command_prefix(tokenLst, &(*tree)->chld->sibl) == SUCCESS)
				return (SUCCESS);
			return (SUCCESS);
		}
	}
	*tree = NULL;
	return (PARSING_ERROR);
}

int	is_command_word(t_TokenLst **tokenLst, t_ASTree **tree)
{
	*tree = alloc_ast_token(NULL, command_word);
	if ((*tokenLst)->token->type == WORD)
		if (is_word(tokenLst, &(*tree)->chld) == SUCCESS)
			return (SUCCESS);
	*tree = NULL;
	return (PARSING_ERROR);
}

int	is_command_suffix(t_TokenLst **tokenLst, t_ASTree **tree)
{
	*tree = alloc_ast_token(NULL, command_suffix);
	if ((*tokenLst)->token->type == REDIRECT_SYMBOL)
	{
		if (is_io_redirect(tokenLst, &(*tree)->chld) == SUCCESS)
		{
			if (is_command_suffix(tokenLst, &(*tree)->sibl) == SUCCESS)
				return (SUCCESS);
			return (SUCCESS);
		}
	}
	if ((*tokenLst)->token->type == WORD)
	{
		if (is_word(tokenLst, &(*tree)->chld) == SUCCESS)
		{
			if (is_command_suffix(tokenLst, &(*tree)->sibl) == SUCCESS)
				return (SUCCESS);
			return (SUCCESS);
		}
	}
	*tree = NULL;
	return (PARSING_ERROR);
}

int	is_io_redirect(t_TokenLst **tokenLst, t_ASTree **tree)
{
	*tree = alloc_ast_token(NULL, io_redirect);
	if (is_io_file(tokenLst, &(*tree)->chld) == SUCCESS)
		return (SUCCESS);
	if (is_io_number(tokenLst, &(*tree)->chld) == SUCCESS)
		if (is_io_file(tokenLst, &(*tree)->sibl) == SUCCESS)
			return (SUCCESS);
	if (is_io_here(tokenLst, &(*tree)->chld) == SUCCESS)
		return (SUCCESS);
	if (is_io_number(tokenLst, &(*tree)->chld) == SUCCESS)
		if (is_io_here(tokenLst, &(*tree)->sibl) == SUCCESS)
			return (SUCCESS);
	*tree = NULL;
	return (PARSING_ERROR);
}

int	is_io_file(t_TokenLst **tokenLst, t_ASTree **tree)
{
	*tree = alloc_ast_token(NULL, io_file);
	if ((*tokenLst)->token->lexeme != NULL)
		if (ft_strcmp((*tokenLst)->token->lexeme, "<") == SUCCESS)
			if (is_redirect_symbol(tokenLst, &(*tree)->chld) == SUCCESS)
				if (is_filename(tokenLst, &(*tree)->chld->sibl) == SUCCESS)
					return (SUCCESS);
	if ((*tokenLst)->token->lexeme != NULL)
		if (ft_strcmp((*tokenLst)->token->lexeme, ">") == SUCCESS)
			if (is_redirect_symbol(tokenLst, &(*tree)->chld) == SUCCESS)
				if (is_filename(tokenLst, &(*tree)->chld->sibl) == SUCCESS)
					return (SUCCESS);
	if ((*tokenLst)->token->lexeme != NULL)
		if (ft_strcmp((*tokenLst)->token->lexeme, ">>") == SUCCESS)
			if (is_redirect_symbol(tokenLst, &(*tree)->chld) == SUCCESS)
				if (is_filename(tokenLst, &(*tree)->chld->sibl) == SUCCESS)
					return (SUCCESS);
	*tree = NULL;
	return (PARSING_ERROR);
}
