/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclam <mclam@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 20:15:12 by mclam             #+#    #+#             */
/*   Updated: 2021/10/20 20:15:12 by mclam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_ParseTree	*alloc_ParseTree(void)
{
	t_ParseTree	*tree;

	tree = ft_calloc_lc(sizeof(t_ParseTree), 1);
	if (!tree)
		err_exit(MEMORY_ERROR, errno);
	return (tree);
}

static void	print_PT(t_ParseTree *tree, int indent)
{
	t_ParseTree	*sibling;
	t_ParseTree	*child;

	if (tree)
	{
		while (--indent >= 0)
			ft_putchar_fd(' ', STDOUT_FILENO);
		print_Token(tree->data);
		sibling = tree->sibling;
		child = tree->child;
		print_PT(child, indent + PRN_PTREE_INDENT);
		print_PT(sibling, indent);
	}
}

void	print_ParseTree(t_ParseTree *tree)
{
	print_PT(tree, 0);
}
