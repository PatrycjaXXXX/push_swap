/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolich <psmolich@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 14:33:59 by psmolich          #+#    #+#             */
/*   Updated: 2025/07/29 15:18:40 by psmolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	apply_instr(char *input)
{
	
}

int	main(int ac, char **av)
{
	char		*input;
	t_list		**stack_a;
	t_list		**stack_b;

	if (ac < 2)
		return (FAIL);
	stack_a = (t_list **)malloc(sizeof(t_list *));
	if (record_arg(ac, av, stack_a) == FAIL)
		return(FAIL);
	stack_b = (t_list **)malloc(sizeof(t_list *));

	input = get_next_line(0);
	while (input != NULL)
	{
		if (apply_instr(input, instr) == FAIL)
			ft_printf("ok\n");
		else
			return (free(input), write(2, "Error\n", 6), FAIL);
		free(input);
		input = get_next_line(0);
	}
	return (0);
}

	// ft_lstprint(*stack_a);
	// ft_printf("%i\n", ft_lstissorted(*stack_a));

	// static char	*instr[12] = {
	// 	"sa\n", "sb\n", "ss\n", "pa\n", "pb\n", "ra\n", "rb\n",
	// 	"rr\n", "rra\n", "rrb\n", "rrr\n", NULL};