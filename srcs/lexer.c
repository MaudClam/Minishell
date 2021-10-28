/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclam <mclam@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 20:01:33 by mclam             #+#    #+#             */
/*   Updated: 2021/10/20 20:01:33 by mclam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

void	build_tokenList(t_var *v)
{
	t_Token		*token;

	token = new_tokenAdd(NULL, EMPTY, &v->tokenList);
	while (v->line[v->offset] != '\0')
	{
		if (ft_isinset(v->line[v->offset], BLANK_CHARSET) == TRUE)
			v->offset += lexeme_BLANK(&v->line[v->offset], token);
		else if (ft_isinset(v->line[v->offset], QUOTES_CHARSET) == TRUE)
			v->offset += lexeme_QUOTED_WORD(&v->line[v->offset], token);
		else if (ft_isinset(v->line[v->offset], WORD_CHARSET) == TRUE)
			v->offset += lexeme_WORD(&v->line[v->offset], token);
		else if (ft_isinset(v->line[v->offset], PIPE_CHARSET) == TRUE)
			v->offset += lexeme_PIPE_SYMBOL(&v->line[v->offset], token);
		else if (ft_isinset(v->line[v->offset], REDIRECT_CHARSET) == TRUE)
			v->offset += lexeme_REDIRECT_SYMBOL(&v->line[v->offset], token);
		else if (ft_isinset(v->line[v->offset], COMMAND_OPTION_CHARSET) == TRUE)
			v->offset += lexeme_COMMAND_OPTION(&v->line[v->offset], token);
		else
			v->offset++;
		if (token->type != BLANK)
			token = new_tokenAdd(NULL, EMPTY, &v->tokenList);
	}
	token = new_tokenAdd(NULL, END, &v->tokenList);
}

t_Token	*new_tokenAdd(char *lexeme, t_TokenType type, t_TokenList **tokenList)
{
	t_Token	*token;

	token = new_token(lexeme, type);
	tokenAdd_back(tokenList, token);
	return (token);
}

t_Token	*new_token(char *lexeme, t_TokenType type)
{
	t_Token	*token;

	token = lc(malloc(sizeof(t_Token)));
	if (token)
	{
		token->lexeme = lexeme;
		token->type = type;
	}
	else
		err_exit(MEMORY_ERROR, errno);
	return (token);
}

void	tokenAdd_back(t_TokenList **tokenList, t_Token *token)
{
	t_TokenList	*tmp;
	t_TokenList	*new;

	tmp = *tokenList;
	new = lc(malloc(sizeof(t_TokenList)));
	if (new)
	{
		new->token = token;
		new->next = NULL;
		if (tmp)
		{
			while (tmp->next)
				tmp = tmp->next;
			tmp->next = new;
		}
		else
			*tokenList = new;
	}
	else
		err_exit(MEMORY_ERROR, errno);
}

size_t	lexeme_BLANK(const char *str, t_Token *token)
{
	size_t	i;

	i = 0;
	while (ft_isinset(str[i], BLANK_CHARSET) == TRUE)
		i++;
	token->lexeme = ft_substr_lc(str, 0, i);
	if (!token->lexeme)
		err_exit(MEMORY_ERROR, errno);
	token->type = BLANK;
	return (i);
}
