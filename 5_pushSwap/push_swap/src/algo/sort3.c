/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nic <Nic@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 00:00:45 by Nic               #+#    #+#             */
/*   Updated: 2024/10/05 00:25:47 by Nic              ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../include/push_swap.h"

int compare_bits(t_head *heads, int bit_number, int stack_len)
{
    int     counter;
    t_node  *current;

    counter = 0;
    current = heads->head_a;
    while (stack_len)
    {
        if (!((current->index >> bit_number) & 1))
        {
            ft_pb(heads, 1);
            counter++;
        }
        else
            ft_ra(heads, 1);
        current = heads->head_a;
        stack_len--;
    }
    return (counter);
}
void    return_to_a(t_head *heads, int counter)
{
    while (counter)
    {
        ft_pa(heads, 1);
        counter--;
    }
}
void	ft_sort_6(t_head *heads)
{
	int	total_bits;
	int	bit_number;
	int	stack_len;
	int	counter;

	total_bits = get_max_n_of_bits(heads->head_a);
	bit_number = 0;
	while (bit_number < total_bits)
	{
		stack_len = get_stack_len(heads->head_a);
		counter = compare_bits(heads, bit_number, stack_len);
		return_to_a(heads, counter);
		bit_number++;
	}
}
void    ft_sort_all(t_head *heads, int stack_len)
{
    if (stack_len == 1)
        exit (1);
    else if (stack_len == 2)
        ft_sort_2 (heads);
    else if (stack_len == 3)
        ft_sort_3 (heads);
    else if (stack_len == 4)
        ft_sort_4(heads);
    else if (stack_len == 5)
        ft_sort_5(heads);
    else if (stack_len > 5)
        ft_sort_6(heads);
}
