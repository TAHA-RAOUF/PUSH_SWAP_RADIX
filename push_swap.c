/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moraouf <moraouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 11:32:49 by moraouf           #+#    #+#             */
/*   Updated: 2025/03/20 02:54:34 by moraouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_new_node(int content)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}

int	ft_lst_size(t_list *stack_a)
{
	int		count;
	t_list	*current;

	count = 0;
	current = stack_a;
	while (current)
	{
		current = current->next;
		count++;
	}
	return (count);
}

void	ft_lstclear(t_list **lst)
{
	t_list	*current;
	t_list	*next;

	if (!lst || !*lst)
		return ;
	current = *lst;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*lst = NULL;
}

void	ft_lst_add_back(t_list **lst, int value)
{
	t_list	*new;
	t_list	*last;

	new = ft_new_node(value);
	if (!lst || !new)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
	{
		last = *lst;
		while (last->next)
			last = last->next;
		last->next = new;
	}
}

int	main(int ac, char **av)
{
	int		len;
	t_list	*stack_a;
	t_list	*stack_b;

	if (ac >= 2)
	{
		stack_a = NULL;
		stack_b = NULL;
		main_fun(av, ac, &stack_a);
		if (is_sorted(stack_a))
			return (free_stack(stack_a), 0);
		len = ft_lst_size(stack_a);
		if (len <= 20)
			rank_algo(&stack_a, &stack_b);
		rank(stack_a);
		radix(&stack_a, &stack_b);
		free_stack(stack_a);
	}
	else
	{
		write(1, "error2\n", 6);
		exit(1);
	}
}
