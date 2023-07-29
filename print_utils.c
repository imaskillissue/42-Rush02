//
// Created by Emil Karpawitz on 7/29/23.
//

#include <unistd.h>
#include "print_utils.h"

void	print_str(char *str)
{
	while (*str)
		write(1, str++, 1);
}

void	print_int(int i)
{
	char	c;

	if (i < 0)
	{
		write(1, "-", 1);
		i *= -1;
	}
	if (i > 9)
		print_int(i / 10);
	c = i % 10 + '0';
	write(1, &c, 1);
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
		printlong(l / 10);
	c = l % 10 + '0';
	write(1, &c, 1);
}

void	newline(void)
{
	write(1, "\n", 1);
}