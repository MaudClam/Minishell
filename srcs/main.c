/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclam <mclam@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 17:43:12 by mclam             #+#    #+#             */
/*   Updated: 2021/10/20 17:43:12 by mclam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	minishell(t_var *v)
{
	v->tokenLst = NULL;
	if (build_tokenlist(v->line, &v->tokenLst) == SUCCESS)
	{
		if (v->debug == TRUE)
			print_TokenLst(v->tokenLst);
		v->tree = NULL;
		if (v->tokenLst->token->type != END)
		{
			if (build_astree(&v->tokenLst, &v->tree) == SUCCESS)
			{
				if (v->debug == TRUE)
					print_astree(v->tree);
//				execute_astree(v);
			}
		}
	}
}

static char	*prompt(t_var *v, char *s1, char *s2, char *s3)
{
	char	*prompt;

	prompt = ft_strjoin3_lc(s1, get_env(v->etree, s2), s3);
	return (prompt);
}

static void	init_var(t_var *v, int argc, char **argv, char **env)
{
	ft_bzero(v, sizeof(t_var));
	if (argc > 1 && ft_strcmp(argv[1], DEBUG_OPTION) == SUCCESS)
		v->debug = TRUE;
	else
		print_welcomemsg();
	v->etree = build_etree(env);
	v->fd[0] = dup(0);
	v->fd[1] = dup(1);
	v->fd[2] = dup(2);
	embed_etree_node(v->etree, "?", "0");
	v->prompt = prompt(v, PROMPT_S1, PROMPT_S2, PROMPT_S3);
	errmsg(v->prompt, 0);
//	print_etree(v->etree);
//	print_array(v->env);
//	size_t	i = 0;
//	printf("%zu\n", etree_counter(v->etree, &i));
}

int	main(int argc, char **argv, char **env)
{
	t_var	v;

	rl_catch_signals = 0;
	signal(SIGQUIT, SIG_IGN);
	init_var(&v, argc, argv, env);
	lc(PUT_HARDBARRIER);
	while (v.exit == FALSE)
	{
		signal(SIGINT, handle_ctrlc);
		v.line = lc(readline(v.prompt));
		if (v.line == NULL)
			break ;
		if (*v.line != '\0')
		{
			add_history(v.line);
			signal(SIGINT, handle_ctrlc_);
			minishell(&v);
		}
		lc(FREE_TO_BARRIER);
	}
	ft_putstr_fd("exit\n", STDOUT_FILENO);
	lc(FREE_ALL);
	return (SUCCESS);
}
