
#ifndef MAP_H
# define MAP_H

typedef struct s_map	t_map;
typedef struct s_map
{
	int				key;
	char			*value;
	t_map			*next;
}					t_map;

t_map	*create(int key, char *value);
t_map	*add(t_map *map, int key, char *value);
char	*find(t_map *map, int key);

#endif
