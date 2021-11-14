/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclam <mclam@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 23:05:22 by mclam             #+#    #+#             */
/*   Updated: 2021/11/10 23:05:22 by mclam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_eTree	*alloc_etree_node(char *name, char *vol)
{
	t_eTree	*node;

	node = ft_calloc_lc(sizeof(t_eTree), 1);
	node->name = name;
	node->vol = vol;
	return (node);
}

static char	**split_env(char *env)
{
	char	**split;

	if (env != NULL && *env != 0 && *env != '=')
	{
		split = ft_calloc_lc(sizeof(char *), 2);
		split[0] = ft_strdup_lc(env);
		split[1] = ft_strchr(split[0], '=');
		*(split[1]) = '\0';
		split[1] = split[1] + 1;
		return (split);
	}
	return (NULL);
}

t_eTree	*build_etree(char **env)
{
	t_eTree	*root;
	int		i;
	char	**splitenv;

	root = NULL;
	i = 0;
	while (env != NULL && env[i] != NULL)
	{
		splitenv = split_env(env[i]);
		if (splitenv != NULL)
			root = embed_etree_node(root, splitenv[0], splitenv[1]);
		else
		{
			errmsg("invalid environment variable name\n", ERROR);
			break ;
		}
		i++;
	}
	return (root);
}

void	find_etree_node(t_eTree **node, t_eTree *root, char *name)
{
	int	cond;

	if (root != NULL)
	{
		cond = ft_strcmp(name, root->name);
		while (cond != 0)
		{
			if (cond < 0)
				root = root->left;
			else
				root = root->right;
			if (root == NULL)
				break ;
			cond = ft_strcmp(name, root->name);
		}
		*node = root;
	}
	else
		*node = NULL;
}

void	find_etree_node_r(t_eTree **node, t_eTree *root, char *name)
{
	if (root != NULL)
	{
		find_etree_node_r(node, root->left, name);
		if (ft_strcmp(name, root->name) == SUCCESS)
		{
			*node = root;
			return ;
		}
		find_etree_node_r(node, root->right, name);
	}
}
