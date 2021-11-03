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
	if (token->lexeme == NULL)
		printf("<%s> ", type2char(token->type));
	else
		printf("<%s '%s'> ", type2char(token->type), token->lexeme);
}

void	print_tokenLst(t_tokenLst *tokenLst)
{
	while (tokenLst && tokenLst->next)
	{
		print_Token(tokenLst->token);
		tokenLst = tokenLst->next;
	}
	print_Token(tokenLst->token);
	printf("\n");
}

static void	print_PT(t_ASTree *tree, int indent)
{
	t_ASTree	*sibl;
	t_ASTree	*chld;
	int			space;

	space = indent;
	if (tree)
	{
		while (--space >= 0)
			printf(" ");
		print_Token(tree->data);
		printf("\n");
		space = indent + PRN_PTREE_INDENT;
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
