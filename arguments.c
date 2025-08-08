/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   arguments.c										:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: psmolich <psmolich@student.42berlin.de>	+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2025/07/29 10:34:40 by psmolich		  #+#	#+#			 */
/*   Updated: 2025/08/08 12:20:08 by psmolich		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "libft/libft.h"
#include "lst_int/lst_int.h"
#include <limits.h>
#define FAIL -1
#define SUCCESS 1

static int	check_av(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
		if (!av[i] || !*av[i] || ft_isallspaces(av[i]))
			return (FAIL);
	return (SUCCESS);
}

// static char	**get_arg(int ac, char **av)
// {
// 	char	**arg;
// 		char	*tmp;
// 			char	*space;
// 				int		i;

// 					tmp = ft_strdup(av[1]);
// 						if (!tmp)
// 								return (NULL);
// 									i = 2;
// 										while (i < ac)
// 											{
// 													space = ft_strjoin(tmp, " ");
// 															free(tmp);
// 																	if (!space)
// 																				return (NULL);
// 																						tmp = ft_strjoin(space, av[i++]);
// 																								free(space);
// 																										if (!tmp)
// 																													return (NULL);
// 																														}
// 																															if (!*tmp)
// 																																	return (free(tmp), NULL);
// 																																		arg = ft_split(tmp, ' ');
// 																																			free(tmp);
// 																																				return (arg);
// 																																				}

static char **get_arg(int ac, char **av)
{
    char    **arg;
    char    *tmp;
    char    *new_tmp;
    int     i;

    if (ac < 2)
        return (NULL);
    
    tmp = ft_strdup(av[1]);
    if (!tmp)
        return (NULL);
    
    i = 2;
    while (i < ac)
    {
        new_tmp = ft_strjoin(tmp, " ");
        if (!new_tmp)
            return (free(tmp), NULL);
        free(tmp);
        
        tmp = ft_strjoin(new_tmp, av[i]);
        free(new_tmp);
        if (!tmp)
            return (NULL);
        i++;
    }
    
    if (!*tmp)
        return (free(tmp), NULL);
    
    arg = ft_split(tmp, ' ');
    free(tmp);
    return (arg);
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
			if (i != j && ft_atol(arg[i]) == ft_atol(arg[j]))
				return (FAIL);
			j++;
		}
		i++;
	}
	return (SUCCESS);
}

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

int	record_arg(int ac, char **av, t_list **stack_a)
{
	int		i;
	int		value;
	char	**arg;

	if (check_av(ac, av) == FAIL)
		return (FAIL);
	arg = get_arg(ac, av);
	i = 0;
	while (arg[i])
		ft_printf(":%s:", arg[i++]);
	i = 0;
	if (check_arg(arg, i) == FAIL)
		return (ft_free_arr(arg), FAIL);
	while (arg[i])
	{
		value = 0;
		if (check_value(arg[i], &value) == FAIL)
			return (ft_free_arr(arg), FAIL);
		ft_lstadd_back(stack_a, ft_lstnew(value));
		i++;
	}
	ft_free_arr(arg);
	return (SUCCESS);
}
