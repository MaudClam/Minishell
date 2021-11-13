/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclam <mclam@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 15:20:54 by mclam             #+#    #+#             */
/*   Updated: 2021/11/06 15:20:54 by mclam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** The function returns a pointer to a NUL terminated string containing the
** value of the variable named in the 'name'.
*/
char	*get_env(t_eTree *root, char *name)
{
	t_eTree	*node;

	node = NULL;
	if (root != NULL && name != NULL)
	{
		find_etree_node_r(&node, root, name);
		if (node != NULL)
			return (node->vol);
	}
	return ("");
}

static int	unset1_env(t_eTree *root, t_eTree **ret)
{
	if (root->left == root->right)
	{
		*ret = NULL;
		return (TRUE);
	}
	else if (root->left == NULL)
	{
		*ret = root->right;
		return (TRUE);
	}
	else if (root->right == NULL)
	{
		*ret = root->left;
		return (TRUE);
	}
	else
	{
		*ret = root->right;
		root = root->right;
		while (root->left)
			root = root->left;
		return (TRUE);
	}
	return (FALSE);
}

t_eTree	*unset_env(t_eTree *root, char *name)
{
	t_eTree	*ret;

	if (root == NULL)
		return (root);
	if (ft_strcmp(name, root->name) == SUCCESS)
	{
		if (unset1_env(root, &ret) == TRUE)
			return (ret);
	}
	if (ft_strcmp(name, root->name) > 0)
		root->right = unset_env(root->right, name);
	else
		root->left = unset_env(root->left, name);
	return (root);
}

t_eTree	*embed_etree_node(t_eTree *node, char *name, char *vol)
{
	int	cond;

	if (node != NULL)
	{
		cond = ft_strcmp(name, node->name);
		if (cond < 0)
			node->left = embed_etree_node(node->left, name, vol);
		else if (cond == 0)
			node->vol = vol;
		else
			node->right = embed_etree_node(node->right, name, vol);
	}
	else
		node = alloc_etree_node(name, vol);
	return (node);
}
