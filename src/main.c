/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroussea <aroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 13:54:58 by aroussea          #+#    #+#             */
/*   Updated: 2023/03/21 17:54:04 by aroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack;
	// t_list *current;
	int	i;

	i = 0;
	if (argc > 1)
	{
		stack = args_parsing(argc, argv);
		if (!stack)
		{
			stack = ft_free_stack(stack);
			write(1, "Error\n", 7);
			return (1);
		}
		push_swap(stack);
		// current = stack->stack_a;
		// while (current)
		// {
		// 	printf("%i ; faux_index : %i\n", current->content, current->findex);
		// 	current = current->next;
		// }
		// printf("\n");
		// current = stack->stack_b;
		// while (current)
		// {
		// 	printf("%i\n", current->content);
		// 	current = current->next;
		// }
		stack = ft_free_stack(stack);
		return (0);
	}
	write(1, "Error\n", 7);
	return (1);
}
