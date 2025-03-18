/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzohraby <mzohraby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 12:42:42 by mzohraby          #+#    #+#             */
/*   Updated: 2025/03/09 16:29:48 by mzohraby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"

# include "fcntl.h"
# include <stdio.h>
# include <errno.h>
# include <string.h>
# include <sys/wait.h>
# include <sys/types.h>

char	*slash_join(char const *s1, char const *s2);
void	exit_error(char *msg, char *cmd);
void	free_split(char **str);
int		open_dup(char *file, int dup_fd);
char	*get_path(char *envp[]);
char	*get_full_path(char *cmd, char *envp[], char **args, int i);
void	access_execute(char *cmd, char *envp[]);

#endif
