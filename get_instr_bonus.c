/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_instr_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolich <psmolich@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 10:09:02 by psmolich          #+#    #+#             */
/*   Updated: 2025/09/19 10:25:55 by psmolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"
#include "libft/libft.h"
#include <unistd.h>

static void	ft_free_rest(char **rest)
{
	if (rest && *rest)
	{
		free(*rest);
		*rest = NULL;
	}
}

static int	ft_add_to_rest(char **rest)
{
	char	*buff;
	char	*temp;
	int		r_bytes;

	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (FAIL);
	r_bytes = 1;
	while (!ft_strchr(*rest, '\n') && r_bytes > 0)
	{
		r_bytes = read(0, buff, BUFFER_SIZE);
		if (r_bytes < 0)
			return (free(buff), FAIL);
		if (r_bytes == 0)
			break ;
		buff[r_bytes] = '\0';
		temp = ft_strjoin(*rest, buff);
		if (!temp)
			return (free(buff), FAIL);
		free(*rest);
		*rest = temp;
	}
	return (free(buff), SUCCESS);
}

static char	*ft_line(char **rest)
{
	char	*new_ptr;
	char	*line;
	char	*temp;
	int		len;

	new_ptr = ft_strchr(*rest, '\n');
	if (new_ptr)
		len = new_ptr - *rest + 1;
	else
		len = ft_strlen(*rest);
	line = ft_substr(*rest, 0, len);
	if (!line)
		return (ft_free_rest(rest), NULL);
	temp = ft_strdup(*rest + len);
	if (!temp)
		return (ft_free_rest(rest), free(line), NULL);
	free(*rest);
	*rest = temp;
	return (line);
}

char	*get_instr(char **rest)
{
	char	*line;

	if (!rest)
		return (NULL);
	if (!*rest)
	{
		*rest = ft_strdup("");
		if (*rest == NULL)
			return (NULL);
	}
	if (ft_add_to_rest(rest) == FAIL)
		return (ft_free_rest(rest), NULL);
	if (!*rest || !(*rest)[0])
		return (ft_free_rest(rest), NULL);
	line = ft_line(rest);
	if (line == NULL)
		ft_free_rest(rest);
	return (line);
}
