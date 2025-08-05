/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolich <psmolich@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 13:27:41 by psmolich          #+#    #+#             */
/*   Updated: 2025/08/05 15:13:39 by psmolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#define FAIL -1
#define SUCCESS 1

static int	move_lst(char *move, t_list **stack_a, t_list **stack_b)
{
	ft_printf("%s", move);
	return (apply_instr(move, stack_a, stack_b));
}

int	des_to_as(t_list **stack_a, t_list **stack_b, int size_a)
{
	int	moves;

	if (size_a == 2)
		return (move_lst("sa\n", stack_a, stack_b));
	moves = size_a - 3;
	while (moves--)
	{
		move_lst("rra\n", stack_a, stack_b);
		move_lst("pb\n", stack_a, stack_b);
	}
	move_lst("ra\n", stack_a, stack_b);
	move_lst("sa\n", stack_a, stack_b);
	moves = size_a - 3;
	while (moves--)
		move_lst("pa\n", stack_a, stack_b);
	return (ft_lst_issorted_as(*stack_a));
}

void	ft_bubblesort(t_list **stack_a, t_list **stack_b)
{
	t_list	*first;
	t_list	*second;

	ft_printf("xxx\n");
	first = *stack_a;
	second = first->next;
	while (ft_lst_issorted_as(*stack_a) == FAIL)
	{
		if (first->content > second->content)
			move_lst("sa\n", stack_a, stack_b);
		move_lst("ra\n", stack_a, stack_b);
	}
}
