/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclam <mclam@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 14:58:39 by mclam             #+#    #+#             */
/*   Updated: 2021/11/11 14:58:39 by mclam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void	ast_extractor(t_ASTree *node, size_t *i, t_TokenType type, \
																t_ASTree **arr)
{
	if (node != NULL)
	{
		if (node->data->type == type)
		{
			arr[*i] = node;
			(*i)++;
		}
		ast_extractor(node->chld, i, type, arr);
		ast_extractor(node->sibl, i, type, arr);
	}
}

t_ASTree	**make_ast_arr(t_ASTree *node, t_TokenType type, t_ASTree **arr)
{
	size_t		i;
	
	arr = NULL;
	i = 0;
	if (node != NULL)
	{
		i = ast_counter(node, &i, type, 0);
		arr = ft_calloc_lc(sizeof(t_ASTree *), i + 1);
		if (arr != NULL)
		{
			i = 0;
			ast_extractor(node, &i, type, arr);
		}
		else
			error_exit(strerror(ENOMEM), ENOMEM);
	}
	return (arr);
}

static void	argv_extractor(t_ASTree *node, size_t *i, char **argv)
{
	if (node != NULL && node->data->type != IO_REDIRECT)
	{
		if (node->data->type == COMMAND)
		{
			argv[*i] = (node->data->lexeme);
			(*i)++;
		}
		argv_extractor(node->chld, i, argv);
		argv_extractor(node->sibl, i, argv);
	}
}

char	**make_argv(t_ASTree *command)
{
	char	**argv;
	size_t	i;
	
	argv = NULL;
	i = 0;
	if (command != NULL)
	{
		i = ast_counter(command, &i, COMMAND, IO_REDIRECT);
		argv = ft_calloc_lc(sizeof(char *), i + 1);
		if (argv != NULL)
		{
			i = 0;
			argv_extractor(command, &i, argv);
		}
		else
			error_exit(strerror(ENOMEM), ENOMEM);
	}
	return(argv);
}
