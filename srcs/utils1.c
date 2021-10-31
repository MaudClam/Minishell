/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclam <mclam@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 03:39:53 by mclam             #+#    #+#             */
/*   Updated: 2021/10/24 03:39:53 by mclam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

void	print_Token(t_Token *token)
{
	printf("<'%s', %s>\n", token->lexeme, type2char(token->type));
}

void	print_TokenList(t_TokenList *tokenList)
{
	while (tokenList && tokenList->next)
	{
		print_Token(tokenList->token);
		tokenList = tokenList->next;
	}
}

static void	print_PT(t_ASTree *tree, int indent)
{
	t_ASTree	*sibl;
	t_ASTree	*chld;

	if (tree)
	{
		while (--indent >= 0)
			ft_putchar_fd(' ', STDOUT_FILENO);
		print_Token(tree->data);
		sibl = tree->sibl;
		chld = tree->chld;
		print_PT(chld, indent + PRN_PTREE_INDENT);
		print_PT(sibl, indent);
	}
}

void	print_ASTree(t_ASTree *tree)
{
	print_PT(tree, 0);
}
