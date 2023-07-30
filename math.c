/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekarpawi <ekarpawi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 15:30:57 by ekarpawi          #+#    #+#             */
/*   Updated: 2023/07/30 15:30:58 by ekarpawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math.h"

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
