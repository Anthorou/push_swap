/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroussea <aroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 13:43:42 by aroussea          #+#    #+#             */
/*   Updated: 2023/03/29 17:29:06 by aroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int findex_finder_p(t_list *list, int index)
{
	int i;
	int size;
	
	i = 0;
	size = ft_lstsize(list);
	while (i < size)
	{
		if (list->findex == index)
			return(i);
		i++;
		list = list->next;
	}
	return (-1);
}

static t_list *find_grand(t_list **list, int findex, int max)
{
	t_list *current;
	int size;
	int i;
	
	current = *list;
	size = ft_lstsize(current);
	findex++;
	while (findex <= max)
	{
		i = 0;
		while (i < size)
		{
			if (current->findex == findex)
				return (current);
			i++;
			current = current->next;
		}
		current = *list;
		findex++;
	}
	return (NULL);
}

static void bloc_bloc(t_stack *stack, int bloc1, int bloc2, int bloc3)
{
	int size;
	int i;
	
	size = ft_lstsize(stack->stack_a);
	i = 0;
	while (i < size)
	{
		if (stack->stack_a->findex > bloc3 && stack->stack_a->findex <= bloc1)
		{
			push_b(stack);
			rotate(&stack->stack_b, 'b');
		}
		else if (stack->stack_a->findex > bloc1 && stack->stack_a->findex <= bloc2)
			push_b(stack);
		else
			rotate(&stack->stack_a, 'a');
		i++;
	}
}

static void bloc1(t_stack *stack, int bloc1)
{
	int i;
	int size;

	i = 0;
	size = ft_lstsize(stack->stack_a);
	while (i < size)
	{
		if (stack->stack_a->findex <= bloc1)
		{
			push_b(stack);
			rotate(&stack->stack_b, 'b');
		}
		else
			push_b(stack);
		i++;
	}
}

static t_bloc *create_bloc(int nb, int size)
{
	t_bloc *blocs;

	blocs = (t_bloc *)malloc(sizeof(t_bloc));
	if (nb == 8)
	{
		blocs->bloc_1 = size / 8;
		blocs->bloc_3 = blocs->bloc_1 * 2;
		blocs->bloc_3 = blocs->bloc_2 + blocs->bloc_1;
		blocs->bloc_4 = blocs->bloc_3 + blocs->bloc_1;
		blocs->bloc_5 = blocs->bloc_4 + blocs->bloc_1;
		blocs->bloc_6 = blocs->bloc_5 + blocs->bloc_1;
		blocs->bloc_7 = blocs->bloc_6 + blocs->bloc_1;
	}
	else
	{
		blocs->bloc_1 = size / 18;
		blocs->bloc_2 = blocs->bloc_1 * 2;
		blocs->bloc_3 = blocs->bloc_2 + blocs->bloc_1;
		blocs->bloc_4 = blocs->bloc_3 + blocs->bloc_1;
		blocs->bloc_5 = blocs->bloc_4 + blocs->bloc_1;
		blocs->bloc_6 = blocs->bloc_5 + blocs->bloc_1;
		blocs->bloc_7 = blocs->bloc_6 + blocs->bloc_1;
		blocs->bloc_8 = blocs->bloc_7 + blocs->bloc_1;
		blocs->bloc_9 = blocs->bloc_8 + blocs->bloc_1;
		blocs->bloc_10 = blocs->bloc_9 + blocs->bloc_1;
		blocs->bloc_11 = blocs->bloc_10 + blocs->bloc_1;
		blocs->bloc_12 = blocs->bloc_11 + blocs->bloc_1;
		blocs->bloc_13 = blocs->bloc_12 + blocs->bloc_1;
		blocs->bloc_14 = blocs->bloc_13 + blocs->bloc_1;
		blocs->bloc_15 = blocs->bloc_14 + blocs->bloc_1;
		blocs->bloc_16 = blocs->bloc_15 + blocs->bloc_1;
		blocs->bloc_17 = blocs->bloc_16 + blocs->bloc_1;
	}
	return (blocs);
}

static void bloc_handler(t_stack *stack)
{
	t_bloc *blocs;
	int size;
	
	size = ft_lstsize(stack->stack_a);
	if (size <= 100)
	{
		blocs = create_bloc(8, size);
		bloc_bloc(stack, blocs->bloc_4, blocs->bloc_5, blocs->bloc_3);
		bloc_bloc(stack, blocs->bloc_3, blocs->bloc_6, blocs->bloc_2);
		bloc_bloc(stack, blocs->bloc_2, blocs->bloc_7, blocs->bloc_1);
		bloc1(stack, blocs->bloc_1);
	}
	else
	{
		blocs = create_bloc(18, size);
		bloc_bloc(stack, blocs->bloc_9, blocs->bloc_10, blocs->bloc_8);
		bloc_bloc(stack, blocs->bloc_8, blocs->bloc_11, blocs->bloc_7);
		bloc_bloc(stack, blocs->bloc_7, blocs->bloc_12, blocs->bloc_6);
		bloc_bloc(stack, blocs->bloc_6, blocs->bloc_13, blocs->bloc_5);
		bloc_bloc(stack, blocs->bloc_5, blocs->bloc_14, blocs->bloc_4);
		bloc_bloc(stack, blocs->bloc_4, blocs->bloc_15, blocs->bloc_3);
		bloc_bloc(stack, blocs->bloc_3, blocs->bloc_16, blocs->bloc_2);
		bloc_bloc(stack, blocs->bloc_2, blocs->bloc_17, blocs->bloc_1);
		bloc1(stack, blocs->bloc_1);
	}
	free(blocs);
}

static void plus_min_max(t_stack *stack, int max_ou_pas, int min)
{
	int p;
	
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

static void find_spot(t_stack *stack, int max)
{
	int p;
	t_list *plus_grand;
	
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

static void algo(t_stack *stack)
{
	int size;
	int min;
	int max;
	int i;
	int p;
	
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
	p = findex_finder_p(stack->stack_a, 0);
	if (p > ft_lstsize(stack->stack_a) / 2)
	{
		while (stack->stack_a->findex != 0)
			reverse_rotate(&stack->stack_a, 'a');
	}
	while (stack->stack_a->findex != 0)
		rotate(&stack->stack_a, 'a');
}

static void algo_3(t_stack *stack)
{
	int max;
	
	max = findex_max(stack);
	if (stack->stack_a->findex == max)
		rotate(&stack->stack_a, 'a');
	else if (stack->stack_a->next->findex == max)
		reverse_rotate(&stack->stack_a, 'a');
	if (stack->stack_a->findex > stack->stack_a->next->findex)
		swap(&stack->stack_a, 'a');
}

static void operation_5(t_stack *stack, int index, char c, int *num)
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

static void	min_ou_max(t_stack *stack, int *min, int *max)
{
	int max_r;
	int min_r;

	min_r = 5 - (*min + 1);
	max_r = 5 - (*max + 1);
	if (*min < *max && *min < min_r && *min < max_r)
		operation_5(stack, 0, 'c', min);
	else if (*max < *min && *max < min_r && *max < max_r)
		operation_5(stack, 4, 'c', max);
	else if (min_r < *max && min_r < *min && min_r < max_r)
		operation_5(stack, 0, 'r', min);
	else
		operation_5(stack, 4, 'r', max);
}

static void reste_stackb_util(t_stack *stack, int pos, int index)
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

static void algo_5(t_stack *stack)
{
	int min_p;
	int max_p;
	
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
	if (size == 3)
		algo_3(stack);
	else if (size == 5)
		algo_5(stack);
	else
		algo(stack);
}

void	push_swap(t_stack *stack)
{
	int i;
	
	i = 0;
	if (!check_order(stack))
	{
		findex_bubble_sort(stack);
		algo_decideur(stack, ft_lstsize(stack->stack_a));
	}
}
