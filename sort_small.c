/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moraouf <moraouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 15:36:51 by moraouf           #+#    #+#             */
/*   Updated: 2025/03/20 02:39:33 by moraouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*max(t_list *stack_a)
{
	t_list	*current;
	t_list	*max;

	current = stack_a;
	max = current;
	while (current)
	{
		if (current->content > max->content)
			max = current;
		current = current->next;
	}
	return (max);
}

int	is_sorted(t_list *stack_a)
{
	t_list	*current;

	current = stack_a;
	while (current && current->next)
	{
		if (current->content > current->next->content)
			return (0);
		current = current->next;
	}
	return (1);
}

void	fun_position(t_list *stack)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		stack->postion = pos++;
		stack = stack->next;
	}
}

void	sorted_three_num(t_list **stack_a)
{
	t_list	*max_num;

	max_num = max(*stack_a);
	if ((*stack_a)->content == (max_num)->content)
		ra(stack_a);
	else if ((*stack_a)->next->content == (max_num)->content)
		rra(stack_a);
	if ((*stack_a)->content > (*stack_a)->next->content)
		sa(stack_a);
}

t_list	*min(t_list *stack_a)
{
	t_list	*current;
	t_list	*min;

	current = stack_a;
	min = current;
	while (current)
	{
		if (current->content < min->content)
			min = current;
		current = current->next;
	}
	return (min);
}
