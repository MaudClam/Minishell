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
# include <sys/stat.h>
# include "libft.h"
# include "lexer.h"
# include "parser.h"

typedef enum e_TokenType	t_TokenType;
typedef struct s_Token		t_Token;
typedef struct s_TokenLst	t_TokenLst;
typedef struct s_ASTree		t_ASTree;
typedef struct s_var		t_var;
typedef struct s_eTree		t_eTree;

struct s_var
{
	int			debug;
	int			fd[3];
	char		*prompt;
	int			status;
	char		exit;
	char		*status_str;
	char		**env;
	char		*line;
	t_eTree		*etree;
	t_TokenLst	*tokenLst;
	t_ASTree	*tree;
};

struct s_eTree
{
	char		*name;
	char		*vol;
	t_eTree		*left;
	t_eTree		*right;
};

# define TRUE			1
# define FALSE			0
# define ERROR			-1
# define SUCCESS		0
# define DEBUG_OPTION	"-d"
# define DEFAULT		"\033[0m"
# define BOLD			"\033[1m"
# define YELLOW			"\033[33m"
# define GREEN			"\033[32m"
# define GRAY			"\033[37m"
# define TURQUOISE		"\033[36m"
# define RED			"\033[31m"
# define ENV_PATH		"PATH"
# define PROMPT_S1		"minishell("
# define PROMPT_S2		"USER"
# define PROMPT_S3		"): "
/*
** 		env.c
*/
char	*get_env(t_eTree *root, char *name);
t_eTree	*unset_env(t_eTree *root, char *name);
t_eTree	*embed_etree_node(t_eTree *root, char *name, char *vol);
/*
** 		env1.c
*/
t_eTree	*alloc_etree_node(char *name, char *vol);
t_eTree	*build_etree(char **env);
void 	find_etree_node(t_eTree **node, t_eTree *root, char *name);
void	find_etree_node_r(t_eTree **node, t_eTree *root, char *name);
/*
** 		env2.c
*/
size_t	etree_counter(t_eTree *root, size_t *i);
char	**etree_to_env(t_eTree *root);
/*
** 		executer.c
*/
void	execute_astree(t_ASTree *root, t_var *v);
int		execute_pipe(t_ASTree *root, t_var *v);
//void	execute_pipe_sequence(t_ASTree *root, t_var *v);
//int		execute_command(t_ASTree *root, t_var *v);
/*
** 		executer1.c
*/
void	replace_dollar(char **argv, char **env);
int		check_command(t_var *v, char **argv);
char	**join_abspath_cmd(t_eTree *etree, char *command);
int		check_paths(char **paths, char **argv);
/*
** 		utils.c
*/
int		do_exit(char *str);
void	handle_ctrlc(int status);
void	handle_ctrlc_(int status);
char	*type2char(t_TokenType type);
/*
** 		utils1.c
*/
void	print_TokenLst(t_TokenLst *tokenLst);
void	print_astree(t_ASTree *tree);
void	print_welcomemsg(void);
/*
** 		utils2.c
*/
int		errmsg(char *str, int err);
int		errmsg2(char *str1, char *str2, int err);
void	syntax_errmsg(char *str);
/*
** 		utils3.c
*/
void	print_etree(t_eTree *root);
void	print_array(char **env);

#endif
