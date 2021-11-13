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

static char	*unquoter(char **line, size_t *i)
{
	char			quote;
	char			*str;
	unsigned int	start;

	quote = (*line)[(*i)++];
	str = NULL;
	start = (unsigned int)(*i);
	while ((*line)[*i] != '\0' && (*line)[*i] != quote)
		(*i)++;
	if ((*line)[*i] == '\0')
	{
		if (join_newreadline(line) != SUCCESS)
			return (NULL);
		*i = start - 1;
		str = unquoter(line, i);
	}
	else
	{
		str = ft_substr_lc(*line, start, (*i)++ - start);
		if (str == NULL)
			error_exit(strerror(ENOMEM), ENOMEM);
	}
	add_history(*line);
	return (str);
}

int	quoted_word(char **line, size_t *i, t_TokenLst **tokenLst)
{
	char	*lexeme;
	char	*unquoted;

	lexeme = NULL;
	unquoted = NULL;
	while (ft_isinset((*line)[*i], QUOTES_CHARSET) == TRUE)
	{
		unquoted = unquoter(line, i);
		if (unquoted == NULL)
			return (ERROR);
		lexeme = ft_strjoin_lc(lexeme, unquoted);
		if (lexeme == NULL)
			error_exit(strerror(ENOMEM), ENOMEM);
	}
	if (lexeme != NULL && lexeme[0] != '\0')
		new_tokenAdd(lexeme, WORD, tokenLst);
	return (SUCCESS);
}

size_t	lexeme_word(char *str, t_TokenLst **tokenLst)
{
	int		i;
	char	*lexeme;

	i = 0;
	while (ft_isinset(str[i], WORD_CHARSET) == TRUE)
		i++;
	lexeme = ft_substr_lc(str, 0, i);
	if (lexeme == NULL)
		error_exit(strerror(ENOMEM), ENOMEM);
	new_tokenAdd(lexeme, WORD, tokenLst);
	return (i);
}

size_t	lexeme_pipe_symbol(char *str, t_TokenLst **tokenLst)
{
	char	*lexeme;

	lexeme = ft_substr_lc(&str[0], 0, 1);
	if (lexeme == NULL)
		error_exit(strerror(ENOMEM), ENOMEM);
	new_tokenAdd(lexeme, PIPE_SYMBOL, tokenLst);
	return (1);
}

size_t	lexeme_redirect_symbol(char *str, t_TokenLst **tokenLst)
{
	char	*lexeme;

	lexeme = ft_substr_lc(str, 0, 2);
	if (lexeme && (ft_strcmp(lexeme, "<<") == SUCCESS || \
				   ft_strcmp(lexeme, ">>") == SUCCESS))
	{
		new_tokenAdd(lexeme, REDIRECT_SYMBOL, tokenLst);
		return (2);
	}
	else if (lexeme == NULL)
		error_exit(strerror(ENOMEM), ENOMEM);
	lexeme = ft_substr_lc(str, 0, 1);
	if (lexeme && (ft_strcmp(lexeme, "<") == SUCCESS || \
				   ft_strcmp(lexeme, ">") == SUCCESS))
	{
		new_tokenAdd(lexeme, REDIRECT_SYMBOL, tokenLst);
		return (1);
	}
	else if (lexeme == NULL)
		error_exit(strerror(ENOMEM), ENOMEM);
	return (0);
}
