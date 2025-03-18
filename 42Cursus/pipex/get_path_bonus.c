/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzohraby <mzohraby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 15:45:49 by mzohraby          #+#    #+#             */
/*   Updated: 2025/03/09 18:32:08 by mzohraby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	*get_path(char *envp[])
{
	int		i;

	i = 0;
	while (envp[i] != NULL)
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			return (envp[i] + 5);
		i++;
	}
	return ("/usr/gnu/bin:/usr/local/bin:/bin:/usr/bin");
}

char	*get_full_path(char *cmd, char *envp[], char **args, int i)
{
	char	**path_dir;
	char	*full_path;

	if (access(cmd, X_OK) == 0)
		return (ft_strdup(cmd));
	path_dir = ft_split(get_path(envp), ':', 0, 0);
	if (!path_dir)
		exit_error(NULL, NULL);
	while (path_dir[i])
	{
		full_path = slash_join(path_dir[i], cmd);
		if (!full_path)
			return (free_split(path_dir), NULL);
		if (access(full_path, X_OK) == 0)
			return (free_split(path_dir), full_path);
		free(full_path);
		i++;
	}
	ft_putstr_fd("pipex: command not found: ", STDERR_FILENO);
	ft_putstr_fd(cmd, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
	free_split(path_dir);
	free_split(args);
	//system("leaks pipex");
	exit(127);
}

void	access_execute(char *cmd, char *envp[])
{
	char	**args;

	while (*cmd == ' ')
		cmd++;
	if (access(cmd, X_OK) == 0)
	{
		if (ft_strchr(cmd, '/'))
		{
			args = ft_split(cmd, '\0', 0, 0);
			if (!args)
				exit_error(NULL, NULL);
			if (execve(cmd, args, envp) == -1)
			{
				free_split(args);
				exit_error(NULL, NULL);
			}
		}
		else
			exit_error(NULL, cmd);
	}
	if (ft_strlen(cmd) > 2)
	{
		if (cmd[0] == '.' && cmd[1] == '/')
			exit_error(NULL, cmd);
	}
}
