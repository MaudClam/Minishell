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
typedef struct s_ParseTree	t_ParseTree;
typedef struct s_var		t_var;

struct s_var
{
	int				fd;
	int				status;
	int				exit;
	char			**env;
	char			*line;
	unsigned int	offset;
	t_ParseTree		*tree;
	t_TokenList		*tokenList;
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
# define MEMORY_ERROR	"unable to allocate memory"
/*
** 		utils.c
*/
int		do_exit(char *str);
int		err_exit(char *str, int err);
char	*get_env(char **env, char *name);
void	handle_ctrlc(int status);
void	handle_ctrlc_(int status);
/*
** 		utils1.c
*/
char	*type2char(t_TokenType type);

#endif
