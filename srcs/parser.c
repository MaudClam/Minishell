/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclam <mclam@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 20:15:12 by mclam             #+#    #+#             */
/*   Updated: 2021/10/20 20:15:12 by mclam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	build_astree(t_TokenLst **tokenLst, t_ASTree **tree)
{
	if (is_pipe_sequence(tokenLst, tree) == SUCCESS)
		return (SUCCESS);
	return (ERROR);
}

t_ASTree	*alloc_astree(void)
{
	t_ASTree	*tree;

	tree = ft_calloc_lc(sizeof(t_ASTree), 1);
	if (tree == NULL)
		error_exit(strerror(ENOMEM), ENOMEM);
	return (tree);
}

t_ASTree	*alloc_ast_token(char *lexeme, t_TokenType type)
{
	t_ASTree	*tree;

	tree = alloc_astree();
	tree->data = new_token(lexeme, type);
	return (tree);
}

int	is_pipe_sequence(t_TokenLst **tokenLst, t_ASTree **tree)
{
	*tree = alloc_ast_token(NULL, PIPE_SEQUENCE);
	if (is_command(tokenLst, &(*tree)->chld) == SUCCESS)
	{
		if ((*tokenLst)->token->type == END)
		{
			if (is_end(tokenLst, &(*tree)->sibl) == SUCCESS)
				return (SUCCESS);
		}
		else if ((*tokenLst)->token->type == PIPE_SYMBOL)
		{
			if (is_pipe_symbol(tokenLst, &(*tree)->sibl) == SUCCESS)
				if (is_pipe_sequence(tokenLst, &(*tree)->sibl->sibl) == \
																		SUCCESS)
					return (SUCCESS);
		}
	}
	*tree = NULL;
	syntax_errmsg((*tokenLst)->token->lexeme);
	return (PARSING_ERROR);
}

int	is_command(t_TokenLst **tokenLst, t_ASTree **tree)
{
	*tree = alloc_ast_token(NULL, COMMAND);
	if (is_command_prefix(tokenLst, &(*tree)->chld) == SUCCESS)
	{
		if (is_command_word(tokenLst, &(*tree)->chld->sibl) == SUCCESS)
		{
			if (is_command_suffix(tokenLst, &(*tree)->chld->sibl->sibl) == \
																		SUCCESS)
				return (SUCCESS);
			else
				return (SUCCESS);
		}
		return (SUCCESS);
	}
	else if (is_command_word(tokenLst, &(*tree)->chld) == SUCCESS)
	{
		if (is_command_suffix(tokenLst, &(*tree)->chld->sibl) == SUCCESS)
			return (SUCCESS);
		else
			return (SUCCESS);
	}
	syntax_errmsg((*tokenLst)->token->lexeme);
	*tree = NULL;
	return (PARSING_ERROR);
}
