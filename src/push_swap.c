/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroussea <aroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 13:43:42 by aroussea          #+#    #+#             */
/*   Updated: 2023/03/30 16:56:39 by aroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	algo(t_stack *stack)
{
	int	size;
	int	min;
	int	max;
	int	i;

	bloc_handler(stack);
	i = 2;
	size = ft_lstsize(stack->stack_b);
	push_a(stack);
	push_a(stack);
	if (stack->stack_a->findex > stack->stack_a->next->findex)
		swap(&stack->stack_a, 'a');
	while (i < size)
	{
		max = findex_max(stack);
		min = findex_min(stack);
		if (stack->stack_b->findex < min)
			plus_min_max(stack, 0, min);
		else if (stack->stack_b->findex > max)
			plus_min_max(stack, 1, min);
		else
			find_spot(stack, max);
		i++;
	}
	fin(stack);
}

static void	algo_3(t_stack *stack)
{
	int	max;

	max = findex_max(stack);
	if (stack->stack_a->findex == max)
		rotate(&stack->stack_a, 'a');
	else if (stack->stack_a->next->findex == max)
		reverse_rotate(&stack->stack_a, 'a');
	if (stack->stack_a->findex > stack->stack_a->next->findex)
		swap(&stack->stack_a, 'a');
}

static void	algo_5(t_stack *stack)
{
	int	min_p;
	int	max_p;

	min_p = findex_finder_p(stack->stack_a, 0);
	max_p = findex_finder_p(stack->stack_a, 4);
	min_ou_max(stack, &min_p, &max_p);
	if (max_p == -1)
		reste_stackb_util(stack, min_p, 0);
	else
		reste_stackb_util(stack, max_p, 4);
	push_b(stack);
	algo_3(stack);
	if (stack->stack_b->findex == 4)
	{
		push_a(stack);
		rotate(&stack->stack_a, 'a');
		push_a(stack);
	}
	else
	{
		push_a(stack);
		push_a(stack);
		rotate(&stack->stack_a, 'a');
	}
}

static void	algo_decideur(t_stack *stack, int size)
{
	if (size <= 3)
		algo_3(stack);
	else if (size == 5)
		algo_5(stack);
	else
		algo(stack);
}

void	push_swap(t_stack *stack)
{
	int	i;

	i = 0;
	if (!check_order(stack))
	{
		findex_bubble_sort(stack);
		algo_decideur(stack, ft_lstsize(stack->stack_a));
	}
}
