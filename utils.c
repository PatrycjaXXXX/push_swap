/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolich <psmolich@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 17:34:33 by psmolich          #+#    #+#             */
/*   Updated: 2025/07/21 17:47:56 by psmolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

void	apply_instr(char *input)
{
	if (strcmp("sa", input) == 0)
		printf("sa");
}

int	parse_arg(char *arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if(!ft_isdigit(arg[i]) || strchr(" -+"))
	}
}

void	create_stack(int argc, char **argv)
{
	if (argc == 2)
		parse_arg(argv[1]);
}