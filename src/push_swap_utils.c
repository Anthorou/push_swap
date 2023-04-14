/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroussea <aroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 15:42:41 by aroussea          #+#    #+#             */
/*   Updated: 2023/03/30 15:19:04 by aroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	check_order(t_stack *stack)
{
	t_list	*current;
	int		i;

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

static t_list	*findex_finder(t_list *list, int index)
{
	int	i;
	int	size;

	i = 0;
	size = ft_lstsize(list);
	while (i < size)
	{
		if (list->findex == index)
			return (list);
		i++;
		list = list->next;
	}
	return (NULL);
}

static void	give_index(t_stack *stack)
{
	int		i;
	t_list	*current;

	i = 0;
	current = stack->stack_a;
	while (i < ft_lstsize(stack->stack_a))
	{
		current->findex = i++;
		current = current->next;
	}
}

static void	tri_findex(t_stack *stack, int j)
{
	t_list	*current;
	t_list	*next_findex;
	int		tmp;

	current = findex_finder(stack->stack_a, j);
	next_findex = findex_finder(stack->stack_a, j + 1);
	if (next_findex && (current->content > next_findex->content))
	{
		tmp = next_findex->findex;
		next_findex->findex = current->findex;
		current->findex = tmp;
	}
}

void	findex_bubble_sort(t_stack *stack)
{
	int		i;
	int		j;
	t_list	*current;

	give_index(stack);
	i = 0;
	while (i < ft_lstsize(stack->stack_a))
	{
		j = 0;
		current = stack->stack_a;
		while (j < ft_lstsize(stack->stack_a) - i)
		{
			tri_findex(stack, j);
			j++;
		}
		i++;
	}
}
