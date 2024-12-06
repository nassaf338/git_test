/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_a.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nassaf <nassaf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 08:41:00 by nassaf            #+#    #+#             */
/*   Updated: 2024/09/16 14:10:50 by nassaf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

//SA: in stack_a: first element becomes second and second element becomes first
void  ft_sa(t_head *heads, int print)
{
	t_node  *first;
	t_node  *second;
	t_node	*third;

	if (heads->head_a == NULL || heads->head_a->next == NULL)
		return;
	first = heads->head_a;
	second = heads->head_a->next;
	third = second->next;
	first->next = third;
	if (third != NULL)
		third->previous = first;
	second->next = first;
	first->previous = second;
	second->previous = NULL;
	heads->head_a = second;
	if (print == 1)
		write (1, "sa\n", 3);
	heads->counter++;
}

//RA: in stack a: first element becomes last element
void  ft_ra(t_head *heads, int print)
{
	t_node  *first;
	t_node  *last;
	t_node  *new_first;

	if(heads->head_a == NULL || heads->head_a->next == NULL)
		return;
	first = heads->head_a;
	new_first = heads->head_a->next;
	last = get_last_node(heads->head_a);
	last->next = first;
	first->previous = last;
	first->next = NULL;
	new_first->previous = NULL;
	heads->head_a = new_first;
	if (print == 1)
		write (1, "ra\n", 3);
	heads->counter++;
}

//RRA: in stack a: the last element becomes the first elment
void  ft_rra(t_head *heads, int print)
{
	t_node  *first;
	t_node  *last;
	t_node  *new_last;

	if(heads->head_a == NULL || heads->head_a->next == NULL)
		return;
	first = heads->head_a;
	last = get_last_node(heads->head_a);
	new_last = last->previous;
	new_last->next = NULL;
	first->previous = last;
	last->next = first;
	last->previous = NULL;
	heads->head_a = last;
	if (print == 1)
		write (1, "rra\n", 4);
}

//PA: takes the first element et the top of B and puts it at the top of A (does nothing if B is empty)
void	ft_pa(t_head *heads, int print)
{
	t_node	*first_b;
	
	if(heads->head_b == NULL)
		return;
	first_b = heads->head_b;
	heads->head_b = first_b->next;
	if (heads->head_b != NULL)
		heads->head_b->previous = NULL;
	first_b->next = heads->head_a;
	if(heads->head_a)
		heads->head_a->previous = first_b;
	first_b->previous = NULL;
	heads->head_a = first_b;
	if (print == 1)
		write (1, "pa\n", 3);
	heads->counter++;
}
	