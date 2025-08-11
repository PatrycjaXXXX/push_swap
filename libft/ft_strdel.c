/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolich <psmolich@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 04:47:08 by psmolich          #+#    #+#             */
/*   Updated: 2025/08/11 05:23:27 by psmolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

// sorce string needs to be created by allocating memory and provided as an adress
int	ft_strdel(char **str, const char *pattern)
{
	char	*src;
	char	*dst;
	char	*new_str;
	size_t	pat_len;

	if (!str || !*str || !pattern)
		return (-1);
	pat_len = ft_strlen(pattern);
	if (pat_len == 0)
		return (0);
	new_str = malloc(ft_strlen(*str) + 1);
	if (!new_str)
		return (-1);
	src = *str;
	dst = new_str;
	while (*src)
	{
		if (ft_strncmp(src, pattern, pat_len) == 0)
			src += pat_len;
		else
			*dst++ = *src++;
	}
	*dst = '\0';
	free(*str);
	*str = new_str;
	return (0);
}
