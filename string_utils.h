/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekarpawi <ekarpawi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 16:16:19 by ekarpawi          #+#    #+#             */
/*   Updated: 2023/07/29 16:17:26 by ekarpawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRING_UTILS_H
# define STRING_UTILS_H

char	**ft_split(char *str, char *charset);
int		ft_str_contains(char *str, char c);
char	*ft_str_rm(char *str, char c);
int		ft_atoi(char *str);

#endif
