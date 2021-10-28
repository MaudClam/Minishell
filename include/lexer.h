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
typedef struct s_TokenList	t_TokenList;
typedef struct s_ParseTree	t_ParseTree;
typedef struct s_var		t_var;

# define TOKEN_TYPES_SET	"EMPTY,BLANK,WORD,PIPE_SYMBOL,REDIRECT_SYMBOL,\
COMMAND_OPTION,COMMAND,COMMAND_PREFIX,COMMAND_WORD,COMMAND_SUFFIX,VARIABLE,\
PIPE_SEQUENCE,REDIRECT_SEQUENCE,END,"
# define BLANK_CHARSET		" \t\n\v\f\r"
# define QUOTES_CHARSET		"\"\'"
# define WORD_CHARSET		"!$#%&()*+,-./=?_\
0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"
# define PIPE_CHARSET 		"|"
# define REDIRECT_CHARSET	"<>"
# define COMMAND_OPTION_CHARSET	"-"
# define TYPE2CHAR_ERROR	"forbidden argument in type2char()"
# define SYNTAX_ERROR		"incorrect syntax"

enum e_TokenType
{
	EMPTY,
	BLANK,
	WORD,
	PIPE_SYMBOL,
	REDIRECT_SYMBOL,
	COMMAND_OPTION,
	COMMAND,
	COMMAND_PREFIX,
	COMMAND_WORD,
	COMMAND_SUFFIX,
	VARIABLE,
	PIPE_SEQUENCE,
	REDIRECT_SEQUENCE,
	END,
};

struct s_Token
{
	char		*lexeme;
	t_TokenType	type;
};

struct s_TokenList
{
	t_Token		*token;
	t_TokenList	*next;
};

/*
**		lexer.c
*/
void	build_tokenList(t_var *v);
t_Token	*new_token(char *lexeme, t_TokenType type);
t_Token	*new_tokenAdd(char *lexeme, t_TokenType type, t_TokenList **tokenList);
void	tokenAdd_back(t_TokenList **tokenList, t_Token *token);
size_t	lexeme_BLANK(const char *str, t_Token *token);
/*
**		lexer1.c
*/
size_t	lexeme_QUOTED_WORD(const char *str, t_Token *token);
size_t	lexeme_WORD(const char *str, t_Token *token);
size_t	lexeme_PIPE_SYMBOL(const char *str, t_Token *token);
size_t	lexeme_REDIRECT_SYMBOL(const char *str, t_Token *token);
size_t	lexeme_COMMAND_OPTION(const char *str, t_Token *token);
/*
**		lexer2.c
*/
void	print_Token(t_Token *token);
int		singleTokenTemplate(t_TokenList **token, t_ParseTree **tree, \
												t_TokenType type, char *lexeme);
#endif
