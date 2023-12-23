/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpalacio <lpalacio@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 21:34:32 by lpalacio          #+#    #+#             */
/*   Updated: 2023/12/23 21:02:11 by lpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"


void	error_and_exit(int n);
int 	is_valid_str_for_int(char *str);
void	ft_putnbr_endl(void *n);
int		count_rows(char **args);

/** moves_push_swap.c **/
int swap(t_list **stack);
int	push(t_list **lst_src, t_list **lst_dst);
int	rotate(t_list **stack);


#endif


