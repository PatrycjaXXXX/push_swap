/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   radix.c											:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: psmolich <psmolich@student.42berlin.de>	+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2025/08/09 05:43:41 by psmolich		  #+#	#+#			 */
/*   Updated: 2025/08/10 06:16:51 by psmolich		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#define FAIL -1
#define SUCCESS 1

static void	normalize_data(t_list **stack_r, t_list **stack_b, int size_a)
{
	int	min;
	int	i;

	i = 0;
	while (*stack_r)
	{
		min = ft_lstsmallest(*stack_r)->content;
		while ((*stack_r)->content != min)
			apply_instr("ra\n", stack_r, stack_b);
		apply_instr("pb\n", stack_r, stack_b);
		(*stack_b)->content = i++;
	}
	while (*stack_b)
	{
		size_a--;
		while ((*stack_b)->index != size_a)
			apply_instr("rb\n", stack_r, stack_b);
		apply_instr("pa\n", stack_r, stack_b);
	}
}

int	ft_radixsort(t_list **stack_a, t_list **stack_b, int size_a)
{
	t_list	*stack_r;

	stack_r = ft_lstcopy(*stack_a);
	normalize_data(&stack_r, stack_b, size_a);
	
	ft_lstfree(&stack_r);
	return (SUCCESS);
}
