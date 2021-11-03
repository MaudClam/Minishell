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

typedef enum e_TokenType		t_TokenType;
typedef struct s_Token			t_Token;
typedef struct s_tokenLst		t_tokenLst;
typedef struct s_ASTree			t_ASTree;
typedef struct s_var			t_var;

# define TOKEN_TYPES_SET		"EMPTY,BLANK,WORD,PIPE_SYMBOL,REDIRECT_SYMBOL,\
COMMAND_OPTION,COMMAND_PREFIX,COMMAND,COMMAND_WORD,COMMAND_SUFFIX,VARIABLE,\
PIPE_SEQUENCE,IO_REDIRECT,IO_FILE,IO_HERE,HERE_END,FILENAME,IO_NUMBER,END"
# define BLANK_CHARSET			" \t\n\v\f\r"
# define QUOTES_CHARSET			"\"\'"
# define WORD_CHARSET			"!$#%&()*+,-./=?_\
0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"
# define PIPE_CHARSET 			"|"
# define REDIRECT_CHARSET		"<>"
# define COMMAND_OPTION_CHARSET	"-"

enum e_TokenType
{
	EMPTY,
	BLANK,
	WORD,
	PIPE_SYMBOL,
	REDIRECT_SYMBOL,
	COMMAND_OPTION,
	COMMAND_PREFIX,
	COMMAND,
	COMMAND_WORD,
	COMMAND_SUFFIX,
	VARIABLE,
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

struct s_tokenLst
{
	t_Token		*token;
	t_tokenLst	*next;
};

/*
**		lexer.c
*/
void	build_tokenLst(t_var *v);
t_Token	*new_token(char *lexeme, t_TokenType type);
t_Token	*new_tokenAdd(char *lexeme, t_TokenType type, t_tokenLst **tokenLst);
void	tokenAdd_back(t_tokenLst **tokenLst, t_Token *token);
size_t	lexeme_BLANK(const char *str);
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
int		checkToken_steptokenLst(t_tokenLst **tokenLst, t_ASTree **tree, \
												t_TokenType type, char *lexeme);
int		is_PIPE_SYMBOL(t_tokenLst **tokenLst, t_ASTree **tree);
int		is_REDIRECT_SYMBOL(t_tokenLst **tokenLst, t_ASTree **tree);
int		is_END(t_tokenLst **tokenLst, t_ASTree **tree);
int		is_WORD(t_tokenLst **tokenLst, t_ASTree **tree);

#endif
