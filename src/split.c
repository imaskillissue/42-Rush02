/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekarpawi <ekarpawi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 16:15:13 by ekarpawi          #+#    #+#             */
/*   Updated: 2023/07/29 16:16:04 by ekarpawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_utils.h"
#include <stdlib.h>

int	is_seperator(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i++])
			return (1);
	}
	return (0);
}

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;
	int				j;

	i = 0;
	j = 0;
	while (src[i] && i < n)
	{
		dest[j++] = src[i++];
	}
	dest[j] = '\0';
	return (dest);
}

int	word_count(char *str, char *charset)
{
	int	i;
	int	count;

	i = 0;
	count = 1;
	while (str[i])
	{
		if (is_seperator(str[i + 1], charset)
			&& is_seperator(str[i], charset) == 0)
			count++;
		i++;
	}
	return (count);
}

void	str_split(char *str, char *charset, char **dest)
{
	int	i;
	int	j;
	int	length;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (is_seperator(str[i], charset) == 1)
			i++;
		else
		{
			length = 0;
			while (is_seperator(str[i + length], charset) == 0
				&& str[i + length])
				length++;
			dest[j] = malloc(sizeof(char) * (length + 1));
			dest[j] = ft_strncpy(dest[j], &str[i], length);
			i += length;
			j++;
		}
	}
}

char	**ft_split(char *str, char *charset)
{
	int		words;
	char	**rtn;

	words = word_count(str, charset);
	rtn = malloc(sizeof(char *) * (words + 1));
	str_split(str, charset, rtn);
	rtn[words] = 0;
	return (rtn);
}
