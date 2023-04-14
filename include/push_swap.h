/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroussea <aroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 13:44:13 by aroussea          #+#    #+#             */
/*   Updated: 2023/03/30 17:02:47 by aroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "../libft/libft.h"

typedef struct s_stack
{
	t_list	*stack_a;
	t_list	*stack_b;
}	t_stack;

t_stack	*args_parsing(int argc, char **argv);
t_stack	*ft_free_stack(t_stack *stack);
t_list	*ft_free_list(t_list *list);
void	swap(t_list **list, char c);
void	ss(t_stack *stack);
void	push_b(t_stack *stack);
void	push_a(t_stack *stack);
void	rotate(t_list **list, char c);
void	rr(t_stack *stack);
void	reverse_rotate(t_list **list, char c);
void	rrr(t_stack *stack);
void	push_swap(t_stack *stack);
int		check_order(t_stack *stack);
void	findex_bubble_sort(t_stack *stack);
int		findex_max(t_stack *stack);
int		findex_min(t_stack *stack);
void	reste_stackb_util(t_stack *stack, int pos, int index);
void	min_ou_max(t_stack *stack, int *min, int *max);
void	operation_5(t_stack *stack, int index, char c, int *num);
void	fin(t_stack *stack);
void	find_spot(t_stack *stack, int max);
void	plus_min_max(t_stack *stack, int max_ou_pas, int min);
void	bloc_handler(t_stack *stack);
int		*create_bloc(int nb, int size);
void	bloc1(t_stack *stack, int bloc1);
void	bloc_bloc(t_stack *stack, int bloc1, int bloc2, int bloc3);
t_list	*find_grand(t_list **list, int findex, int max);
int		findex_finder_p(t_list *list, int index);

#endif