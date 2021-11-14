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
		return (SUCCESS);
	}
	errmsg = ft_strjoin_lc(prompt, str);
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

	msg = ft_strjoin3_lc("syntax error near unexpected token '", str, "'\n");
	errmsg(msg, ERROR);
}
