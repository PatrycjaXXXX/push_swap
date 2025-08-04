/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolich <psmolich@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 14:33:59 by psmolich          #+#    #+#             */
/*   Updated: 2025/08/04 14:01:11 by psmolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#define FAIL -1

static void	cleanup(char *instr, t_list **stack_a, t_list **stack_b)
{
	free(instr);
	ft_lstfree(stack_a);
	ft_lstfree(stack_b);
}

int	main(int ac, char **av)
{
	char		*instr;
	t_list		**stack_a;
	t_list		**stack_b;

	if (ac < 2)
		return (FAIL);

	stack_a = (t_list **)malloc(sizeof(t_list *));
	if (!stack_a)
		return (write(2, "Error\n", 6), FAIL);

	if (record_arg(ac, av, stack_a) == FAIL)
		return (ft_lstfree(stack_a), write(2, "Error\n", 6), FAIL);

	stack_b = (t_list **)malloc(sizeof(t_list *));
	if (!stack_b)
		return (write(2, "Error\n", 6), FAIL);

	instr = get_next_line(0);
	while (instr != NULL)
	{
		if (apply_instr(instr, stack_a, stack_b) == FAIL)
			return (cleanup(instr, stack_a, stack_b),
				write(2, "Error\n", 6), FAIL);
		free(instr);
		instr = get_next_line(0);
	}
	if (ft_lst_issorted_as(stack_a) && ft_lstempty(stack_b))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	cleanup(NULL, stack_a, stack_b);
	return (0);
}
