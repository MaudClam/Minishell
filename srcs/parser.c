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

int	build_ASTree(t_TokenList **tokenList, t_ASTree **tree)
{
	if (is_PIPE_SEQUENCE(tokenList, tree) == SUCCESS)
		return (SUCCESS);
	return (ERROR);
}

t_ASTree	*alloc_ASTree(void)
{
	t_ASTree	*tree;

	tree = ft_calloc_lc(sizeof(t_ASTree), 1);
	if (!tree)
		ft_error_exit(strerror(ENOMEM), ENOMEM);
	return (tree);
}

int	is_PIPE_SEQUENCE(t_TokenList **tokenList, t_ASTree **tree)
{
	if (!tokenList || !tree)
		return (ft_error_msg("Bad arguments is_PIPE_SEQUENCE()", ERROR));
	*tree = alloc_ASTree();
	(*tree)->data = new_token(NULL, PIPE_SEQUENCE);
	if (is_COMMAND(tokenList, &(*tree)->chld) == SUCCESS)
	{
		if (is_END(tokenList, &(*tree)->sibl) == SUCCESS)
			return (SUCCESS);
		else if (is_PIPE_SYMBOL(tokenList, &(*tree)->sibl) == SUCCESS)
			if (is_PIPE_SEQUENCE(tokenList, &(*tree)->sibl->sibl) == SUCCESS)
				return (SUCCESS);
	}
	return (PARSING_ERROR);
}

int	is_COMMAND(t_TokenList **tokenList, t_ASTree **tree)
{
	int	criterion;
	
	criterion = 0;
	if (!tokenList || !tree)
		return (ft_error_msg("Bad arguments is_COMMAND()", ERROR));
	*tree = alloc_ASTree();
	(*tree)->data = new_token(NULL, COMMAND);
	if (is_COMMAND_PREFIX(tokenList, &(*tree)->chld) == SUCCESS)
		criterion = 100;
	if (criterion == 0)
		if (is_COMMAND_WORD(tokenList, &(*tree)->chld) == SUCCESS)
			criterion = 200;
	if (criterion == 100)
		if (is_COMMAND_WORD(tokenList, &(*tree)->sibl) == SUCCESS)
			criterion = 120;
	if (criterion == 0)
		if (is_COMMAND_SUFFIX(tokenList, &(*tree)->chld) == SUCCESS)
			criterion = 300;
	if (criterion == 100 || criterion == 200)
		if (is_COMMAND_SUFFIX(tokenList, &(*tree)->sibl) == SUCCESS)
			criterion += 30;
	if (criterion == 120)
		if (is_COMMAND_SUFFIX(tokenList, &(*tree)->sibl->sibl) == SUCCESS)
			criterion = 123;
	return (fii(criterion == 0, PARSING_ERROR, SUCCESS));
}

int		is_COMMAND_PREFIX(t_TokenList **tokenList, t_ASTree **tree)
{
	if (!tokenList || !tree)
		return (ft_error_msg("Bad arguments is_COMMAND_PREFIX()", ERROR));
	*tree = alloc_ASTree();
	(*tree)->data = new_token(NULL, COMMAND_PREFIX);
	return (PARSING_ERROR);
}
