/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolich <psmolich@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 11:57:25 by psmolich          #+#    #+#             */
/*   Updated: 2025/08/04 15:07:52 by psmolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "lst_int.h"

void	ft_lstprint(t_list *lst)
{
	t_list	*curr;

	ft_printf("[head]");
	if (!lst)
	{
		ft_printf("empty\n");
		return ;
	}
	curr = lst;
	while (curr)
	{
		ft_printf(" -> ");
		ft_printf("%i", curr->content);
		curr = curr->next;
	}
	ft_printf("\n");
}
