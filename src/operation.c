/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroussea <aroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 13:15:10 by aroussea          #+#    #+#             */
/*   Updated: 2023/03/30 14:33:42 by aroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	swap(t_list **list, char c)
{
	t_list	*third;
	t_list	*first;
	t_list	*second;

	first = *list;
	second = first->next;
	third = second->next;
	second->next = first;
	first->next = third;
	*list = second;
	write(1, "s", 1);
	write(1, &c, 1);
	write (1, "\n", 1);
}

void	ss(t_stack *stack)
{
	swap(&stack->stack_a, 'a');
	swap(&stack->stack_b, 'b');
}

void	push_a(t_stack *stack)
{
	t_list	*first_b;

	first_b = stack->stack_b;
	stack->stack_b = first_b->next;
	ft_lstadd_front(&stack->stack_a, first_b);
	write(1, "pa\n", 3);
}

void	push_b(t_stack *stack)
{
	t_list	*first_a;

	first_a = stack->stack_a;
	stack->stack_a = first_a->next;
	ft_lstadd_front(&stack->stack_b, first_a);
	write(1, "pb\n", 3);
}

void	rotate(t_list **list, char c)
{
	t_list	*first;

	first = *list;
	*list = first->next;
	first->next = NULL;
	ft_lstadd_back(list, first);
	write(1, "r", 1);
	write(1, &c, 1);
	write (1, "\n", 1);
}
