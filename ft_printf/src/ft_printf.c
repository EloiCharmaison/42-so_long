/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eloi <eloi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 13:14:12 by echarmai          #+#    #+#             */
/*   Updated: 2025/11/21 21:13:36 by eloi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	print_arg(char c, va_list args);

int	ft_printf(const char *str, ...) 
{
	va_list	args;
	int		i;
	int		count;

	va_start(args, str);
	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			count += print_arg(str[i], args);
		}
		else
			count += ft_print_chr(str[i]);
		i++;
	}
	va_end(args);
	return (count);
}

static int	print_arg(char c, va_list args)
{
	if (c == '%')
		return (ft_print_chr('%'));
	else if (c == 'c')
		return (ft_print_chr(va_arg(args, int)));
	else if (c == 's')
		return (ft_print_str(va_arg(args, char *)));
	else if (c == 'd' || c == 'i')
		return (ft_print_nbr(va_arg(args, int)));
	else if (c == 'u')
		return (ft_print_unsigned(va_arg(args, unsigned int)));
	else if (c == 'x')
		return (ft_print_hex(va_arg(args, unsigned int)));
	else if (c == 'X')
		return (ft_print_hexmaj(va_arg(args, unsigned int)));
	else if (c == 'p')
		return (ft_print_ptr(va_arg(args, void *)));
	else
		return (0);
}
