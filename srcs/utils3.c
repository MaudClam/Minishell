/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclam <mclam@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 23:04:03 by mclam             #+#    #+#             */
/*   Updated: 2021/11/11 23:04:03 by mclam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_etree(t_eTree *root)
{
	if (root != NULL)
	{
		print_etree(root->left);
		printf("%s=%s\n", root->name, root->vol);
		print_etree(root->right);
	}
}

void	print_array(char **env)
{
	int	i;

	i = 0;
	while (env != NULL && env[i] != NULL)
		printf("%s\n", env[i++]);
}
