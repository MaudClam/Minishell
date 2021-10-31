/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclam <mclam@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 17:48:35 by mclam             #+#    #+#             */
/*   Updated: 2021/10/20 17:48:35 by mclam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# ifndef READLINE_LIBRARY
#  define READLINE_LIBRARY "/usr/local/Cellar/readline/8.1.1"
# endif

# include <stdio.h>
# include <sys/signal.h>
# include <readline.h>
# include <history.h>
# include "libft.h"
# include "lexer.h"
# include "parser.h"

typedef enum e_TokenType	t_TokenType;
typedef struct s_Token		t_Token;
typedef struct s_TokenList	t_TokenList;
typedef struct s_ASTree	t_ASTree;
typedef struct s_var		t_var;

struct s_var
{
	int				fd;
	int				status;
	int				exit;
	char			**env;
	char			*line;
	unsigned int	offset;
	t_TokenList		*tokenList;
	t_ASTree		*tree;
};

# define TRUE			1
# define FALSE			0
# define ERROR			-1
# define SUCCESS		0
# define DEFAULT		"\033[0m"
# define BOLD			"\033[1m"
# define YELLOW			"\033[33m"
# define GREEN			"\033[32m"
# define GRAY			"\033[37m"
# define TURQUOISE		"\033[36m"
# define RED			"\033[31m"
/*
** 		executer.c
*/
void	execute_ASTree(t_var *v);
/*
** 		utils.c
*/
int		do_exit(char *str);
char	*get_env(char **env, char *name);
void	handle_ctrlc(int status);
void	handle_ctrlc_(int status);
char	*type2char(t_TokenType type);
/*
** 		utils1.c
*/
void	print_Token(t_Token *token);
void	print_TokenList(t_TokenList *tokenList);
void	print_ASTree(t_ASTree *tree);

#endif
