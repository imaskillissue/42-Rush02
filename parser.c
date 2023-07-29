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

char	*read_file(char *filename);
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
	while (lines[i])
	{
		map = parse_lines(lines[i], map);
		if (map == NULL)
			return (NULL);
		i++;
	}
	return (map);
}

t_map	*parse_lines(char *line, t_map *parent)
{
	char	**key_value;
	char	*formtated_value;
	int		i;

	if (ft_str_contains(line, ':') == 0)
		return (NULL);
	map = malloc(sizeof(t_map));
	if (map == NULL)
		return (NULL);
	key_value = ft_split(line, ":");
	if (key_value == NULL)
		return (NULL);
	formtated_value = ft_str_rm(key_value[1], ' ');
	if (formtated_value == NULL)
		return (NULL);
	if (parent == NULL)
		return (create(ft_atoi(key_value[0]), formtated_value));
	return (add(parent, ft_atoi(key_value[0]), formtated_value));
}

char	*read_file(char *filename)
{
	char	*content;
	int		fd;
	int		size;
	int		read_size;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (NULL);
	size = get_file_size(fd);
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
