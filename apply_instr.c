/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_instr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolich <psmolich@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 16:48:35 by psmolich          #+#    #+#             */
/*   Updated: 2025/07/29 17:01:42 by psmolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst_utils.lst.h"

static int apply_instr2(char *instr, t_list **stack_a, t_list **stack_b);

int apply_instr(char *instr, t_list **stack_a, t_list **stack_b)
{
	if (!(ft_strcmp(instr, "sa\n")))
		return (swap(stack_a));
	else if (!(ft_strcmp(instr, "sb\n")))
		return (swap(stack_b));
	else if (!(ft_strcmp(instr, "ss\n")))
	{
		if (swap(stack_a) == FAIL || swap(stack_b) == FAIL)
			return (FAIL)
		return (SUCCESS)
	}
	else if (!(ft_strcmp(instr, "pa\n")))
		return (push(stack_a, stack_b));
	else if (!(ft_strcmp(instr, "pb\n")))
		return (push(stack_b, stack_a));
	return (apply_instr2(instr, stack_a, stack_b));
}

static int apply_instr2(char *instr, t_list **stack_a, t_list **stack_b)
{
	if (!(ft_strcmp(instr, "ra\n")))
		return (rotate(stack_a));
	else if (!(ft_strcmp(instr, "rb\n")))
		return (rotate(stack_b));
	else if (!(ft_strcmp(instr, "rr\n")))
	{
		if (rotate(stack_a)== FAIL || rotate(stack_b) == FAIL)
			return (FAIL);
		return (SUCCESS);
	}
	else if (!(ft_strcmp(instr, "rra")))
		return (reverse_rotate(stack_a));
	else if (!(ft_strcmp(instr, "rrb")))
		return (reverse_rotate(stack_b));
	else if (!(ft_strcmp(instr, "rrr")))
	{
		if (reverse_rotate(stack_a) == FAIL || reverse_rotate(stack_b) == FAIL)
			return (FAIL);
		return SUCCESS;
	}
	return (FAIL);
}