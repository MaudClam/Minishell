/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclam <mclam@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 20:15:31 by mclam             #+#    #+#             */
/*   Updated: 2021/10/20 20:15:31 by mclam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "minishell.h"

# define PARSING_ERROR		-2
# define SUBTREE_SUCCESS	0
# define PRN_PTREE_INDENT	4
# define SYNTAX_ERR			"minishell: syntax error near unexpected token '"

typedef enum e_TokenType	t_TokenType;
typedef struct s_Token		t_Token;
typedef struct s_TokenLst	t_TokenLst;
typedef struct s_ASTree		t_ASTree;
typedef struct s_var		t_var;

struct s_ASTree
{
	t_Token			*data;
	t_ASTree		*chld;
	t_ASTree		*sibl;
};
/*
** 			parser.c
*/
int			build_ASTree(t_TokenLst **tokenLst, t_ASTree **tree);
t_ASTree	*alloc_ASTree(void);
t_ASTree	*alloc_ASTreeToken(char *lexeme, t_TokenType type);
int			is_PIPE_SEQUENCE(t_TokenLst **tokenLst, t_ASTree **tree);
int			is_COMMAND(t_TokenLst **tokenLst, t_ASTree **tree);
/*
** 			parser1.c
*/
int			is_COMMAND_PREFIX(t_TokenLst **tokenLst, t_ASTree **tree);
int			is_COMMAND_WORD(t_TokenLst **tokenLst, t_ASTree **tree);
int			is_COMMAND_SUFFIX(t_TokenLst **tokenLst, t_ASTree **tree);
int			is_IO_REDIRECT(t_TokenLst **tokenLst, t_ASTree **tree);
int			is_IO_FILE(t_TokenLst **tokenLst, t_ASTree **tree);
/*
** 			parser2.c
*/
int			is_IO_HERE(t_TokenLst **tokenLst, t_ASTree **tree);
int			is_HERE_END(t_TokenLst **tokenLst, t_ASTree **tree);
int			is_FILENAME(t_TokenLst **tokenLst, t_ASTree **tree);
int			is_IO_NUMBER(t_TokenLst **tokenLst, t_ASTree **tree);

#endif
