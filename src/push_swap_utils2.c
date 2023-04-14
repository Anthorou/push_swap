/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroussea <aroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 15:56:07 by aroussea          #+#    #+#             */
/*   Updated: 2023/03/30 16:49:41 by aroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	findex_max(t_stack *stack)
{
	int		max;
	int		i;
	int		size;
	t_list	*current;

	max = 0;
	current = stack->stack_a;
	size = ft_lstsize(stack->stack_a);
	i = 0;
	while (i < size)
	{
		if (current->findex > max)
			max = current->findex;
		current = current->next;
		i++;
	}
	return (max);
}

int	findex_min(t_stack *stack)
{
	int		min;
	int		i;
	int		size;
	t_list	*current;

	min = ft_lstsize(stack->stack_a) + ft_lstsize(stack->stack_b);
	current = stack->stack_a;
	size = ft_lstsize(stack->stack_a);
	i = 0;
	while (i < size)
	{
		if (current->findex < min)
			min = current->findex;
		current = current->next;
		i++;
	}
	return (min);
}

void	reste_stackb_util(t_stack *stack, int pos, int index)
{
	pos = findex_finder_p(stack->stack_a, index);
	if (pos <= 4 - (pos + 1))
	{
		while (stack->stack_a->findex != index)
			rotate(&stack->stack_a, 'a');
	}
	else
	{
		while (stack->stack_a->findex != index)
			reverse_rotate(&stack->stack_a, 'a');
	}
}

void	min_ou_max(t_stack *stack, int *min, int *max)
{
	int	max_r;
	int	min_r;

	min_r = 5 - (*min + 1);
	max_r = 5 - (*max + 1);
	if (*min < *max && *min < min_r && *min < max_r)
		operation_5(stack, 0, 'c', min);
	else if (*max < *min && *max < min_r && *max < max_r)
		operation_5(stack, 4, 'c', max);
	else if (min_r <= *max && min_r < *min && min_r < max_r)
		operation_5(stack, 0, 'r', min);
	else
		operation_5(stack, 4, 'r', max);
}

void	operation_5(t_stack *stack, int index, char c, int *num)
{
	if (c == 'r')
	{
		while (stack->stack_a->findex != index)
			reverse_rotate(&stack->stack_a, 'a');
		push_b(stack);
	}
	else
	{
		while (stack->stack_a->findex != index)
			rotate(&stack->stack_a, 'a');
		push_b(stack);
	}
	*num = -1;
}
