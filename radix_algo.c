/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moraouf <moraouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 22:02:34 by moraouf           #+#    #+#             */
/*   Updated: 2025/03/20 01:59:01 by moraouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	shifter(int max)
{
	int	i;

	i = 0;
	while (max)
	{
		max = max >> 1;
		i++;
	}
	return (i);
}
void	push_to_b(t_list **stack_a, t_list **stack_b, int size, int shift)
{
	int		i;
	t_list	*tmp;

	i = 0;
	while (i < size)
	{
		tmp = *stack_a;
		if (((tmp->rank >> shift) & 1) == 1)
			ra(stack_a);
		else
			pb(stack_a, stack_b);
		i++;
	}
}

void	radix(t_list **stack_a, t_list **stack_b)
{
	int	max_pos;
	int	size;
	int	i;
	int	shift;

	max_pos = ft_lst_size(*stack_a);
	size = shifter(max_pos - 1);
	i = 0;
	shift = 0;

	while (i < size)
	{
        //printf("ana dekhlt");
		push_to_b(stack_a, stack_b, max_pos, shift);
		while (*stack_b)
			pa(stack_a, stack_b);
		i++;
		shift++;
	}
}






