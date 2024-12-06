/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nic <Nic@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 21:20:14 by nassaf            #+#    #+#             */
/*   Updated: 2024/10/05 20:43:51 by Nic              ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "include/push_swap.h"

int main(int argc, char **argv)
{
	t_head	*heads;
	int		stack_len;
	
	ft_check_args(argv);
	heads = create_stacks(argc, argv);
	stack_len = get_stack_len(heads->head_a);
	check_duplicates(heads->head_a, heads);
	if (check_if_sorted(heads))
	{
		ft_free_stack(heads);
		return (0);
	}
	ft_insert_index(heads->head_a);
	ft_position_in_stack(heads->head_a);
	ft_sort_all(heads, stack_len);
	ft_free_stack(heads);	
}
//FUNCTION USED TO PRINT THE RESULTS OF THE TESTS
// void	print_stacks(t_head *heads)
// {
// 	t_node	*current;
	
// 	printf("pointer H: %p\n", heads);
// 	printf("pointer A: %p\n", heads->head_a);
// 	printf("pointer B: %p\n", heads->head_b);
// 	printf("STACK A:\n");
// 	current = heads->head_a;
// 	while (current != NULL)
// 	{
// 		printf("data: %d - current:%p - next:%p - previous:%p\n", current->data, current, current->next, current->previous);
// 		current = current->next;
// 	}
// 	printf("STACK B:\n");
// 	current = heads->head_b;
// 	while (current != NULL)
// 	{
// 		printf("data: %d - current:%p - next:%p - previous:%p\n", current->data, current, current->next, current->previous);
// 		current = current->next;
// 	}
// 	printf("\n\n");
// }

// int	main(int argc, char **argv)
// {
	// t_head	*heads;
	
	// if (argc == 1 || argc == 2 && !argv[1][0])
	// 	return(1);
	// else
	// 	ft_check_args(argv);
	// 	heads = create_stacks(argc, argv);
	// 	check_duplicates(heads->head_a);
		//if their are duplicates i have to free the stack i have created
		//
		//have to check if it is sorted
		//if not sorted
		//    if stack len == 2 => execute sa
		//    if stack len == 3 => execute sort 3 function
		//    if stack len >  3 => execute sorting alogorithm
		//free the stacks
		//return value
	

	

	
	// EVERYTHING UNDER HERE IS FOR TESTING THE FUNCTIONS
// 	t_head	*heads;
	
// 	ft_check_args(argv);
// 	heads = create_stacks(argc, argv);
// 	check_duplicates(heads->head_a);
	
// 	printf("\n----------CREATING STACKS ----------:\n");
// 	print_stacks(heads);
	

	
// 	int sorted = check_if_sorted(heads);
// 	printf("Is A sorted: %d\n", sorted);
	
// 	int total_nodes = count_nodes(heads);
// 	printf("total_nodes in A: %d\n", total_nodes);
	
// 	t_node *minpointer = find_min(heads);
// 	printf("Node with minimum value: %p\n", minpointer);
	
// 	t_node *maxpointer = find_max(heads);
// 	printf("node with maximum value: %p\n", maxpointer);

// 	ft_sort_three(heads);
// 	printf("\n----------Sorts 3 elements in A ----------:\n");
// 	print_stacks(heads);
	
// 	printf("\n----------SA switch 1st and 2nd in A ----------:\n");
// 	ft_sa(heads,1);
// 	print_stacks(heads);
	
// 	printf("\n----------RA switch 1st and last in A ----------:\n");
// 	ft_ra(heads, 1);
// 	print_stacks(heads);

// 	printf("\n----------RRA last becomes first in A ----------:\n");
// 	ft_rra(heads, 1);
// 	print_stacks(heads);
	
// 	printf("\n----------PA 1st from B to A ----------: NO EFFECT\n");
// 	ft_pa(heads, 1);
// 	print_stacks(heads);

// 	printf("\n----------PB first from A to B ----------: X 3 TIMES\n");
// 	ft_pb(heads, 1);
// 	ft_pb(heads, 1);
// 	ft_pb(heads, 1);
// 	print_stacks(heads);

// 	printf("\n----------SB 1st and 2nd in B ----------:\n");
// 	ft_sb(heads, 1);
// 	print_stacks(heads);

// 	printf("\n----------RB 1st to last in B ----------:\n");
// 	ft_rb(heads, 1);
// 	print_stacks(heads);

// 	printf("\n----------RRB last to 1st in B ----------:\n");
// 	ft_rrb(heads, 1);
// 	print_stacks(heads);

// 	printf("\n----------SS 1st and 2nd in A and B ----------:\n");
// 	ft_ss(heads, 1);
// 	print_stacks(heads);

// 	printf("\n----------RR 1st to last in A and B ----------:\n");
// 	ft_rr(heads, 1);
// 	print_stacks(heads);

// 	printf("\n----------RRR last to 1st in A and B ----------:\n");
// 	ft_rrr(heads, 1);
// 	print_stacks(heads);

// 	printf("\n----------PB first from A to B ----------: X 3 TIMES\n");
// 	ft_pb(heads, 1);
// 	ft_pb(heads, 1);
// 	ft_pb(heads, 1);
// 	print_stacks(heads);

// 	printf("\n----------SA with one element ----------:\n");
// 	ft_pa(heads, 1);
// 	ft_sa(heads, 1);
// 	print_stacks(heads);

// 	printf("\n----------PB first from A to B ----------: LAST ONE\n");
// 	ft_pb(heads, 1);
// 	ft_pb(heads, 1);
// 	print_stacks(heads);

// 	printf("\n----------PB first from A to B ----------: NO EFFECT\n");
// 	ft_pb(heads, 1);
// 	print_stacks(heads);
	
	

// 	free(heads);
	
// 	return (0);

	
// }
