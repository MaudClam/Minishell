/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclam <mclam@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 13:34:10 by mclam             #+#    #+#             */
/*   Updated: 2021/10/30 13:34:10 by mclam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execute_astree(t_ASTree *root, t_var *v)
{
	execute_pipe_sequence(root, v);
}

void	execute_pipe_sequence(t_ASTree *node, t_var *v)
{
	if (node != NULL)
	{
		if (node->data->type == COMMAND)
			execute_command(node, v);
		else if (node->data->type != END)
			if (node->sibl->data->type == PIPE_SYMBOL)
				if (node->sibl->sibl->data->type == PIPE_SEQUENCE)
						execute_pipe_sequence(node, v);
	}
}

//void	execute_command_(t_var *v)
//{
//	t_ASTree	**cmds;
//	pid_t		*pid;
//	size_t		i;
//	size_t		pipes;
//	char		**argv;
//
//	cmds = NULL;
//	pipes = 0;
//	pipes = ast_counter(v->tree, &pipes, COMMAND, 0);
//	pid = ft_calloc_lc(sizeof(pid_t), pipes);
//	if (pid == NULL)
//		error_exit(strerror(ENOMEM), ENOMEM);
//	cmds = make_ast_arr(v->tree, COMMAND, cmds);
//	v->env = etree_to_env(v->etree);
////	close(0);
////	close(1);
//	i = 0;
//	while (cmds[i])
//	{
//		if (i == 0)
//		{
//			v->tmp_fd = 0;
//			pipe(v->pfd);
//		}
//		else if (i == pipes - 1)
//		{
//			close(v->pfd[1]);
//			dup2(v->fd[1], v->pfd[1]);
//		}
//		else
//		{
//			dup2(v->pfd[0], v->tmp_fd);
//			pipe(v->pfd);
//		}
//		pid[i] = fork();
//		argv = make_argv(cmds[i]);
//		if (pid == 0)
//		{
//			dup2(v->tmp_fd, 0);
//			dup2(v->pfd[1], 1);
//			close(v->pfd[1]);
//			execve(argv[0], argv, v->env);
//			error_exit2(argv[0], strerror(errno), errno);
//		}
//		else if (pid[i] < 0)
//			errmsg("fork() error in execute_command()\n", ERROR);
//		i++;
//	}
//	while (i < pipes)
//		waitpid(pid[i++], &v->status, 0);
//	dup2(v->fd[0], 0);
//	dup2(v->fd[1], 1);
//	dup2(v->fd[2], 2);
//	embed_etree_node(v->etree, "?", int_to_char(v->status));
//}
