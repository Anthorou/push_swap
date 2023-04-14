/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils4.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroussea <aroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 16:54:29 by aroussea          #+#    #+#             */
/*   Updated: 2023/03/30 16:56:25 by aroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	bloc1(t_stack *stack, int bloc1)
{
	int	i;
	int	size;

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

void	bloc_bloc(t_stack *stack, int bloc1, int bloc2, int bloc3)
{
	int	size;
	int	i;

	size = ft_lstsize(stack->stack_a);
	i = 0;
	while (i < size)
	{
		if (stack->stack_a->findex > bloc3 && stack->stack_a->findex <= bloc1)
		{
			push_b(stack);
			rotate(&stack->stack_b, 'b');
		}
		else if (stack->stack_a->findex > bloc1
			&& stack->stack_a->findex <= bloc2)
			push_b(stack);
		else
			rotate(&stack->stack_a, 'a');
		i++;
	}
}

t_list	*find_grand(t_list **list, int findex, int max)
{
	t_list	*current;
	int		size;
	int		i;

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

int	findex_finder_p(t_list *list, int index)
{
	int	i;
	int	size;

	i = 0;
	size = ft_lstsize(list);
	while (i < size)
	{
		if (list->findex == index)
			return (i);
		i++;
		list = list->next;
	}
	return (-1);
}
