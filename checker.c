/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolich <psmolich@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 14:33:59 by psmolich          #+#    #+#             */
/*   Updated: 2025/07/21 17:38:05 by psmolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	check_instr(char *input, char **instr)
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

int	main(int argc, char **argv)
{
	static char	*instr[12] = {
		"sa\n", "sb\n", "ss\n", "pa\n", "pb\n", "ra\n", "rb\n",
		"rr\n", "rra\n", "rrb\n", "rrr\n", NULL};
	char		*input;

	if (argc <= 1)
		return (FAIL);
	ft_strcmp(argv[1], "");
	input = get_next_line(0);
	while (input != NULL)
	{
		if (check_instr(input, instr) == SUCCESS)
			apply_instr(input);
		else
			return (free(input), write(2, "Error\n", 6), FAIL);
		free(input);
		input = get_next_line(0);
	}
	return (0);
}
