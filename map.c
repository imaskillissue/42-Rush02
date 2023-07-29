/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekarpawi <ekarpawi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 16:13:32 by ekarpawi          #+#    #+#             */
/*   Updated: 2023/07/29 16:13:33 by ekarpawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include <stdlib.h>

t_map	*create(int key, char *value)
{
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		return (0);
	map->key = key;
	map->value = value;
	map->next = 0;
	return (map);
}

t_map	*add(t_map *map, int key, char *value)
{
	t_map	*new;
	t_map	*tmp;

	new = create(key, value);
	tmp = map;
	if (!new)
		return (0);
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	return (map);
}

char	*find(t_map *map, int key)
{
	while (map)
	{
		if (map->key == key)
			return (map->value);
		map = map->next;
	}
	return (0);
}
