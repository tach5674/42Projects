/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzohraby <mzohraby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 13:58:39 by mzohraby          #+#    #+#             */
/*   Updated: 2025/03/19 18:02:08 by mzohraby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	exit_error(char *msg, char *cmd)
{
	if (cmd)
	{
		ft_putstr_fd("pipex: command not found: ", STDERR_FILENO);
		ft_putstr_fd(cmd, STDERR_FILENO);
		ft_putstr_fd("\n", STDERR_FILENO);
		exit(127);
	}
	perror(msg);
	exit(EXIT_FAILURE);
}

void	free_split(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

int	open_dup(char *file, int dup_fd, int check)
{
	int	fd;

	if (check == 1)
		fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0666);
	else if (dup_fd == STDIN_FILENO)
		fd = open(file, O_RDONLY);
	else if (dup_fd == STDOUT_FILENO)
		fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0666);
	else
		fd = -1;
	if (fd == -1)
	{
		if (dup_fd == STDIN_FILENO)
			exit_error("pipex: input", NULL);
		else
			exit_error("pipex: output", NULL);
	}
	if (dup2(fd, dup_fd) == -1)
		exit_error(NULL, NULL);
	return (fd);
}

char	*slash_join(char const *s1, char const *s2)
{
	char	*res;
	int		i;

	i = 0;
	res = malloc(ft_strlen(s1) + ft_strlen(s2) + 2);
	if (!res)
		return (NULL);
	while (*s1)
		res[i++] = *s1++;
	res[i++] = '/';
	while (*s2)
		res[i++] = *s2++;
	res[i] = '\0';
	return (res);
}

void	here_doc_handler(char *limmiter, int argc)
{
	int		pipefd[2];
	char	*line;
	
	if (pipe(pipefd) == -1)
		exit_error(NULL, NULL);
	while (1)
	{
		while (argc-- > 5)
			ft_putstr_fd("pipe ", STDIN_FILENO);
		ft_putstr_fd("heredoc> ", STDIN_FILENO);
		line = get_next_line(STDIN_FILENO);
		if (!line) {
			exit_error(NULL, NULL);
		}
		if (ft_strncmp(line, ft_strjoin(limmiter, "\n"), ft_strlen(line)) == 0)
		{
			free(line);
			break ;
		}
		write(pipefd[1], line, ft_strlen(line));
		free(line);
	}
	close(pipefd[1]);
	if (dup2(pipefd[0], STDIN_FILENO) == -1)
		exit_error(NULL, NULL);
}
