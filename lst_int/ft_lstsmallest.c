/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsmallest.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolich <psmolich@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 12:48:38 by psmolich          #+#    #+#             */
/*   Updated: 2025/08/05 13:10:57 by psmolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst_int.h"
#include <stdlib.h>

t_list	*ft_lstsmallest(t_list *lst)
{
	t_list	*curr;
	t_list	*smallest;

	if (!lst)
		return (NULL);
	if (!lst->next)
		return (lst);
	curr = lst;
	smallest = curr;
	while (curr && curr->next)
	{
		if (smallest->content > curr->next->content)
			smallest = curr->next->content;
		curr = curr->next;
	}
	return (smallest);
}