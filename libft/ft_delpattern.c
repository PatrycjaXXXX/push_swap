/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_delpattern.c									:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: psmolich <psmolich@student.42berlin.de>	+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2025/08/10 17:43:12 by psmolich		  #+#	#+#			 */
/*   Updated: 2025/08/10 17:43:14 by psmolich		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_delpattern(char **str, const char *pattern)
{
	char	*src;
	char	*dst;
	char	*out;
	size_t	len_pat;

	if (!str || !*str || !pattern)
		return ;
	len_pat = ft_strlen(pattern);
	if (len_pat == 0)
		return ;
	src = *str;
	out = malloc(ft_strlen(src) + 1);
	if (!out)
		return ;
	dst = out;
	while (*src)
	{
		if (ft_strncmp(src, pattern, len_pat) == 0)
			src += len_pat;
		else
			*dst++ = *src++;
	}
	*dst = '\0';
	free(*str);
	*str = out;
}
