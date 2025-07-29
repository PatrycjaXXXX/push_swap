/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolich <psmolich@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 11:57:25 by psmolich          #+#    #+#             */
/*   Updated: 2025/07/29 12:01:00 by psmolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "lst.h"

void	ft_lstprint(t_list *lst)
{
	t_list	*curr;

	if (!lst)
		return ;
	curr = lst;
	while (curr)
	{
		ft_printf("%i\n", curr->content);
		curr = curr->next;
	}
}