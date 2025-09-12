/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolich <psmolich@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 12:02:41 by psmolich          #+#    #+#             */
/*   Updated: 2025/09/12 12:42:03 by psmolich         ###   ########.fr       */
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

static int	get_instr(t_list **stack_a, t_list **stack_b)
{
	char	instr[1028];
	int		read_count;

	read_count = read(0, instr, 1028);
	while (!(read_count <= 0))
	{
		if (apply_instr(instr, stack_a, stack_b) == FAIL)
			return (cleanup(stack_a, stack_b), FAIL);
		read_count = read(0, instr, 4);
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
	if (get_instr(&stack_a, &stack_b) == FAIL)
		return (write(2, "Error\n", 6), FAIL);
	if (ft_lstissorted_as(stack_a) == SUCCESS && (stack_b == NULL))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	cleanup(&stack_a, &stack_b);
	return (0);
}
