/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekarpawi <ekarpawi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 16:13:46 by ekarpawi          #+#    #+#             */
/*   Updated: 2023/07/29 16:14:50 by ekarpawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "map.h"
#include "string_utils.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

char	*read_file(char *filename);
t_map	*parse_line(char *line, t_map *parent);
int		get_file_size(int fd);

t_map	*parse(char *filename)
{
	char	*content;
	t_map	*map;
	char	**lines;
	int		i;

	content = read_file(filename);
	if (content == NULL)
		return (NULL);
	lines = ft_split(content, "\n");
	if (lines == NULL)
		return (NULL);
	i = 0;
	while (lines[i])
	{
		map = parse_line(lines[i], map);
		if (map == NULL)
			return (NULL);
		i++;
	}
	return (map);
}

t_map	*parse_line(char *line, t_map *parent)
{
	char	**key_value;
	char	*value;

	if (ft_str_contains(line, ':') == 0)
		return (NULL);
	key_value = ft_split(line, ":");
	if (key_value == NULL)
		return (NULL);
	value = ft_str_rm(key_value[1], ' ');
	if (value == NULL)
		return (NULL);
	if (parent == NULL)
		return (create(ft_atoi(key_value[0]), value));
	return (parent);
}

char	*read_file(char *filename)
{
	size_t		size;
	size_t		read_size;
	char		*content;
	int			fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (NULL);
	size = get_file_size(fd);
	close(fd);
	fd = open(filename, O_RDONLY);
	content = malloc(size + 1);
	if (content == NULL)
		return (NULL);
	read_size = read(fd, content, size);
	if (read_size != size)
		return (NULL);
	content[size] = '\0';
	close(fd);
	return (content);
}

int	get_file_size(int fd)
{
	int		size;
	char	c;

	size = 0;
	while (read(fd, &c, 1) > 0)
		size++;
	return (size);
}
