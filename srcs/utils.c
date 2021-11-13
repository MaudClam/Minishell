/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclam <mclam@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 01:42:56 by mclam             #+#    #+#             */
/*   Updated: 2021/11/07 22:34:13 by mclam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	do_exit(char *str)
{
	ft_putstr_fd(str, STDOUT_FILENO);
	lc(FREE_ALL);
	exit(EXIT_SUCCESS);
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
		lc(PUT_BARRIER);
		tokenTypes = ft_splitset_lc(TOKEN_TYPES_SET, ",; |");
		if (tokenTypes != NULL)
			arrsize = ft_arrsize((const void **)tokenTypes);
		lc(MOVE_PTRS_TO_BEGIN);
	}
	if (tokenTypes != NULL && type >= 0 && type < arrsize)
		return (tokenTypes[type]);
	else if (tokenTypes == NULL)
		error_exit(strerror(ENOMEM), ENOMEM);
	ft_putendl_fd("Error: forbidden argument in type2char()", STDERR_FILENO);
	return (NULL);
}
