/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   record_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolich <psmolich@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 10:34:40 by psmolich          #+#    #+#             */
/*   Updated: 2025/07/29 13:26:30 by psmolich         ###   ########.fr       */
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
		return (SUCCESS);
	}
	return (FAIL);
}

static int	check_arg(char **arg, int i)
{
	int	j;

	while (arg[i])
	{
		if (!(ft_strlen(arg[i]) <= 11 && ft_strchr("0123456789-+", arg[i][0])))
			return (FAIL);
		j = 0;
		while (arg[i][++j])
			if (!ft_isdigit(arg[i][j]))
				return (FAIL);
		j = 0;
		while (arg[j])
		{
			if (i != j && ft_strcmp(arg[i], arg[j]) == 0)
				return (FAIL);
			j++;
		}
		i++;
	}
	return (SUCCESS);
}

static void	free_arr(int ac, char **arr)
{
	int	i;

	if (ac == 2)
	{
		i = 0;
		while (arr[i])
			free(arr[i++]);
		free(arr);
	}
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
			return (FAIL);
		arg = ft_split(av[1], ' ');
	}
	else
		arg = av;
	i = !(ac == 2);
	if (check_arg(arg, i) == FAIL)
		return (free_arr(ac, arg), FAIL);
	while (arg[i])
	{
		value = 0;
		if (check_value(arg[i], &value) == FAIL)
			return (free_arr(ac, arg), ft_lstfree(stack_a), FAIL);
		ft_lstadd_back(stack_a, ft_lstnew(value));
		i++;
	}
	free_arr(ac, arg);
	return (SUCCESS);
}
