/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_function3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moraouf <moraouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 15:44:29 by moraouf           #+#    #+#             */
/*   Updated: 2025/03/20 02:53:49 by moraouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_double(t_list *head)
{
	t_list	*current;
	t_list	*runner;

	current = head;
	while (current)
	{
		runner = current->next;
		while (runner)
		{
			if (current->content == runner->content)
			{
				write(1, "eroor1\n", 7);
				ft_lstclear(&head);
				return (1);
			}
			runner = runner->next;
		}
		current = current->next;
	}
	return (0);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

void	free_stack(t_list *stack)
{
	t_list	*temp;

	while (stack)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
}

void	print_list(t_list *stack_a)
{
	while (stack_a)
	{
		printf("%d \n", stack_a->content);
		stack_a = stack_a->next;
	}
}
