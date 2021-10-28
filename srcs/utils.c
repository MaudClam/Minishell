/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclam <mclam@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 01:42:56 by mclam             #+#    #+#             */
/*   Updated: 2021/10/22 01:42:56 by mclam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	do_exit(char *str)
{
	ft_putstr_fd(str, STDOUT_FILENO);
	lc(FREE_ALL);
	exit(EXIT_SUCCESS);
}

int	err_exit(char *str, int err)
{
	ft_errmsg(str, err);
	exit(EXIT_FAILURE);
}

/*
** The function returns a pointer to a NUL terminated string containing the
** value of the variable named in the 'name'.
*/
char	*get_env(char **env, char *name)
{
	int		i;
	char	**split;
	char	*getenv;

	i = 0;
	getenv = NULL;
	lc(FIX_POINTER);
	while (env && env[i])
	{
		split = ft_splitset_lc(env[i], "=");
		if (!split)
			err_exit(MEMORY_ERROR, errno);
		if (ft_strcmp(split[0], name) == SUCCESS)
		{
			getenv = ft_strdup(split[1]);
			if (!getenv)
				err_exit(MEMORY_ERROR, errno);
			lc(FREE_TO_FIX);
			return (lc(getenv));
		}
		i++;
	}
	lc(FREE_TO_FIX);
	return ("");
}

void	handle_ctrlc(int status)
{
	ft_putendl_fd("", STDOUT_FILENO);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
	(void)status;
}

void	handle_ctrlc_(int status)
{
	ft_putendl_fd("", STDOUT_FILENO);
	(void)status;
}
