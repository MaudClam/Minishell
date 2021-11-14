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

# define TOKEN_TYPES_SET	"	empty,BLANK,WORD,PIPE_SYMBOL,REDIRECT_SYMBOL,\
END,simple_command,command_prefix,command,command_word,command_suffix,\
pipe_sequence,io_redirect,io_file,io_here,here_end,filename,io_number,"
# define BLANK_CHARSET		" \t\n\v\f\r"
# define QUOTES_CHARSET		"\"\'"
# define WORD_CHARSET		"!$#%&()*+,-./=?_\
0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"
# define PIPE_CHARSET 		"|"
# define REDIRECT_CHARSET	"<>"

enum e_TokenType
{
	empty,
	BLANK,
	WORD,
	PIPE_SYMBOL,
	REDIRECT_SYMBOL,
	END,
	simple_command,
	command_prefix,
	command,
	command_word,
	command_suffix,
	pipe_sequence,
	io_redirect,
	io_file,
	io_here,
	here_end,
	filename,
	io_number,
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
int		build_tokenlist(char *line, t_TokenLst **tokenLst);
t_Token	*new_token(char *lexeme, t_TokenType type);
t_Token	*new_tokenAdd(char *lexeme, t_TokenType type, t_TokenLst **tokenLst);
void	tokenadd_back(t_TokenLst **tokenLst, t_Token *token);
int		join_newreadline(char **line);
/*
**		lexer1.c
*/
int		quoted_word(char **line, size_t *i, t_TokenLst **tokenLst);
size_t	lexeme_word(char *str, t_TokenLst **tokenLst);
size_t	lexeme_pipe_symbol(char *str, t_TokenLst **tokenLst);
size_t	lexeme_redirect_symbol(char *str, t_TokenLst **tokenLst);
/*
**		lexer2.c
*/
int		check_token_step_tokenlst(t_TokenLst **tokenLst, t_ASTree **tree, \
												t_TokenType type, char *lexeme);
int		is_word(t_TokenLst **tokenLst, t_ASTree **tree);
int		is_pipe_symbol(t_TokenLst **tokenLst, t_ASTree **tree);
int		is_redirect_symbol(t_TokenLst **tokenLst, t_ASTree **tree);
int		is_end(t_TokenLst **tokenLst, t_ASTree **tree);

#endif
