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
typedef struct s_ParseTree	t_ParseTree;
typedef struct s_var		t_var;

struct s_ParseTree
{
	t_Token			*data;
	t_ParseTree		*child;
	t_ParseTree		*sibling;
};

t_ParseTree	*alloc_ParseTree(void);
void		print_ParseTree(t_ParseTree *tree);
void		free_ParseTree(t_ParseTree *tree);
int			build_ParseTree(t_TokenList *head, t_ParseTree **tree);
int			build_ParseTree_FromFile(const char *fileName, t_ParseTree **tree);

#endif
