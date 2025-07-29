/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacka_creator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolich <psmolich@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 10:34:40 by psmolich          #+#    #+#             */
/*   Updated: 2025/07/29 11:55:39 by psmolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	check_value(const char *nptr, int *number)
{
	long	nb;

	nb = ft_atol(nptr);
	if (((long)INT_MIN <= nb) && (nb <= (long)INT_MAX))
	{
		*number = (int)nb;
		ft_printf("success in check value\n");
		return (SUCCESS);
	}
	ft_printf("fail in check value\n");
	return (FAIL);
}

static int	check_arg(char **arg, int i)
{
	int	j;

	while (arg[i])
	{
		if (!(ft_strlen(arg[i]) <= 11 && ft_strchr("0123456789-+", arg[i][0])))
			return (ft_printf("fail 1 in check arg\n"), FAIL);
		j = 0;
		while (arg[i][++j])
			if (!ft_isdigit(arg[i][j]))
				return (ft_printf("fail 2 in check arg\n"), FAIL);
		j = 0;
		while (arg[j])
		{
			if (i != j && ft_strcmp(arg[i], arg[j]) == 0)
				return (ft_printf("fail 3 in check arg\n"), FAIL);
			j++;
		}
		i++;
	}
	return (ft_printf("success in check arg\n"), SUCCESS);
}

static void	free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
	ft_printf("array freed\n");
	return ;
}

int	record_arg(int ac, char **av, t_list **stack_a)
{
	int		i;
	int		value;
	char	**arg;

	if (ac == 2)
	{
		if (ft_strstr(av[1], "  ") || av[1][0] == '\0' || !ft_strcmp(av[1], " "))
			return (ft_printf("fail 1 in record arg\n"), FAIL);
		arg = ft_split(av[1], ' ');
	}
	else
		arg = av;
	i = !(ac == 2);
	if (check_arg(arg, i) == FAIL)
		return (ft_printf("fail 2 in record arg\n"), FAIL);
	while (arg[i])
	{
		value = 0;
		if (check_value(arg[i], &value) == FAIL)
			return (ft_printf("fail 3 in record arg\n"), FAIL);
		ft_lstadd_back(stack_a, ft_lstnew(value));
		i++;
	}
	if (ac == 2)
		free_arr(arg);
	return (SUCCESS);
}