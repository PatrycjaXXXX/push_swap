/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolich <psmolich@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 13:23:56 by psmolich          #+#    #+#             */
/*   Updated: 2025/08/05 12:41:50 by psmolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#define FAIL -1
#define SUCCESS 1

static int	ft_sort_lstint(t_list **stack_a, t_list **stack_b)
{
	int	size;

	size = ft_lstsize(*stack_a);
	if ( )
	if (size == 2)
		return (ft_printf("sa\n"), apply_instr("sa\n", stack_a, stack_b));
	else if (size <= 5)
	return (ft_printf("else\n"), 0);
}

int	main(int ac, char **av)
{
	t_list	**stack_a;
	t_list	**stack_b;

	if (ac < 2)
		return (FAIL);
	stack_a = (t_list **)malloc(sizeof(t_list *));
	if (!stack_a)
		return (write(2, "Error\n", 6), FAIL);
	*stack_a = NULL;
	if (record_arg(ac, av, stack_a) == FAIL)
		return (ft_lstfree(stack_a), write(2, "Error\n", 6), FAIL);
	if (ft_lst_issorted_as(*stack_a) == SUCCESS)
		return (ft_lstfree(stack_a), 0);
	stack_b = (t_list **)malloc(sizeof(t_list *));
	if (!stack_b)
		return (write(2, "Error\n", 6), FAIL);
	*stack_b = NULL;
	// ft_lstprint(*stack_a);
	// ft_lstprint(*stack_b);
	if (ft_sort_lstint(stack_a, stack_b) == FAIL)
		return (write(2, "Error\n", 6), FAIL);
	// ft_printf("end\n");
	return (0);
}
