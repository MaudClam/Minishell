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

int	build_tokenlist(char *line, t_TokenLst **tokenLst)
{
	size_t	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (ft_isinset(line[i], QUOTES_CHARSET) == TRUE && \
			quoted_word(&line, &i, tokenLst) != SUCCESS)
			return (ERROR);
		else if (ft_isinset(line[i], WORD_CHARSET) == TRUE)
			i += lexeme_word(&line[i], tokenLst);
		else if (ft_isinset(line[i], PIPE_CHARSET) == TRUE)
			i += lexeme_pipe_symbol(&line[i], tokenLst);
		else if (ft_isinset(line[i], REDIRECT_CHARSET) == TRUE)
			i += lexeme_redirect_symbol(&line[i], tokenLst);
		else if (ft_isinset(line[i], BLANK_CHARSET) == TRUE)
			while (ft_isinset(line[i], BLANK_CHARSET) == TRUE)
				i++;
		else
			i++;
	}
	new_tokenAdd("newline", END, tokenLst);
	return (SUCCESS);
}

t_Token	*new_tokenAdd(char *lexeme, t_TokenType type, t_TokenLst **tokenLst)
{
	t_Token	*token;

	token = new_token(lexeme, type);
	tokenadd_back(tokenLst, token);
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
		error_exit(strerror(ENOMEM), ENOMEM);
	return (token);
}

void	tokenadd_back(t_TokenLst **tokenLst, t_Token *token)
{
	t_TokenLst	*tmp;
	t_TokenLst	*new;

	tmp = *tokenLst;
	new = lc(malloc(sizeof(t_TokenLst)));
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
			*tokenLst = new;
	}
	else
		error_exit(strerror(ENOMEM), ENOMEM);
}

int	join_newreadline(char **line)
{
	char	*str;

	str = NULL;
	signal(SIGINT, handle_ctrlc);
	str = readline("> ");
	if (str == NULL)
		return (ERROR);
	*line = ft_strjoin_lc(ft_strjoin_lc(*line, "\n"), str);
	free (str);
	str = NULL;
	if (*line == NULL)
		error_exit(strerror(ENOMEM), ENOMEM);
	return (SUCCESS);
}
