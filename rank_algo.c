/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rank_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moraouf <moraouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 17:37:24 by moraouf           #+#    #+#             */
/*   Updated: 2025/03/20 02:38:52 by moraouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rank(t_list *stack_a)
{
	t_list	*current;
	t_list	*runner;
	int		runk;

	current = stack_a;
	while (current)
	{
		runk = 0;
		runner = stack_a;
		while (runner)
		{
			if (current->content > runner->content)
				runk++;
			runner = runner->next;
		}
		current->rank = runk;
		current = current->next;
	}
	return (runk);
}

void	rank_algo(t_list **stack_a, t_list **stack_b)
{
	int		len;
	t_list	*min_node;

	len = ft_lst_size(*stack_a);
	fun_position(*stack_a);
	while (len > 3)
	{
		min_node = min(*stack_a);
		while (min_node->content != (*stack_a)->content)
		{
			if (min_node->postion <= len / 2)
				ra(stack_a);
			else
				rra(stack_a);
		}
		pb(stack_a, stack_b);
		fun_position(*stack_a);
		len--;
	}
	sorted_three_num(stack_a);
	while (*stack_b)
	{
		pa(stack_a, stack_b);
	}
}
