/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclam <mclam@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 22:58:27 by mclam             #+#    #+#             */
/*   Updated: 2021/11/04 22:58:27 by mclam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** The function displays an error message consisting of a program prompt and a
** message passed as an argument str.
** The first call to the function creates a copy of the argument str, which
** will be used as a prompt for further calls to the function.
** The first call to the function displays nothing, the function returns 0.
** Other calls return the argument err.
*/
int	errmsg(char *str, int err)
{
	static char	*prompt;
	char		*errmsg;

	if (prompt == NULL)
	{
		prompt = ft_strdup_lc(str);
		if (prompt == NULL)
			error_exit(strerror(ENOMEM), ENOMEM);
		return (SUCCESS);
	}
	errmsg = ft_strjoin_lc(prompt, str);
	if (errmsg == NULL)
		error_exit(strerror(ENOMEM), ENOMEM);
	ft_putstr_fd(errmsg, STDERR_FILENO);
	return (err);
}

int	errmsg2(char *str1, char *str2, int err)
{
	errmsg(str1, err);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putstr_fd(str2, STDERR_FILENO);
	return (err);
}

void	syntax_errmsg(char *str)
{
	char	*msg;

	msg = ft_strjoin_lc("syntax error near unexpected token '", str);
	if (msg == NULL)
		error_exit(strerror(ENOMEM), ENOMEM);
	msg = ft_strjoin_lc(msg, "'\n");
	if (msg == NULL)
		error_exit(strerror(ENOMEM), ENOMEM);
	errmsg(msg, ERROR);
}

int	error_exit(char *str, int err)
{
	errmsg(str, err);
	ft_putstr_fd(" (exit code: ", STDERR_FILENO);
	ft_putnbr_fd(err, STDERR_FILENO);
	ft_putstr_fd(")\n", STDERR_FILENO);
	lc(FREE_ALL);
	exit (err);
}

int	error_exit2(char *str1, char *str2, int err)
{
	errmsg(str1, err);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putstr_fd(str2, STDERR_FILENO);
	ft_putstr_fd(" (exit code: ", STDERR_FILENO);
	ft_putnbr_fd(err, STDERR_FILENO);
	ft_putstr_fd(")\n", STDERR_FILENO);
	lc(FREE_ALL);
	exit (err);
}
