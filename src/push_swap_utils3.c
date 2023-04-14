/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroussea <aroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 16:50:22 by aroussea          #+#    #+#             */
/*   Updated: 2023/03/30 16:53:43 by aroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	fin(t_stack *stack)
{
	int	p;

	p = findex_finder_p(stack->stack_a, 0);
	if (p > ft_lstsize(stack->stack_a) / 2)
	{
		while (stack->stack_a->findex != 0)
			reverse_rotate(&stack->stack_a, 'a');
	}
	while (stack->stack_a->findex != 0)
		rotate(&stack->stack_a, 'a');
}

void	find_spot(t_stack *stack, int max)
{
	int		p;
	t_list	*plus_grand;

	plus_grand = find_grand(&stack->stack_a, stack->stack_b->findex, max);
	p = findex_finder_p(stack->stack_a, plus_grand->findex);
	while (p != -1)
	{
		if (plus_grand->findex == stack->stack_a->findex)
		{
			p = -1;
			push_a(stack);
		}
		else if (p > ft_lstsize(stack->stack_a) / 2)
			reverse_rotate(&stack->stack_a, 'a');
		else
			rotate(&stack->stack_a, 'a');
	}
}

void	plus_min_max(t_stack *stack, int max_ou_pas, int min)
{
	int	p;

	p = findex_finder_p(stack->stack_a, min);
	if (p > ft_lstsize(stack->stack_a) / 2)
	{
		while (stack->stack_a->findex != min)
			reverse_rotate(&stack->stack_a, 'a');
	}
	else
	{
		while (stack->stack_a->findex != min)
			rotate(&stack->stack_a, 'a');
	}
	push_a(stack);
	if (max_ou_pas == 1)
		rotate(&stack->stack_a, 'a');
}

void	bloc_handler(t_stack *stack)
{
	int	i;
	int	j;
	int	nb;
	int	*blocs;
	int	size;

	size = ft_lstsize(stack->stack_a);
	if (size <= 100)
		nb = 8;
	else
		nb = 18;
	blocs = create_bloc(nb, size);
	j = nb / 2;
	i = j - 1;
	while (i > 0)
	{
		bloc_bloc(stack, blocs[i], blocs[j], blocs[i - 1]);
		i--;
		j++;
	}
	bloc1(stack, blocs[0]);
	free(blocs);
}

int	*create_bloc(int nb, int size)
{
	int	*blocs;
	int	i;

	i = 0;
	blocs = (int *)malloc(sizeof(int) * size - 1);
	while (i < nb - 1)
	{
		if (i == 0)
			blocs[i] = size / nb;
		else
			blocs[i] = blocs[i - 1] + blocs[0];
		i++;
	}
	return (blocs);
}
