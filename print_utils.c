/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekarpawi <ekarpawi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 15:34:00 by ekarpawi          #+#    #+#             */
/*   Updated: 2023/07/30 15:34:06 by ekarpawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "print_utils.h"

void	print_str(char *str)
{
	while (*str)
		write(1, str++, 1);
}

void	print_long(long l)
{
	char	c;

	if (l < 0)
	{
		write(1, "-", 1);
		l *= -1;
	}
	if (l > 9)
		print_long(l / 10);
	c = l % 10 + '0';
	write(1, &c, 1);
}

void	newline(void)
{
	write(1, "\n", 1);
}
