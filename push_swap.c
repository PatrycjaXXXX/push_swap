/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolich <psmolich@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 13:23:56 by psmolich          #+#    #+#             */
/*   Updated: 2025/07/29 09:49:04 by psmolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include "lst_int/lst_int.h"
#define FAIL -1
#define SUCCESS 1

int	main(int argc, char **argv)
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
	stack_b = (t_list **)malloc(sizeof(t_list *));
	if (!stack_b)
		return (write(2, "Error\n", 6), FAIL);
	*stack_b = NULL;

	return (0);
}
