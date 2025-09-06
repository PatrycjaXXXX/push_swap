/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolich <psmolich@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 20:06:50 by psmolich          #+#    #+#             */
/*   Updated: 2025/09/06 22:12:25 by psmolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../libft/libft.h"

static void	mark_keep(t_list **a)
{
	int		best_len;
	t_list	*best_end;
	t_list	*i;
	t_list	*j;

	best_len = 0;
	best_end = NULL;
	i = *a;
	while (i)
	{
		j = *a;
		while (j != i)
		{
			if (j->content < i->content && j->lis_len + 1 > i->lis_len)
			{
				i->lis_len = j->lis_len + 1;
				i->lis_prev = j;
			}
			j = j->next;
		}
		if (i->lis_len > best_len)
		{
			best_len = i->lis_len;
			best_end = i;
		}
		i = i->next;
	}
	while (best_end)
	{
		best_end->lis_keep = 1;
		best_end = best_end->lis_prev;
	}
}

static int	there_is_still_non_keep_in_a(t_list *a)
{
	while (a)
	{
		if (a->lis_keep == 0)
			return (1);
		a = a->next;
	}
	return (0);
}

static void	push_non_keep_to_b(t_list **a, t_list **b)
{
	int	median;

	median = ft_lstsize(*a) / 2;
	while (there_is_still_non_keep_in_a(*a))
	{
		if ((*a)->lis_keep == 0)
		{
			ft_move("pb\n", a, b);
			if ((*b)->content < median)
			{
				if ((*a)->lis_keep == 1)
					ft_move("rr\n", a, b);
				else
					ft_move("rb\n", a, b);
			}
		}
		else
			ft_move("ra\n", a, b);
	}
}

void	ft_lis(t_list **a, t_list **b)
{
	mark_keep(a);
	push_non_keep_to_b(a, b);
}

static int	totalcost(t_list *a, t_list *b, t_list *node_a, t_list *node_b)
{
	int	a_steps;
	int	b_steps;
	int	size_a;
	int	size_b;

	size_a = ft_lstsize(a);
	size_b = ft_lstsize(b);
	a_steps = ft_steps(ft_lstindex(a, node_a), size_a);
	b_steps = ft_steps(ft_lstindex(b, node_b), size_b);
	if (a_steps * b_steps < 0)
		ft_adjuststeps(&a_steps, &b_steps, size_a, size_b);
	return (ft_absint(a_steps) + ft_absint(b_steps));
}

static t_list	*where_to_in_a(t_list *a, t_list *node_b)
{
	
}

static void insert_all_from_b(t_node **a, t_node **b)
{
	t_list	*iter;

	while (*b)
	{
		iter = *b;
		while (iter)
		{
			iter->next_in_a = where_to_in_a(a, iter);
			iter->move_cost = total_cost(*a, *b, iter->next_in_a, iter);
			iter = iter->next;
		}
		
	}
}

static void insert_all_from_b(t_node **a, t_node **b)
{
	while (*b)
	{
		int best_cost = 1<<30;
		int best_a_steps = 0, best_b_steps = 0;
		int b_size = stack_size(*b);
		int a_size = stack_size(*a);

		// Przejdź po wszystkich elementach B i znajdź najtańszy do wstawienia
		int idx_b = 0;
		for (t_node *it = *b; it; it = it->next, idx_b++){
			int target_a_idx = target_index_in_a(*a, it->rank);
			int a_steps = steps_to_top(target_a_idx, a_size);
			int b_steps = steps_to_top(idx_b, b_size);
			int cost = total_cost(a_steps, b_steps);
			if (cost < best_cost){
				best_cost = cost;
				best_a_steps = a_steps;
				best_b_steps = b_steps;
			}
		}
		// wykonaj obrót i wstaw
		do_rotations(a, b, &best_a_steps, &best_b_steps);
		pa(a, b);
	}
}
