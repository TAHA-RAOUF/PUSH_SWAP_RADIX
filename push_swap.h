/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moraouf <moraouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 11:32:29 by moraouf           #+#    #+#             */
/*   Updated: 2025/03/20 01:54:34 by moraouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				content;
	struct s_list	*next;
	int				rank;
	int				postion;
	struct s_list	*target;
	int				cost;
}					t_list;

int					ft_atoi(const char *str, char **array, t_list **head);
void				main_fun(char **str, int ac, t_list **head);
void				ft_lst_add_back(t_list **lst, int value);
char				**ft_split(char const *s, char c);
char				*ft_strjoin(const char *s1, const char *s2);
void				free_mem(char **array);
void				print_list(t_list *stack_a);
int 				ft_strlen(const char *str);
void 				free_stack(t_list *stack);
void				ft_lstclear(t_list **lst);
int 				ft_lst_size(t_list *stack_a);
int					fun_eror(char **array, t_list **head);
int					check_double(t_list *head);
void				pb(t_list **stack_a, t_list **stack_b);
void				pa(t_list **stack_a, t_list **stack_b);
void				sa(t_list **stack_a);
void				sb(t_list **stack_b);
void				ss(t_list **stack_a, t_list **stack_b);
void				ra(t_list **stack_a);
void				rb(t_list **stack_b);
void				rr(t_list **stack_a, t_list **stack_b);
void				rra(t_list **stack_a);
void				rrb(t_list **stack_b);
void				rrr(t_list **stack_a, t_list **stack_b);
t_list				*max(t_list *stack_a);
t_list				*min(t_list *stack_a);
int 				rank(t_list *stack_a);
void    			fun_position(t_list *stack);
int 				is_sorted(t_list *stack_a);
void 				rank_algo(t_list **stack_a,t_list **stack_b);
void 				sorted_three_num(t_list **stack_a);


void    radix(t_list **stack_a,t_list **stack_b);

#endif