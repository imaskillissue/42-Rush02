/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekarpawi <ekarpawi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 16:13:23 by ekarpawi          #+#    #+#             */
/*   Updated: 2023/07/29 16:13:26 by ekarpawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "parser.h"
#include "map.h"
#include "print_utils.h"
#include "math.h"

int	main(int argc, char **argv)
{
	t_map	*map;

	map = parse("numbers.dict");
	print_long(add_digits(2, 2));
	if (argc == 2)
		printf("%s\n", find(map, ft_atoi(argv[1])));
	else
		print_str("\nError\n");
}