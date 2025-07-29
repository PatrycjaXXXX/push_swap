/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolich <psmolich@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 14:33:59 by psmolich          #+#    #+#             */
/*   Updated: 2025/07/29 11:40:53 by psmolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	check_instr(char *input, char **instr)
{
	int	i;

	i = 0;
	while (instr[i])
	{
		if (ft_strcmp(instr[i], input) == 0)
			return (SUCCESS);
		i++;
	}
	return (FAIL);
}

int	main(int ac, char **av)
{
	static char	*instr[12] = {
		"sa\n", "sb\n", "ss\n", "pa\n", "pb\n", "ra\n", "rb\n",
		"rr\n", "rra\n", "rrb\n", "rrr\n", NULL};
	char		*input;
	t_list		**stack_a;

	if (ac < 2)
		return (FAIL);
	stack_a = (t_list **)malloc(sizeof(t_list *));
	if (record_arg(ac, av, stack_a) == FAIL)
		return(ft_printf("booo\n"), FAIL);
	input = get_next_line(0);
	while (input != NULL)
	{
		if (check_instr(input, instr) == SUCCESS)
			ft_printf("ok\n");
		else
			return (free(input), write(2, "Error\n", 6), FAIL);
		free(input);
		input = get_next_line(0);
	}
	return (0);
}
