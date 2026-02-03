/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echarmai <echarmai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 16:22:15 by echarmai          #+#    #+#             */
/*   Updated: 2025/11/21 14:35:06 by echarmai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include <unistd.h>

static int	ft_print_ptr_hex(unsigned long n);

int	ft_print_ptr(void *ptr)
{
	if (!ptr)
		return (ft_print_str("(nil)"));
	ft_print_str("0x");
	return (ft_print_ptr_hex((unsigned long)ptr) + 2);
}

static int	ft_print_ptr_hex(unsigned long n)
{
	char	c;
	int		count;

	count = 0;
	if (n >= 16)
		count += ft_print_ptr_hex(n / 16);
	c = "0123456789abcdef"[n % 16];
	count += ft_print_chr(c);
	return (count);
}
