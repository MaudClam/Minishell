/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclam <mclam@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 03:49:50 by mclam             #+#    #+#             */
/*   Updated: 2021/10/24 03:49:50 by mclam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

void	print_Token(t_Token *token)
{
	printf("<'%s', %s>\n", token->lexeme, type2char(token->type));
}

int	singleTokenTemplate(t_TokenList **token, t_ParseTree **tree, \
												t_TokenType type, char *lexeme)
{
	t_TokenList	*current;
	t_Token		*newToken;

	if (!token || !*token || !tree || !*tree || lexeme)
		return (PARSING_ERROR);
	current = *token;
	if (current->token->type != type)
	{
		printf("Expecting <%s>, Found <%s>\n", type2char(type), \
											type2char(current->token->type));
		return (PARSING_ERROR);
	}
	if (ft_strcmp(current->token->lexeme, lexeme))
	{
		printf("Expecting %s, Found %s\n", lexeme, current->token->lexeme);
		return (PARSING_ERROR);
	}
	newToken = new_token(current->token->lexeme, current->token->type);
	(*tree)->data = newToken;
	(*tree)->child = NULL;
	(*tree)->sibling = NULL;
	*token = current->next;
	return (SUBTREE_SUCCESS);
}
