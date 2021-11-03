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
	v->tree = NULL;
	v->offset = 0;
	build_tokenLst(v);
	if (v->debug == TRUE)
		print_tokenLst(v->tokenLst);
	if (v->tokenLst->token->type != END)
		if (build_ASTree(&v->tokenLst, &v->tree) == SUCCESS)
			execute_ASTree(v);
	if (v->debug == TRUE)
		print_ASTree(v->tree);
}

static char	*prompt(t_var *v, char *s1, char *s2, char *s3)
{
	char	*prompt;

	prompt = ft_strjoin_lc(ft_strjoin_lc(s1, get_env(v->env, s2)), s3);
	if (prompt == NULL)
		ft_error_exit(strerror(ENOMEM), ENOMEM);
	return (prompt);
}

static void	init_var(t_var *v, int argc, char **argv, char **env)
{
	int	i;

	ft_bzero(v, sizeof(t_var));
	if (argc > 0 && ft_strcmp(argv[1], DEBUG_OPTION) == SUCCESS)
	{
		v->debug = TRUE;
		v->line = type2char(0);
	}
	v->fd = dup(1);
	i = 0;
	while (env && env[i])
		i++;
	v->env = lc(malloc(sizeof(char *) * (i + 1)));
	if (v->env)
	{
		v->env[i] = NULL;
		while (i--)
		{
			v->env[i] = ft_strdup_lc(env[i]);
			if (v->env[i] == NULL)
				ft_error_exit(strerror(ENOMEM), ENOMEM);
		}
	}
	else
		ft_error_exit(strerror(ENOMEM), ENOMEM);
}

int	main(int argc, char **argv, char **env)
{
	t_var	v;

	rl_catch_signals = 0;
	signal(SIGQUIT, SIG_IGN);
	init_var(&v, argc, argv, env);
	lc(FIX_POINTER);
	while (!v.exit)
	{
		signal(SIGINT, handle_ctrlc);
		v.line = lc(readline(prompt(&v, PROMPT_S1, PROMPT_S2, PROMPT_S3)));
		if (v.line == NULL)
			do_exit("exit\n");
		signal(SIGINT, handle_ctrlc_);
		if (v.line && *v.line)
		{
			add_history(v.line);
			minishell(&v);
		}
		lc(FREE_TO_FIX);
	}
	lc(FREE_ALL);
	return (0);
}
