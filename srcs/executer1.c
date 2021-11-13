/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclam <mclam@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 23:03:12 by mclam             #+#    #+#             */
/*   Updated: 2021/11/11 23:03:12 by mclam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//int	execute_command(t_var *v)
//{
//	char	**argv = NULL;
//	pid_t	pid;
//
//	if (v->debug == TRUE)
//		printf("============EXECUTING COMMAND=========\n");
////	argv = make_argv(COMMAND, IO_REDIRECT);
//	v->env = etree_to_env(v->etree);
//	if (v->debug == TRUE)
//		print_array(argv);
//	pid = fork();
//	if (pid == 0)
//	{
//		execve(argv[0], argv, v->env);
//		error_exit2(argv[0], strerror(errno), errno);
//	}
//	else if (pid < 0)
//		return (errmsg("fork() error in execute_command()\n", ERROR));
//	waitpid(pid, &v->status, 0);
//	embed_etree_node(v->etree, "?", int_to_char(v->status));
//	return (SUCCESS);
//}

int	check_command(t_var *v, char **argv)
{
	int	i;

	i = 0;
	if (ft_strchr(argv[0], '/') != NULL)
		if (check_paths(join_abspath_cmd(v->etree, argv[0]), argv) != SUCCESS)
			return (errmsg2(argv[0], "command not found\n", 127));
	return (SUCCESS);
}

char	**join_abspath_cmd(t_eTree *etree, char *command)
{
	char	**split_envpath;
	int		i;

	i = 0;
	split_envpath = ft_splitset_lc(get_env(etree, ENV_PATH), ":");
	if (split_envpath == NULL)
		error_exit(strerror(ENOMEM), ENOMEM);
	while (split_envpath[i] != NULL)
	{
		split_envpath[i] = ft_strjoin3_lc(split_envpath[i], "/", command);
		if (split_envpath[i] == NULL)
			error_exit(strerror(ENOMEM), ENOMEM);
	}
	return (split_envpath);
}

int	check_paths(char **paths, char **argv)
{
	int	i;
	struct stat	info;
	
	i = 0;
	while (paths[i] != NULL)
	{
		if (stat(paths[i], &info) == 0)
		{
			if (info.st_mode & S_IFDIR)
			{
				argv[0] = ft_strjoin_lc(paths[i], argv[0]);
				if (argv[0])
					error_exit(strerror(ENOMEM), ENOMEM);
				if (stat(argv[0], &info) == 0 && info.st_mode & S_IXUSR)
					return (SUCCESS);
			}
		}
		i++;
	}
	return (ERROR);
}
