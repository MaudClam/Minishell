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

int	build_ASTree(t_tokenLst **tokenLst, t_ASTree **tree)
{
	if (is_PIPE_SEQUENCE(tokenLst, tree) == SUCCESS)
		return (SUCCESS);
	return (ERROR);
}

t_ASTree	*alloc_ASTree(void)
{
	t_ASTree	*tree;

	tree = ft_calloc_lc(sizeof(t_ASTree), 1);
	if (tree == NULL)
		ft_error_exit(strerror(ENOMEM), ENOMEM);
	return (tree);
}

t_ASTree	*alloc_ASTreeToken(char *lexeme, t_TokenType type)
{
	t_ASTree	*tree;

	tree = alloc_ASTree();
	tree->data = new_token(lexeme, type);
	return (tree);
}

int	is_PIPE_SEQUENCE(t_tokenLst **tokenLst, t_ASTree **tree)
{
	*tree = alloc_ASTreeToken(NULL, PIPE_SEQUENCE);
	if (is_COMMAND(tokenLst, &(*tree)->chld) == SUCCESS)
	{
		if ((*tokenLst)->token->type == END)
		{
			if (is_END(tokenLst, &(*tree)->sibl) == SUCCESS)
				return (SUCCESS);
		}
		else if ((*tokenLst)->token->type == PIPE_SYMBOL)
		{
			if (is_PIPE_SYMBOL(tokenLst, &(*tree)->sibl) == SUCCESS)
				if (is_PIPE_SEQUENCE(tokenLst, &(*tree)->sibl->sibl) == SUCCESS)
					return (SUCCESS);
		}
	}
	*tree = NULL;
	return (PARSING_ERROR);
}

int	is_COMMAND(t_tokenLst **tokenLst, t_ASTree **tree)
{
	*tree = alloc_ASTreeToken(NULL, COMMAND);
	if (is_COMMAND_PREFIX(tokenLst, &(*tree)->chld) == SUCCESS)
	{
		if (is_COMMAND_WORD(tokenLst, &(*tree)->chld->sibl) == SUCCESS)
		{
			if (is_COMMAND_SUFFIX(tokenLst, &(*tree)->chld->sibl->sibl) == SUCCESS)
				return (SUCCESS);
			else
				return (SUCCESS);
		}
		return (SUCCESS);
	}
	else if (is_COMMAND_WORD(tokenLst, &(*tree)->chld) == SUCCESS)
	{
		if (is_COMMAND_SUFFIX(tokenLst, &(*tree)->chld->sibl) == SUCCESS)
			return (SUCCESS);
		else
			return (SUCCESS);
	}
	*tree = NULL;
	return (PARSING_ERROR);
}
