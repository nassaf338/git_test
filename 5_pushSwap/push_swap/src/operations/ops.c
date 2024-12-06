/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nassaf <nassaf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 08:41:28 by nassaf            #+#    #+#             */
/*   Updated: 2024/09/14 22:55:43 by nassaf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_node	*get_last_node(t_node *head)
{
	if (head == NULL)
		return (NULL);
	if (head->next == NULL)
		return (head);
	head = head->next;
	while (head->next != NULL)
		head = head->next;
	return (head);
}

void	ft_ss(t_head *heads, int print)
{
	ft_sa(heads, 0);
	ft_sb(heads, 0);
	if (print == 1)
		write (1, "ss\n", 3);
}

void	ft_rr(t_head *heads, int print)
{
	ft_ra(heads, 0);
	ft_rb(heads, 0);
	if (print == 1)
		write (1, "rr\n", 3);
}

void	ft_rrr(t_head *heads, int print)
{
	ft_rra(heads, 0);
	ft_rrb(heads, 0);
	if (print == 1)
		write (1, "rrr\n", 4);
}
