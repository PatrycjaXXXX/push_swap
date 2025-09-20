/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolich <psmolich@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 12:02:41 by psmolich          #+#    #+#             */
/*   Updated: 2025/09/19 10:18:34 by psmolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"
#include "libft/libft.h"
#include <unistd.h>

static void	cleanup(t_list **stack_a, t_list **stack_b)
{
	ft_lstfree(stack_a);
	ft_lstfree(stack_b);
}

static int	check_instr(t_list **stack_a, t_list **stack_b)
{
	char	*instr;
	char	*rest;

	rest = NULL;
	instr = get_instr(&rest);
	while (instr != NULL)
	{
		if (apply_instr(instr, stack_a, stack_b) == FAIL)
			return (free(rest), free(instr), cleanup(stack_a, stack_b), FAIL);
		free(instr);
		instr = get_instr(&rest);
	}
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
	stack_b = NULL;
	if (check_instr(&stack_a, &stack_b) == FAIL)
		return (write(2, "Error\n", 6), FAIL);
	if (ft_lstissorted_as(stack_a) == SUCCESS && (stack_b == NULL))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	cleanup(&stack_a, &stack_b);
	return (0);
}
