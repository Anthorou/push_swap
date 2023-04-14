/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroussea <aroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 13:46:56 by aroussea          #+#    #+#             */
/*   Updated: 2023/04/13 17:20:52 by aroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	check_int(char *str, t_list **stack_a)
{
	int		i;
	long	check;
	t_list	*current;

	i = 0;
	while (str[i])
	{
		if (i == 0 && str[i] == '-' && ft_isdigit(str[i + 1]))
			i++;
		else if (!ft_isdigit(str[i++]))
			return (0);
	}
	check = ft_atoi(str);
	if (check > 2147483647 || check < -2147483648)
		return (0);
	i = 0;
	current = *stack_a;
	while (current)
	{
		if (current->content == check)
			return (0);
		current = current->next;
	}
	ft_lstadd_back(stack_a, ft_lstnew(check));
	return (1);
}

static int	check_stack(t_list *stack, long tmp)
{
	t_list	*current;

	current = stack;
	if (tmp > 2147483647 || tmp < -2147483648)
		return (0);
	while (current)
	{
		if (current->content == tmp)
			return (0);
		current = current->next;
	}
	return (1);
}

static t_list	*put_stack(t_list *stack, char *str, int i)
{
	int		x;
	int		j;
	long	tmp;

	x = 0;
	while (str[i])
	{
		while (str[i] && str[i] == ' ')
			i++;
		if (str[i])
		{
			j = 0;
			tmp = ft_atoi(&str[i]);
			if (!check_stack(stack, tmp))
			{
				ft_free_list(stack);
				return (NULL);
			}
			ft_lstadd_back(&stack, ft_lstnew(ft_atoi(&str[i])));
		}
		while (str[i] && str[i] != ' ')
			i++;
	}
	return (stack);
}

static t_list	*parse_string(char *str)
{
	int		i;
	t_list	*stack_a;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && str[i] != ' ' && str[i] != '-')
			return (NULL);
		if (i > 0 && str[i] == '-' && str[i - 1] != ' ')
			return (NULL);
		if (str[i] == '-' && !ft_isdigit(str[i + 1]))
			return (NULL);
		i++;
	}
	i = ft_count_words(str, ' ');
	stack_a = NULL;
	i = 0;
	return (put_stack(stack_a, str, i));
}

t_stack	*args_parsing(int argc, char **argv)
{
	int		i;
	t_list	*stack_a;
	t_stack	*stack;

	i = 1;
	if (argc == 2)
	{
		stack_a = parse_string(argv[1]);
		if (!stack_a)
			return (NULL);
	}
	else
	{
		stack_a = NULL;
		while (i < argc)
		{
			if (!check_int(argv[i], &stack_a))
				return ((t_stack *)ft_free_list(stack_a));
			i++;
		}
	}
	stack = (t_stack *)malloc(sizeof(t_stack));
	stack->stack_a = stack_a;
	return (stack);
}
