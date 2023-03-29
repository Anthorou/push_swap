/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroussea <aroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 13:44:13 by aroussea          #+#    #+#             */
/*   Updated: 2023/03/27 16:35:24 by aroussea         ###   ########.fr       */
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
# include <stdio.h>

typedef struct s_stack
{
	t_list *stack_a;
	t_list *stack_b;
}	t_stack;

typedef struct s_bloc
{
	int bloc_1;
	int bloc_2;
	int bloc_3;
	int bloc_4;
	int bloc_5;
	int bloc_6;
	int bloc_7;
	int bloc_8;
	int bloc_9;
	int bloc_10;
	int bloc_11;
	int bloc_12;
	int bloc_13;
	int bloc_14;
	int bloc_15;
	int bloc_16;
	int bloc_17;
}	t_bloc;

t_stack	*args_parsing(int argc, char **argv);
t_stack	*ft_free_stack(t_stack *stack);
t_list	*ft_free_list(t_list *list);
int		swap(t_list **list, char c);
int		ss(t_stack *stack);
int		push_b(t_stack *stack);
int		push_a(t_stack *stack);
int		rotate(t_list **list, char c);
int		rr(t_stack *stack);
int		reverse_rotate(t_list **list, char c);
int		rrr(t_stack *stack);
void	push_swap(t_stack *stack);
int		check_order(t_stack *stack);
void	findex_bubble_sort(t_stack *stack);
int		findex_max(t_stack * stack);
int		findex_min(t_stack * stack);

#endif