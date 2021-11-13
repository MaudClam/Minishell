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
int			build_astree(t_TokenLst **tokenLst, t_ASTree **tree);
t_ASTree	*alloc_astree(void);
t_ASTree	*alloc_ast_token(char *lexeme, t_TokenType type);
int			is_pipe_sequence(t_TokenLst **tokenLst, t_ASTree **tree);
int			is_command(t_TokenLst **tokenLst, t_ASTree **tree);
/*
** 			parser1.c
*/
int			is_command_prefix(t_TokenLst **tokenLst, t_ASTree **tree);
int			is_command_word(t_TokenLst **tokenLst, t_ASTree **tree);
int			is_command_suffix(t_TokenLst **tokenLst, t_ASTree **tree);
int			is_io_redirect(t_TokenLst **tokenLst, t_ASTree **tree);
int			is_io_file(t_TokenLst **tokenLst, t_ASTree **tree);
/*
** 			parser2.c
*/
int			is_io_here(t_TokenLst **tokenLst, t_ASTree **tree);
int			is_here_end(t_TokenLst **tokenLst, t_ASTree **tree);
int			is_filename(t_TokenLst **tokenLst, t_ASTree **tree);
int			is_io_number(t_TokenLst **tokenLst, t_ASTree **tree);
size_t		ast_counter(t_ASTree *node, size_t *i, t_TokenType type, \
														t_TokenType excl_type);
/*
** 			parser3.c
*/
t_ASTree	**make_ast_arr(t_ASTree *node, t_TokenType type, t_ASTree **arr);
char		**make_argv(t_ASTree *command);

#endif
