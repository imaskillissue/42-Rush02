/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekarpawi <ekarpawi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 16:13:23 by ekarpawi          #+#    #+#             */
/*   Updated: 2023/07/30 16:44:12 by ekarpawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "parser.h"
#include "map.h"
#include "print_utils.h"
#include "math.h"
#include "string_utils.h"

long	get_largest_key(t_map *map)
{
	long	largest_key;
	t_map	*tmp;

	largest_key = 0;
	tmp = map;
	while (tmp)
	{
		if (tmp->key > largest_key)
			largest_key = tmp->key;
		tmp = tmp->next;
	}
	return (largest_key);
}

void	check_number(long n, t_map *map)
{
	if (n >= get_largest_key(map) * 1000 || n <= get_largest_key(map) * -1000)
	{
		print_str("Error: number too large\n");
		exit(1);
	}
	if (n < 0)
		print_str("minus ");
}

int	one_before(long nbr, t_map *map)
{
	if (nbr == 100 || nbr == 1000 || nbr == 1000000 || nbr == 1000000000)
	{
		print_str(find(map, 1));
		return (1);
	}
	return (0);
}

void	printable_number(t_map *map, long n)
{
	t_map	*tmp;

	check_number(n, map);
	if (n < 0)
		n *= -1;
	if (find(map, n))
	{
		one_before(n, map);
		print_str(find(map, n));
		return ;
	}
	tmp = map;
	while (tmp->next && tmp->next->key < n)
		tmp = tmp->next;
	if (n > 0 && n / tmp->key > 0)
	{
		if (n / tmp->key > 1)
			printable_number(map, n / tmp->key);
		else
			one_before(tmp->key, map);
		print_str(find(map, tmp->key));
		if (n % tmp->key > 0)
			printable_number(map, n % tmp->key);
		return ;
	}
}

int	main(int argc, char **argv)
{
	t_map	*map;

	if (argc == 2)
	{
		if (!valid_str(argv[1]))
		{
			print_str("error\n");
			return (1);
		}
		map = parse("numbers.dict");
		printable_number(map, ft_atoi(argv[1]));
		newline();
		free_map(map);
	}
	else if (argc == 3)
	{
		map = parse(argv[1]);
		printable_number(map, ft_atoi(argv[2]));
		newline();
		free_map(map);
	}
	else
		print_str("Error: wrong number of arguments\n");
}
