/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolich <psmolich@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 12:57:01 by psmolich          #+#    #+#             */
/*   Updated: 2025/07/29 13:20:01 by psmolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"
#include <stdlib.h>

void	ft_lstfree(t_list **lst)
{
	t_list	*temp;
	t_list	*curr;

	if (!lst)
		return ;
	curr = *lst;
	while (curr)
	{
		temp = curr->next;
		free(curr);
		curr = temp;
	}
	free(lst)
}
