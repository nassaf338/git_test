/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nassaf <nassaf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 22:11:22 by nassaf            #+#    #+#             */
/*   Updated: 2024/09/23 07:12:23 by nassaf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_insert_index(t_node *head_x)
{
	int		i;
	t_node	*node;
	t_node	*current;

	current = head_x;
	while (current != NULL)
	{
		i = 0;
		node = head_x;
		while (node != NULL)
		{
			if (node->data < current->data)
			{
				i++;
				current->index = i;
			}
			node = node->next;
		}
		current = current->next;
	}
}

int	get_max_n_of_bits(t_node *head_x)
{
	int		max;
	int		bits;
	t_node	*current;

	max = INT_MIN;
	bits = 0;
	current = head_x;
	while (current != NULL)
	{
		if (current->index > max)
			max = current->index;
		current = current->next;
	}
	if (max == 0)
		return (1);
	while (max)
	{
		bits++;
		max >>= 1;
	}
	return (bits);
}

int	get_stack_len(t_node *head_x)
{
	int		i;
	t_node	*actual;

	i = 0;
	actual = head_x;
	while (actual)
	{
		i++;
		actual = actual->next;
	}
	return (i);
}

void	ft_position_in_stack(t_node *head_x)
{
	t_node	*current;
	int		i;

	i = 1;
	current = head_x;
	while (current != NULL)
	{
		current->position = i;
		i++;
		current = current->next;
	}
}

void	push_min_to_b(t_head *heads)
{
	int		i;
	t_node	*min;

	i = 0;
	min = find_min(heads->head_a);
	ft_position_in_stack(heads->head_a);
	if (min->position <= (get_stack_len(heads->head_a) / 2))
	{
		i = (min->position) - 1;
		while (i != 0)
		{
			ft_ra(heads, 1);
			i--;
		}
	}
	else if (min->position > (get_stack_len(heads->head_a) / 2))
	{
		i = get_stack_len(heads->head_a) - (min->position) + 1;
		while (i != 0)
		{
			ft_rra(heads, 1);
			i--;
		}
	}
	ft_pb(heads, 1);
}
