/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzohraby <mzohraby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 13:58:39 by mzohraby          #+#    #+#             */
/*   Updated: 2025/03/09 18:32:30 by mzohraby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
	//system("leaks pipex");
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

int	open_dup(char *file, int dup_fd)
{
	int	fd;

	if (dup_fd == STDIN_FILENO)
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
