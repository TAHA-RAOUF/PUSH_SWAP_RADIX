/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_function.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moraouf <moraouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:09:12 by moraouf           #+#    #+#             */
/*   Updated: 2025/03/20 03:03:59 by moraouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	fun_eror(char **array, t_list **head)
{
	if (array)
		free_mem(array);
	if (head)
		ft_lstclear(head);
	write(1, "error\n", 6);
	exit(1);
}

int	ft_atoi(const char *str, char **array, t_list **head)
{
	unsigned int	i;
	int				result;
	int				sign;

	i = 0;
	result = 0;
	sign = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if ((str[i] == '-' || str[i] == '+')
		&& (str[i + 1] >= '0' && str[i + 1] <= '9'))
		if (str[i++] == '-')
			sign *= -1;
	while (str[i] == '0')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i++] - '0');
		if (result < INT_MIN || result > INT_MAX || ft_strlen(str + i) > 11)
			fun_eror(array, head);
	}
	if (str[i] != '\0' && !(str[i] == 32 || (str[i] >= 9 && str[i] <= 13)))
		fun_eror(array, head);
	return (result * sign);
}

void	free_mem(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	main_fun(char **str, int ac, t_list **head)
{
	char	*joined;
	char	*temp;
	char	**numbers;
	int		i;
	int		j;

	j = 2;
	joined = ft_strjoin("", str[1]);
	while (ac > j)
	{
		temp = joined;
		joined = ft_strjoin(joined, str[j++]);
		free(temp);
	}
	numbers = ft_split(joined, 32);
	free(joined);
	i = 0;
	while (numbers[i])
		ft_lst_add_back(head, ft_atoi(numbers[i++], numbers, head));
	if (check_double(*head))
	{
		free_mem(numbers);
		exit(1);
	}
	free_mem(numbers);
}
