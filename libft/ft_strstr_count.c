/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstrnbunt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolich <psmolich@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 05:02:44 by psmolich          #+#    #+#             */
/*   Updated: 2025/08/11 05:10:45 by psmolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strstr_count(const char *str, const char *pattern)
{
	int	i;
	int	j;
	int	count;

	if (!str || !pattern || !*pattern)
		return (-1);
	count = 0;
	i = 0;
	while (str[i])
	{
		j = 0;
		if (str[i] == pattern[0])
		{
			while (str[i + j] == pattern[j] && str[i + j]
				&& pattern[j])
				j++;
			if (pattern[j] == '\0')
				count++;
		}
		i++;
	}
	return (count);
}
