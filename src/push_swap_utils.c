/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroussea <aroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 15:42:41 by aroussea          #+#    #+#             */
/*   Updated: 2023/03/29 16:47:46 by aroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int check_order(t_stack *stack)
{
	t_list *current;
	int i;

	i = 0;
	current = stack->stack_a;
	while (i < ft_lstsize(stack->stack_a) - 1)
	{
		if (current->content > current->next->content)
			return (0);
		current = current->next;
		i++;
	}
	return (1);
}

static t_list *findex_finder(t_list *list, int index)
{
	int i;
	int size;
	
	i = 0;
	size = ft_lstsize(list);
	while (i < size)
	{
		if (list->findex == index)
			return(list);
		i++;
		list = list->next;
	}
	return (NULL);
}

void findex_bubble_sort(t_stack *stack)
{
	int i;
	int j;
	int tmp;
	t_list *current;
	t_list *next_findex;

	i = 0;
	current = stack->stack_a;
	while (i < ft_lstsize(stack->stack_a))
	{
		current->findex = i++;
		current = current->next;
	}
	i = 0;
	while (i < ft_lstsize(stack->stack_a))
	{
		j = 0;
		current = stack->stack_a;
		while (j < ft_lstsize(stack->stack_a) - i)
		{
			current = findex_finder(stack->stack_a, j);
			next_findex = findex_finder(stack->stack_a, j + 1);
			if (next_findex && (current->content > next_findex->content))
			{
				tmp = next_findex->findex;
				next_findex->findex = current->findex;
				current->findex = tmp;
			}
			j++;
		}
		i++;
	}
}

int findex_max(t_stack * stack)
{
	int max;
	int i;
	int size;
	t_list *current;
	
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

int findex_min(t_stack * stack)
{
	int min;
	int i;
	int size;
	t_list *current;
	
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
