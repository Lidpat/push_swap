/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_precheck_and_load.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpalacio <lpalacio@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 20:59:36 by lpalacio          #+#    #+#             */
/*   Updated: 2024/03/21 22:34:16 by lpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Check if string has valid length and characters to be an integer */
int	is_valid_str_for_int(char *str)
{
	int	i;

	i = 0;
	if (!str)
		exit(5);
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] == '0')
	{
		if (!str[i + 1])
			return (1);
		i++;
	}
	if (!str[i] || (ft_strlen(str) - i) > 10)
		error_and_exit(3);
	while (str[i])
	{
		if (!ft_isdigit((int)str[i]))
			error_and_exit(4);
		i++;
	}
	return (1);
}

int	validate_arg(char **args, t_list **stack_a)
{
	int		j;
	int		**num;
	t_list	*new_node;

	j = count_rows(args);
	num = (int **)ft_calloc(j, sizeof(int *));
	if (num == NULL)
		exit (2);
	j = 0;
	while (args[j])
	{
		is_valid_str_for_int(args[j]);
		num[j] = (int *)ft_calloc(2, sizeof(int));
		if (!num[j])
			exit (22);
		num[j][value] = ft_atoi(args[j]);
		num[j][position] = unset;
		free(args[j]);
		new_node = ft_lstnew((void *)num[j]);
		ft_lstadd_back(stack_a, new_node);
		j++;
	}
	free (num);
	return (0);
}

int	check_and_load(char *argv[], t_list **stack_a)
{
	int		i;
	char	**args;

	i = 1;
	while (argv[i])
	{
		args = ft_split(argv[i], ' ');
		if (args == NULL)
			exit (1);
		validate_arg(args, stack_a);
		free(args);
		i++;
	}
	return (0);
}

int	*get_max_and_check_dup(t_list *lst, int *max)
{
	t_list	*aux2;

	aux2 = lst;
	while (aux2)
	{
		if (((int *)(aux2->content))[position] == unset)
		{
			if (max[value] == ((int *)(aux2->content))[value])
				error_and_exit(6);
			if (max[value] < ((int *)(aux2->content))[value])
				max = aux2->content;
		}
		aux2 = aux2->next;
	}
	return (max);
}

void	check_duplicated_and_sort(t_list *stack)
{
	t_list	*aux;
	t_list	*aux2;
	int		count;
	int		*max;

	aux = stack;
	count = ft_lstsize(stack);
	while (count)
	{
		max = aux->content;
		if (max[position] == unset)
		{
			aux2 = aux->next;
			max = get_max_and_check_dup(aux2, max);
			max[position] = --count;
		}
		else
			aux = aux->next;
	}
}
