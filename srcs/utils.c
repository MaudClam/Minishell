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
		if (split && ft_strcmp(split[0], name) == SUCCESS)
		{
			getenv = ft_strdup(split[1]);
			if (getenv == NULL)
				ft_error_exit(strerror(ENOMEM), ENOMEM);
			lc(FREE_TO_FIX);
			return (lc(getenv));
		}
		else if (split == NULL)
			ft_error_exit(strerror(ENOMEM), ENOMEM);
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
	rl_on_new_line();
	(void)status;
}

char	*type2char(t_TokenType type)
{
	static char		**tokenTypes;
	static size_t	arrsize;

	if (tokenTypes == NULL)
	{
		tokenTypes = ft_splitset_lc(TOKEN_TYPES_SET, ",; |");
		if (tokenTypes)
			arrsize = ft_arrsize((const void **)tokenTypes);
	}
	if (tokenTypes && type >= 0 && type < arrsize)
		return (tokenTypes[type]);
	else if (tokenTypes == NULL)
		ft_error_exit(strerror(ENOMEM), ENOMEM);
	ft_putendl_fd("Error: forbidden argument in type2char()", STDOUT_FILENO);
	return (NULL);
}
