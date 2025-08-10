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

static void	normalize_data(t_list **stack_a, t_list **stack_b, int size_a)
{
	int	min;
	int	i;

	i = 0;
	while (*stack_a)
	{
		min = ft_lstsmallest(*stack_a)->content;
		while ((*stack_a)->content != min)
			apply_instr("ra\n", stack_a, stack_b);
		apply_instr("pb\n", stack_a, stack_b);
		(*stack_b)->content = i++;
	}
	while (*stack_b)
	{
		size_a--;
		while ((*stack_b)->index != size_a)
			apply_instr("rb\n", stack_a, stack_b);
		apply_instr("pa\n", stack_a, stack_b);
	}
}

// int	ft_radixsort(t_list **stack_a, t_list **stack_b, int size_a)
// {
// 	int		max_bits;
// 	int		i;
// 	int		j;

// 	normalize_data(stack_a, stack_b, size_a);
// 	max_bits = ft_bitcount(size_a - 1);
// 	i = 0;
// 	while (i < max_bits)
// 	{
// 		j = 0;
// 		while (j < size_a)
// 		{
// 			if (((stack_r->content >> i) & 1) == 0)
// 				apply_instr("pb\n", &stack_r, stack_b);
// 			else
// 				apply_instr("ra\n", &stack_r, stack_b);
// 			j++;
// 		}
// 		ft_lstprint(stack_r);
// 		ft_lstprint(*stack_b);
// 		ft_printf("\n");
// 		i++;
// 	}
// 	while (*stack_b)
// 		apply_instr("pa\n", &stack_r, stack_b);
// 	ft_lstprint(stack_r);
// 	ft_lstprint(*stack_b);
// 	ft_printf("\n");
// 	ft_lstfree(&stack_r);
// 	return (SUCCESS);
// }

// int	ft_radixsort(t_list **stack_a, t_list **stack_b, int size_a)
// {
// 	int		max_bits;
// 	int		i;
// 	int		j;

// 	// Normalizuj bezpośrednio na stack_a (zamień wartości na indeksy)
// 	normalize_data(stack_a, stack_b, size_a);

// 	max_bits = ft_bitcount(size_a - 1);
// 	i = 0;
// 	while (i < max_bits)
// 	{
// 		j = 0;
// 		while (j < size_a)
// 		{
// 			if ((((*stack_a)->content >> i) & 1) == 0)
// 				apply_instr("pb\n", stack_a, stack_b);
// 			else
// 				apply_instr("ra\n", stack_a, stack_b);
// 			j++;
// 		}
// 		// Opcjonalnie: debug print
// 		ft_lstprint(*stack_a);
// 		ft_lstprint(*stack_b);
// 		ft_printf("\n");
// 		i++;
// 	}

// 	// Po przejściu przez wszystkie bity, wracamy elementy ze stack_b do stack_a
// 	while (*stack_b)
// 		apply_instr("pa\n", stack_a, stack_b);

// 	ft_lstprint(*stack_a);
// 	ft_lstprint(*stack_b);
// 	ft_printf("\n");
// 	return (SUCCESS);
// }

int ft_radixsort(t_list **stack_a, t_list **stack_b, int size_a)
{
	int max_bits;
	int i;
	int j;

	max_bits = ft_bitcount(size_a - 1);
	normalize_data(stack_a, stack_b, size_a);
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size_a)
		{
			if ((((*stack_a)->content >> i) & 1) == 0)
				apply_instr("pb\n", stack_a, stack_b);
			else
				apply_instr("ra\n", stack_a, stack_b);
			j++;
		}
		while (*stack_b)
			apply_instr("pa\n", stack_a, stack_b);
		i++;
	}
	return (SUCCESS);
}


