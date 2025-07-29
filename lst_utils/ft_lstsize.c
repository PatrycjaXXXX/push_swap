/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolich <psmolich@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 19:23:18 by psmolich          #+#    #+#             */
/*   Updated: 2025/07/29 09:37:31 by psmolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"

// lst: The beginning of the list. (as adress)
// Return value The length of the list
// Counts the number of nodes in the list.

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}
