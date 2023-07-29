//
// Created by Emil Karpawitz on 7/29/23.
//

#include "math.h"

long	add_digits(int n, int amount)
{
	long	sum;

	sum = n;
	while (amount-- > 0)
		sum *= 10;
	return (sum);
}

long	ft_atoi(char *str)
{
	int			i;
	int			sign;
	long long	rtn;

	i = 0;
	sign = 1;
	rtn = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign *= -1;
	while (str[i] >= '0' && str[i] <= '9')
		rtn = rtn * 10 + (str[i++] - '0');
	return (rtn * sign);
}
