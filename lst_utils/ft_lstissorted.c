/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstissorted.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolich <psmolich@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 12:12:25 by psmolich          #+#    #+#             */
/*   Updated: 2025/07/29 12:22:32 by psmolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "lst.h"

int	ft_lstissorted(t_list *lst)
{
	t_list	*curr;

	if (!lst)
		return (FAIL);
	curr = lst;
	while (curr->next)
	{
		if (curr->content > curr->next->content)
			return (FAIL);
		curr = curr->next;
	}
	return (SUCCESS);
}