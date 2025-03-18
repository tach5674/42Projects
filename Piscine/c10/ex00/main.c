/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzohraby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 15:20:51 by mzohraby          #+#    #+#             */
/*   Updated: 2024/09/24 15:52:38 by mzohraby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fcntl.h"
#include "unistd.h"

int	print(int fd)
{
	int		n;
	int		i;
	char	buf[32];

	n = read(fd, buf, sizeof(buf));
	if (n < 0)
		return (1);
	while (n)
	{
		i = -1;
		while (++i < n)
			write(1, &buf[i], 1);
		n = read(fd, buf, sizeof(buf));
		if (n < 0)
			return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int		fd;

	if (argc == 1)
		write(1, "File name missing.", 18);
	else if (argc > 2)
		write(1, "Too many arguments.", 19);
	else
	{
		fd = open(argv[1], O_RDONLY);
		if (fd < 0)
		{
			write(1, "Cannot read file.", 17);
			return (1);
		}
		if (print(fd))
		{
			write(1, "Cannot read file.", 17);
			return (1);
		}
	}
	return (0);
}
