/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nic <Nic@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 23:35:56 by nassaf            #+#    #+#             */
/*   Updated: 2024/10/06 12:02:47 by Nic              ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../include/push_swap.h"

t_node	*create_node(int data)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->data = data;
	new_node->next = NULL;
	new_node->previous = NULL;
	return (new_node);
}
t_node	*create_first_node(t_node **head, t_node **tail, t_node *new_node)
{
	*head = new_node;
	*tail = new_node;
	return (*head);
}
t_node	*create_stack_from_array(int argc, char **array)
{
	t_node	*head;
	t_node	*tail;
	t_node	*new_node;
	size_t	i;

	head = NULL;
	tail = NULL;
	i = 1;
	if (argc == 2)
		i = 0;
	while (array[i])
	{
		new_node = create_node(ft_atoi(array[i]));
		if (head == NULL)
			create_first_node(&head, &tail, new_node);
		else
		{
			tail->next = new_node;
			new_node->previous = tail;
			tail = new_node;
		}
		i++;
	}
	return (head);
}
t_head	*create_stacks(int argc, char **argv)
{
	t_head	*heads;
	char	**array;
	int		i;

	i = 0;
	array = ft_split(argv[1], ' ');
	heads = malloc(sizeof(t_head));
	if (!heads)
		return(NULL);
	if (argc == 2)
		heads->head_a = create_stack_from_array(argc, array);
	else if (argc > 2)
		heads->head_a = create_stack_from_array(argc, argv);
	while (array[i] != NULL)
		{
			free (array[i]);
			i++;
		}
	free (array);
	heads->head_b = NULL;
	return(heads);
}
void	ft_free_stack(t_head *heads)
{
	t_node	*current;
	t_node	*temp;
	
	current = heads->head_a;
	while (current != NULL)
	{
		temp = current->next;
		free (current);
		current = temp;
	}
	current = heads->head_b;
	while (current != NULL)
	{
		temp = current->next;
		free (current);
		current = temp;
	}
	free (heads);
}
