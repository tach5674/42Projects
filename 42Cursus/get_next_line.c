#include <unistd.h>
#include <stdlib.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif

int ft_strlen(char *str)
{
	int i = 0;
	while (str[i])
		i++;
	return i;
}

char *ft_strjoin(char *container, char *buffer)
{
	int i = 0;
	int j = 0;
	char *res;
	res = malloc(ft_strlen(container) +  ft_strlen(buffer) + 1);
	if (!res)
		return (NULL);
	while (container[i])
	{
		res[i] = container[i];
		i++;
	}
	while (buffer[j])
	{
		res[i + j] = buffer[j];
		j++;
	}
	res[i + j] = '\0';
	return res;
}

char *ft_strdup(char *str, int n)
{
	char *res;
	int i = 0;
	res = malloc(ft_strlen(str) + 1);
	if (!res)
		return NULL;
	while (str[i] && i < n)
	{
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	return res;
}

char *get_next_line(int fd)
{
	static char *container;
	int i;
	char *temp;
	int n;
	char buffer[BUFFER_SIZE  + 1];
	char *res;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	while (1)
	{
		if (container)
		{
			i = 0;
			while (container[i] && container[i] != '\n')
				i++;
			if (container[i] == '\n')
			{
				res = ft_strdup(container, i + 1);
				if (!res)
				{
					free(container);
					container = NULL;
					return NULL;
				}
				if (container[i + 1] == '\0')
				{
					free(container);
					container = NULL;
					return res;
				}
				temp = ft_strdup(container + i + 1, ft_strlen(container + i + 1));
				if (!temp)
				{
					free(res);
					free(container);
					container = NULL;
					return (NULL);
				}
				free(container);
				container = temp;
				return res;
			}
		}
		n = read(fd, buffer, BUFFER_SIZE);
		if (n < 0)
		{
			free(container);
			container = NULL;
			return NULL;
		}
		else if (n == 0)
		{
			if (container)
			{
				res = ft_strdup(container, ft_strlen(container));
				free(container);
				container = NULL;
				if (!res)
					return NULL;
				return res;
			}
			return NULL;
		}
		else
		{
			buffer[n] = '\0';
			if (container)
			{
				temp = ft_strjoin(container, buffer);
				free(container);
				container = NULL;
				if (!temp)
					return NULL;
				container = temp;
			}
			else
			{
				container = ft_strdup(buffer, ft_strlen(buffer));
				if (!container)
					return NULL;
			}
		}
	}
	return NULL;
}
/*
int main()
{
	while (get_next_line(0));
}
*/
