/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nassaf <nassaf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 17:24:40 by nassaf            #+#    #+#             */
/*   Updated: 2024/09/23 08:41:41 by nassaf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_print_error(char *str)
{
	write(1, "Error - ", 8);
	write(1, str, 3);
	write(1, "\n", 1);
	exit(1);
}

int	ft_check_number(int c)
{
	return (c >= '0' && c <= '9');
}

int	ft_check_sign(int c)
{
	return (c == '-' || c == '+');
}

int	ft_check_space(int c)
{
	return (c == ' ');
}

int	ft_check_args(char **argv)
{
	int	i;
	int	j;

	i = 1;
	if (!argv[1] || argv[1][0] == '\0')
		exit (1);
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_check_number(argv[i][j]) && !ft_check_space(argv[i][j])
					&& !ft_check_sign(argv[i][j]))
				ft_print_error("char");
			if (ft_check_sign(argv[i][j]) && !ft_check_number(argv[i][j + 1]))
				ft_print_error("sin");
			if (ft_check_sign(argv[i][j]) && ft_check_sign(argv[i][j+1]))
				ft_print_error("sin");
			if (ft_check_space(argv[i][j]) && ft_check_space(argv[i][j+1]))
				ft_print_error("spc");
			j++;
		}
		i++;
	}
	return (0);
}
