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

int	build_tokenList(char *line, t_TokenLst **tokenLst)
{
	size_t	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (ft_isinset(line[i], QUOTES_CHARSET) == TRUE && \
			quoted_word(&line, &i, tokenLst) != SUCCESS)
			return (ERROR);
		else if (ft_isinset(line[i], WORD_CHARSET) == TRUE)
			i += lexeme_WORD(&line[i], tokenLst);
		else if (ft_isinset(line[i], PIPE_CHARSET) == TRUE)
			i += lexeme_PIPE_SYMBOL(&line[i], tokenLst);
		else if (ft_isinset(line[i], REDIRECT_CHARSET) == TRUE)
			i += lexeme_REDIRECT_SYMBOL(&line[i], tokenLst);
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
	tokenAdd_back(tokenLst, token);
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
		ft_error_exit(strerror(ENOMEM), ENOMEM);
	return (token);
}

void	tokenAdd_back(t_TokenLst **tokenLst, t_Token *token)
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
		ft_error_exit(strerror(ENOMEM), ENOMEM);
}

int	join_newReadline(char **line)
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
		ft_error_exit(strerror(ENOMEM), ENOMEM);
	return (SUCCESS);
}
