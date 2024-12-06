/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nic <Nic@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 20:55:59 by nassaf            #+#    #+#             */
/*   Updated: 2024/10/05 20:18:23 by Nic              ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>

typedef struct s_node
{
	int				data;
	int				index;
	int				position;
	struct s_node	*next;
	struct s_node	*previous;
}	t_node;

typedef struct s_head
{
	t_node	*head_a;
	t_node	*head_b;
	int		counter;
}	t_head;

typedef struct count_operations
{
	int	counter;
}	count_ops;

//algo/sort1.c
void	ft_insert_index(t_node *head_a);
int		get_max_n_of_bits(t_node *head_a);
int		get_stack_len(t_node *head_a);
void	ft_position_in_stack(t_node *head_x);
void	push_min_to_b(t_head *heads);

//algo/sort2.c
int		ft_sort_2(t_head *heads);
void	ft_sort_3(t_head *heads);
void	ft_sort_4(t_head *heads);
void	ft_sort_5(t_head *heads);

//algo/sort3.c
int 	compare_bits(t_head *heads, int bit_number, int stack_len);
void    return_to_a(t_head *heads, int counter);
void	ft_sort_6(t_head *heads);
void    ft_sort_all(t_head *heads, int stack_len);

//checks/checks.c
void	ft_print_error(char *str);
int		ft_check_number(int c);
int		ft_check_sign(int c);
int		ft_check_space(int c);
int		ft_check_args(char **argv);

//checks/checks2.c
int		check_max(int c);
int		check_duplicates(t_node *head, t_head *heads);
int 	check_if_sorted (t_head *heads);

//libft/ft_atoi.c
int		ft_atoi(const char *nptr);

//libft/ft_split.c
void			*ft_memcpy(void *dest, const void *src, size_t n);
char			*ft_strdup(const char *s);
size_t			ft_strlcpy(char *dst, const char *src, size_t size);
char			*ft_substr(char const *s, unsigned int start, size_t len);
unsigned long	ft_strlen(const char *s);

//libft/ft_split2.c
//static size_t	count_word(const char *s, char c);
//static	size_t	get_word_len(const char *s, char c);
//static void		free_array(char **array, size_t i);
//static char		**split(char const *s, char c, char **array, size_t words_count);
char			**ft_split(char const *s, char c);

//operations/op_a.c
void	ft_sa(t_head *heads, int print);
void	ft_ra(t_head *heads, int print);
void	ft_rra(t_head *heads, int print);
void	ft_pa(t_head *heads, int print);

//operations/op_c
void	ft_sb(t_head *heads, int print);
void	ft_rb(t_head *heads, int print);
void	ft_rrb(t_head *heads, int print);
void	ft_pb(t_head *heads, int print);

//operations/ops.c
t_node	*get_last_node(t_node *head);
void	ft_ss(t_head *heads, int print);
void	ft_rr(t_head *heads, int print);
void	ft_rrr(t_head *heads, int print);	

//check//create_stack.c
t_node	*create_node(int data);
t_node	*create_first_node(t_node **head, t_node **tail, t_node *new_node);
t_node	*create_stack_from_array(int argc, char **array);
t_head	*create_stacks(int argc, char **argv);
void	ft_free_stack(t_head *heads);

//checks/min_max.c
t_node *find_min(t_node *head_x);
t_node	*find_max(t_node *head_x);





//checks/op_a.c


//checks/op_b.c




//check/push_swap.c
//void	print_stacks(t_head *heads);




#endif