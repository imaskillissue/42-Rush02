/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekarpawi <ekarpawi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 16:13:40 by ekarpawi          #+#    #+#             */
/*   Updated: 2023/07/29 16:13:41 by ekarpawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

typedef struct s_map	t_map;
typedef struct s_map
{
	long				key;
	char			*value;
	t_map			*next;
}					t_map;

t_map	*create(long key, char *value);
t_map	*add(t_map *map, long key, char *value);
char	*find(t_map *map, long key);

#endif
