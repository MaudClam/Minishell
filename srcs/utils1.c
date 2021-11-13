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

#include "minishell.h"

static void	print_Token(t_Token *token)
{
	if (token->lexeme == NULL)
		printf("<%s> ", type2char(token->type));
	else
		printf("<%s "BOLD"%s"DEFAULT"> ", type2char(token->type), \
																token->lexeme);
}

void	print_TokenLst(t_TokenLst *tokenLst)
{
	if (tokenLst)
	{
		printf(BOLD"tokenList: "DEFAULT);
		while (tokenLst->next)
		{
			print_Token(tokenLst->token);
			tokenLst = tokenLst->next;
		}
		print_Token(tokenLst->token);
		printf("\n");
	}
}

static void	print_PT(t_ASTree *tree, int indent)
{
	t_ASTree	*sibl;
	t_ASTree	*chld;
	int			i;

	i = indent;
	if (tree != NULL)
	{
		while (--i >= 0)
			printf(" ");
		print_Token(tree->data);
		printf("\n");
		sibl = tree->sibl;
		chld = tree->chld;
		print_PT(chld, indent + PRN_PTREE_INDENT);
		print_PT(sibl, indent);
	}
}

void	print_astree(t_ASTree *tree)
{
	printf(BOLD"ASTree:\n"DEFAULT);
	print_PT(tree, 0);
}

void	print_welcomemsg(void)
{
	printf("Welcome!\n");
}
