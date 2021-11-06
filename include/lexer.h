/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclam <mclam@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 19:45:20 by mclam             #+#    #+#             */
/*   Updated: 2021/10/20 19:45:20 by mclam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include "minishell.h"

typedef enum e_TokenType	t_TokenType;
typedef struct s_Token		t_Token;
typedef struct s_TokenLst	t_TokenLst;
typedef struct s_ASTree		t_ASTree;
typedef struct s_var		t_var;

# define TOKEN_TYPES_SET	"EMPTY,WORD,PIPE_SYMBOL,REDIRECT_SYMBOL,\
COMMAND_PREFIX,COMMAND,COMMAND_WORD,COMMAND_SUFFIX,PIPE_SEQUENCE,IO_REDIRECT,\
IO_FILE,IO_HERE,HERE_END,FILENAME,IO_NUMBER,END"
# define BLANK_CHARSET		" \t\n\v\f\r"
# define QUOTES_CHARSET		"\"\'"
# define WORD_CHARSET		"!$#%&()*+,-./=?_\
0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"
# define PIPE_CHARSET 		"|"
# define REDIRECT_CHARSET	"<>"

enum e_TokenType
{
	EMPTY,
	WORD,
	PIPE_SYMBOL,
	REDIRECT_SYMBOL,
	COMMAND_PREFIX,
	COMMAND,
	COMMAND_WORD,
	COMMAND_SUFFIX,
	PIPE_SEQUENCE,
	IO_REDIRECT,
	IO_FILE,
	IO_HERE,
	HERE_END,
	FILENAME,
	IO_NUMBER,
	END,
};

struct s_Token
{
	char		*lexeme;
	t_TokenType	type;
};

struct s_TokenLst
{
	t_Token		*token;
	t_TokenLst	*next;
};

/*
**		lexer.c
*/
int		build_tokenList(char *line, t_TokenLst **tokenLst);
t_Token	*new_token(char *lexeme, t_TokenType type);
t_Token	*new_tokenAdd(char *lexeme, t_TokenType type, t_TokenLst **tokenLst);
void	tokenAdd_back(t_TokenLst **tokenLst, t_Token *token);
int		join_newReadline(char **line);
/*
**		lexer1.c
*/
int		quoted_word(char **line, size_t *i, t_TokenLst **tokenLst);
size_t	lexeme_WORD(char *str, t_TokenLst **tokenLst);
size_t	lexeme_PIPE_SYMBOL(char *str, t_TokenLst **tokenLst);
size_t	lexeme_REDIRECT_SYMBOL(char *str, t_TokenLst **tokenLst);
/*
**		lexer2.c
*/
int		checkToken_stepTokenLst(t_TokenLst **tokenLst, t_ASTree **tree, \
												t_TokenType type, char *lexeme);
int		is_WORD(t_TokenLst **tokenLst, t_ASTree **tree);
int		is_PIPE_SYMBOL(t_TokenLst **tokenLst, t_ASTree **tree);
int		is_REDIRECT_SYMBOL(t_TokenLst **tokenLst, t_ASTree **tree);
int		is_END(t_TokenLst **tokenLst, t_ASTree **tree);

#endif
