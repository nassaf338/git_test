/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_b.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nassaf <nassaf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 08:41:13 by nassaf            #+#    #+#             */
/*   Updated: 2024/09/16 15:51:35 by nassaf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

//SB: in stack_b: first element becomes seond and second element becomes first
void	ft_sb(t_head *heads, int print)
{
	t_node	*first;
	t_node	*second;
	t_node	*third;

	if (heads->head_b == NULL || heads->head_b->next == NULL)
		return ;
	first = heads->head_b;
	second = heads->head_b->next;
	third = second->next;
	first->next = third;
	if (third != NULL)
		third->previous = first;
	second->next = first;
	first->previous = second;
	second->previous = NULL;
	heads->head_b = second;
	if (print == 1)
		write (1, "sb\n", 3);
}

//RB: in stack b: first element becomes last element
void	ft_rb(t_head *heads, int print)
{
	t_node	*first;
	t_node	*last;
	t_node	*new_first;

	if (heads->head_b == NULL || heads->head_b->next == NULL)
		return ;
	first = heads->head_b;
	new_first = heads->head_b->next;
	last = get_last_node(heads->head_b);
	last->next = first;
	first->previous = last;
	first->next = NULL;
	new_first->previous = NULL;
	heads->head_b = new_first;
	if (print == 1)
		write (1, "rb\n", 3);
}

//RRB: in stack b: the last element becomes the first elment
void	ft_rrb(t_head *heads, int print)
{
	t_node	*first;
	t_node	*last;
	t_node	*new_last;

	if (heads->head_b == NULL || heads->head_b->next == NULL)
		return ;
	first = heads->head_b;
	last = get_last_node(heads->head_b);
	new_last = last->previous;
	new_last->next = NULL;
	first->previous = last;
	last->next = first;
	last->previous = NULL;
	heads->head_b = last;
	if (print == 1)
		write (1, "rrb\n", 4);
}

//PB: takes the first element et the top of A and puts it at the top of B
//(does nothing if A is empty)
void	ft_pb(t_head *heads, int print)
{
	t_node	*first_a;

	if (heads->head_a == NULL)
		return ;
	first_a = heads->head_a;
	heads->head_a = first_a->next;
	if (heads->head_a != NULL)
		heads->head_a->previous = NULL;
	first_a->next = heads->head_b;
	if (heads->head_b)
		heads->head_b->previous = first_a;
	first_a->previous = NULL;
	heads->head_b = first_a;
	if (print == 1)
		write (1, "pb\n", 3);
	heads->counter++;
}
