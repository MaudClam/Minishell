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
	build_tokenList(v);
	if (v->tokenList->token->type != END)
		if(build_ASTree(&v->tokenList, &v->tree) == SUCCESS)
			execute_ASTree(v);
}

static char	*prompt(t_var *v)
{
	char	*prompt;

	prompt = ft_strjoin_lc(get_env(v->env, "PWD"), "/" BOLD " $ " DEFAULT);
	if (!prompt)
		ft_error_exit(strerror(ENOMEM), ENOMEM);
	return (prompt);
}

static void	init_var(t_var *v, char **env)
{
	int	i;

	ft_bzero(v, sizeof(t_var));
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
			if (!v->env[i])
				ft_error_exit(strerror(ENOMEM), ENOMEM);
		}
	}
	else
		ft_error_exit(strerror(ENOMEM), ENOMEM);
}

int	main(int argc, char **argv, char **env)
{
	t_var	v;

	(void)argc;
	(void)argv;
	rl_catch_signals = 0;
	signal(SIGQUIT, SIG_IGN);
	init_var(&v, env);
	lc(FIX_POINTER);
	while (!v.exit)
	{
		signal(SIGINT, handle_ctrlc);
		v.line = lc(readline(prompt(&v)));
		if (!v.line)
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
