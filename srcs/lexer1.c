/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclam <mclam@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 13:13:05 by mclam             #+#    #+#             */
/*   Updated: 2021/10/22 13:13:05 by mclam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

size_t	lexeme_QUOTED_WORD(const char *str, t_Token *token)
{
	size_t	i;
	char	quote;

	i = 0;
	quote = str[i++];
	while (str[i] != '\0' && str[i] != quote)
		i++;
	if (str[i] == '\0')
	{
		ft_errmsg(SYNTAX_ERROR, STDOUT_FILENO);
		return (i);
	}
	else
	{
		token->lexeme = ft_substr_lc(str, 1, i - 1);
		if (!token->lexeme)
			err_exit(MEMORY_ERROR, errno);
		else if (token->lexeme[0] == '\0')
			token->type = BLANK;
		else
			token->type = WORD;
	}
	return (i + 1);
}

size_t	lexeme_WORD(const char *str, t_Token *token)
{
	size_t	i;

	i = 0;
	while (ft_isinset(str[i], WORD_CHARSET) == TRUE)
		i++;
	token->lexeme = ft_substr_lc(str, 0, i);
	if (!token->lexeme)
		err_exit(MEMORY_ERROR, errno);
	token->type = WORD;
	return (i);
}

size_t	lexeme_PIPE_SYMBOL(const char *str, t_Token *token)
{
	token->lexeme = ft_substr_lc(&str[0], 0, 1);
	if (!token->lexeme)
		err_exit(MEMORY_ERROR, errno);
	token->type = PIPE_SYMBOL;
	return (1);
}

size_t	lexeme_REDIRECT_SYMBOL(const char *str, t_Token *token)
{
	token->lexeme = ft_substr_lc(str, 0, 2);
	if (!token->lexeme)
		err_exit(MEMORY_ERROR, errno);
	if (ft_strcmp(token->lexeme, "<<") == SUCCESS || \
									ft_strcmp(token->lexeme, ">>") == SUCCESS)
	{
		token->type = REDIRECT_SYMBOL;
		return (2);
	}
	else
	{
		token->lexeme[1] = '\0';
		token->type = REDIRECT_SYMBOL;
		return (2);
	}
	return (0);
}

size_t	lexeme_COMMAND_OPTION(const char *str, t_Token *token)
{
	size_t	i;

	i = 1;
	while (ft_isinset(str[i], WORD_CHARSET) == TRUE)
		i++;
	token->lexeme = ft_substr_lc(str, 0, i);
	if (!token->lexeme)
		err_exit(MEMORY_ERROR, errno);
	token->type = COMMAND_OPTION;
	return (i);
}
