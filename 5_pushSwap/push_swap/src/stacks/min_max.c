/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_max.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nassaf <nassaf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 20:49:46 by nassaf            #+#    #+#             */
/*   Updated: 2024/09/16 23:08:55 by nassaf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_node	*find_min(t_node *head_x)
{
	t_node	*current;
	t_node	*minimum;

	if (head_x == NULL)
		return (NULL);
	current = head_x;
	minimum = head_x;
	while (current != NULL)
	{
		if (current->data < minimum->data)
			minimum = current;
		current = current->next;
	}
	return (minimum);
}

t_node	*find_max(t_node *head_x)
{
	t_node	*current;
	t_node	*maximum;

	if (head_x == NULL)
		return (NULL);
	current = head_x;
	maximum = head_x;
	while (current != NULL)
	{
		if (current->data > maximum->data)
			maximum = current;
		current = current->next;
	}
	return (maximum);
}
