/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolich <psmolich@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 13:23:56 by psmolich          #+#    #+#             */
/*   Updated: 2025/08/10 06:47:23 by psmolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#define FAIL -1
#define SUCCESS 1

int	ft_radixsort(t_list **stack_a, t_list **stack_b, int size_a);

static void	cleanup(t_list **stack_a, t_list **stack_b)
{
	ft_lstfree(stack_a);
	ft_lstfree(stack_b);
}

static int	ft_sort_lstint(t_list **stack_a, t_list **stack_b)
{
	int	size_a;

	size_a = ft_lstsize(*stack_a);
	if (ft_lst_issorted_des(*stack_a) == SUCCESS)
		return (des_to_as(stack_a, stack_b, size_a));
	// ft_selectionsort(stack_a, stack_b, size_a);
	// ft_bubblesort(stack_a, stack_b);
	ft_radixsort(stack_a, stack_b, size_a);
	return (SUCCESS);
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;

	if (ac < 2)
		return (FAIL);
	stack_a = NULL;
	if (record_arg(ac, av, &stack_a) == FAIL)
		return (ft_lstfree(&stack_a), write(2, "Error\n", 6), FAIL);
	if (ft_lst_issorted_as(stack_a) == SUCCESS)
		return (ft_lstfree(&stack_a), 0);
	stack_b = NULL;
	if (ft_sort_lstint(&stack_a, &stack_b) == FAIL)
		return (cleanup(&stack_a, &stack_b), write(2, "Error\n", 6), FAIL);
	cleanup(&stack_a, &stack_b);
	return (0);
}
