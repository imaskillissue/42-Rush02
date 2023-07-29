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

int	main(void)
{
	t_map	*map;

	map = parse("numbers.dict");
	printf("%s\n", find(map, 1));
}
