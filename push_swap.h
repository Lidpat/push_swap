/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpalacio <lpalacio@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 21:34:32 by lpalacio          #+#    #+#             */
/*   Updated: 2023/12/23 21:31:16 by lpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"

enum    stack_content{
    value = 0,
    position = 1
};

enum    stack_position{
    unset = UINT16_MAX
};

void	error_and_exit(int n);
int 	is_valid_str_for_int(char *str);
void	ft_putnbr_endl(void *n);
int		count_rows(char **args);
int	    is_sorted(t_list *lst);

/** moves_push_swap.c **/
int swap(t_list **stack);
int	push(t_list **lst_src, t_list **lst_dst);
int	rotate(t_list **stack);
int	reverse(t_list **stack);

/**sort_and_duplicates.c*/
void	check_duplicated_and_sort(t_list *stack);
int	    check_and_load(char *argv[], t_list **stack_a);


#endif


