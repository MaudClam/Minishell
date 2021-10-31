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

# define PARSING_ERROR		-1
# define SUBTREE_SUCCESS	0
# define PRN_PTREE_INDENT	2

typedef enum e_TokenType	t_TokenType;
typedef struct s_Token		t_Token;
typedef struct s_TokenList	t_TokenList;
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
int			build_ASTree(t_TokenList **tokenList, t_ASTree **tree);
t_ASTree	*alloc_ASTree(void);
int			is_PIPE_SEQUENCE(t_TokenList **tokenList, t_ASTree **tree);
int			is_COMMAND(t_TokenList **tokenList, t_ASTree **tree);
int			is_COMMAND_PREFIX(t_TokenList **tokenList, t_ASTree **tree);
/*
** 			parser1.c
*/
int			is_COMMAND_WORD(t_TokenList **tokenList, t_ASTree **tree);
int			is_COMMAND_SUFFIX(t_TokenList **tokenList, t_ASTree **tree);

#endif
