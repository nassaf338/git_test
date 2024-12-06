/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nic <Nic@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 08:41:52 by nassaf            #+#    #+#             */
/*   Updated: 2024/10/05 00:14:55 by Nic              ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../include/push_swap.h"

int	check_max(int c)
{
	if (c > INT_MAX || c < INT_MIN)
		ft_print_error("lim");
	return (0);
}

int	check_duplicates(t_node *head, t_head *heads)
{
	t_node	*current;
	t_node	*runner;

	current = head;
	if (head == NULL || head->next == NULL)
		return (0);
	while (current != NULL)
	{
		runner = current->next;
		while (runner != NULL)
		{
			if (current->data == runner->data)
			{
				ft_free_stack(heads);
				ft_print_error("dup");
			}
			check_max(head->data);
			runner = runner->next;
		}
		current = current->next;
	}
	return (0);
}

int	check_if_sorted(t_head *heads)
{
	t_node	*actual;

	if (heads->head_a == NULL)
		return (1);
	actual = heads->head_a;
	while (actual->next != NULL)
	{
		if (actual->data < actual->next->data)
			actual = actual->next;
		else
			return (0);
	}
	return (1);
}
