/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzohraby <mzohraby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 13:31:15 by mzohraby          #+#    #+#             */
/*   Updated: 2025/03/09 18:31:54 by mzohraby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	execute(char *cmd, char *envp[])
{
	char	**args;
	char	*full_path;

	access_execute(cmd, envp);
	args = ft_split(cmd, ' ', 0, 0);
	if (!args)
		exit_error(NULL, NULL);
	full_path = get_full_path(args[0], envp, args, 0);
	if (!full_path)
	{
		free_split(args);
		exit_error(NULL, NULL);
	}
	if (execve(full_path, args, envp) == -1)
	{
		free(full_path);
		free_split(args);
		exit_error(NULL, NULL);
	}
}

static void	in_execute(char *cmd, char *input, char *envp[])
{
	int	pid;
	int	pipefd[2];

	if (pipe(pipefd) == -1)
		exit_error(NULL, NULL);
	pid = fork();
	if (pid == -1)
		exit_error(NULL, NULL);
	if (pid == 0)
	{
		close(pipefd[0]);
		open_dup(input, STDIN_FILENO);
		if (dup2(pipefd[1], STDOUT_FILENO) == -1)
			exit_error(NULL, NULL);
		close(pipefd[1]);
		execute(cmd, envp);
	}
	close(pipefd[1]);
	if (dup2(pipefd[0], STDIN_FILENO) == -1)
		exit_error(NULL, NULL);
	close(pipefd[0]);
}

static int	out_execute(char *cmd, char *output, char *envp[])
{
	int	pid;

	pid = fork();
	if (pid == -1)
		exit_error(NULL, NULL);
	if (pid == 0)
	{
		open_dup(output, STDOUT_FILENO);
		execute(cmd, envp);
	}
	return (pid);
}

int	main(int argc, char *argv[], char *envp[])
{
	int	pid;

	fprintf(stderr, "HERE\n");
	if (argc != 5)
	{
		ft_putstr_fd("pipex: Invalid number of arguments\n", STDERR_FILENO);
		//system("leaks pipex");
		exit(EXIT_FAILURE);
	}
	fprintf(stderr, "HERE\n");
	in_execute(argv[2], argv[1], envp);
	pid = out_execute(argv[3], argv[4], envp);
	close(STDIN_FILENO);
	while (wait(NULL) > 0)
		;
	fprintf(stderr, "HERE\n");
	//system("leaks pipex");
	return (0);
}
