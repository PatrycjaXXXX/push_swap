/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolich <psmolich@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 10:34:40 by psmolich          #+#    #+#             */
/*   Updated: 2025/08/04 15:35:25 by psmolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "lst_int/lst_int.h"
#include <limits.h>
#define FAIL -1
#define SUCCESS 1

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

static int	check_format(char *arg)
{
	return (!arg
		|| !*arg
		|| !ft_strcmp(arg, " ")
		|| ft_strstr(arg, "  "));
}

int	record_arg(int ac, char **av, t_list **stack_a)
{
	int		i;
	int		value;
	char	**arg;

	if (ac == 2)
	{
		if (check_format(av[1]))
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
			return (free_arr(ac, arg), FAIL);
		ft_lstadd_back(stack_a, ft_lstnew(value));
		i++;
	}
	free_arr(ac, arg);
	return (SUCCESS);
}
