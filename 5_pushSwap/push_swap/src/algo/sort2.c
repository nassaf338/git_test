/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nic <Nic@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 00:08:33 by nassaf            #+#    #+#             */
/*   Updated: 2024/10/04 10:19:28 by Nic              ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../include/push_swap.h"

int	ft_sort_2(t_head *heads)
{
	if (heads->head_a->data > heads->head_a->next->data)
		ft_sa(heads, 1);
	return (0);
}

void	ft_sort_3(t_head *heads)
{
	t_node	*head_node;
	t_node	*max_node;

	head_node = heads->head_a;
	max_node = find_max(head_node);
	if (head_node == max_node)
	{
		ft_ra(heads, 1);
		head_node = heads->head_a;
		if (head_node->data > head_node->next->data)
			ft_sa(heads, 1);
	}
	else if (head_node->next == max_node)
	{
		ft_rra(heads, 1);
		head_node = heads->head_a;
		if (head_node->data > head_node->next->data)
			ft_sa(heads, 1);
	}
	else if (head_node->next->next == max_node)
	{
		if (head_node->data > head_node->next->data)
			ft_sa(heads, 1);
	}
}

void	ft_sort_4(t_head *heads)
{
	push_min_to_b(heads);
	ft_sort_3(heads);
	ft_pa(heads, 1);
}

void	ft_sort_5(t_head *heads)
{
	push_min_to_b(heads);
	push_min_to_b(heads);
	ft_sort_3(heads);
	ft_pa(heads, 1);
	ft_pa(heads, 1);
}
