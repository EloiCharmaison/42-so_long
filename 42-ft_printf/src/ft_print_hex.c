/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echarmai <echarmai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 13:18:54 by echarmai          #+#    #+#             */
/*   Updated: 2025/11/21 12:50:51 by echarmai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include <unistd.h>

int	ft_print_hex(unsigned int n)
{
	char	c;
	int		count;

	count = 0;
	if (n >= 16)
		count += ft_print_hex(n / 16);
	c = "0123456789abcdef"[n % 16];
	count += ft_print_chr(c);
	return (count);
}
