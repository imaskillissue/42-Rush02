/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekarpawi <ekarpawi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 16:16:13 by ekarpawi          #+#    #+#             */
/*   Updated: 2023/07/29 16:17:34 by ekarpawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_utils.h"

int	ft_str_contains(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i++] == c)
			return (1);
	}
	return (0);
}

char	*ft_str_rm(char *str, char c)
{
	int		i;
	int		j;
	char	*rtn;

	i = 0;
	j = 0;
	rtn = malloc(sizeof(char) * (ft_strlen(str) + 1));
	while (str[i])
	{
		if (str[i] != c)
			rtn[j++] = str[i];
		i++;
	}
	rtn[j] = '\0';
	return (rtn);
}

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	rtn;

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
