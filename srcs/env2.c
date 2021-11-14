/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclam <mclam@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 23:14:44 by mclam             #+#    #+#             */
/*   Updated: 2021/11/10 23:14:44 by mclam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t	etree_counter(t_eTree *root, size_t *i)
{
	if (root != NULL)
	{
		etree_counter(root->left, i);
		(*i)++;
		etree_counter(root->right, i);
	}
	return (*i);
}

static void	etree_to_env1(t_eTree *root, size_t *i, char **env)
{
	if (root != NULL)
	{
		etree_to_env1(root->left, i, env);
		env[*i] = ft_strjoin3_lc(root->name, "=", root->vol);
		(*i)++;
		etree_to_env1(root->right, i, env);
	}
}

char	**etree_to_env(t_eTree *root)
{
	char	**env;
	size_t	i;

	env = NULL;
	if (root != NULL)
	{
		i = 0;
		i = etree_counter(root, &i);
		env = ft_calloc_lc(sizeof(char *), i + 1);
		i = 0;
		etree_to_env1(root, &i, env);
	}
	return (env);
}
