/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexmaj.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echarmai <echarmai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 15:59:16 by echarmai          #+#    #+#             */
/*   Updated: 2025/11/21 14:52:12 by echarmai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include <unistd.h>

int	ft_print_hexmaj(unsigned int n)
{
	char	c;
	int		count;

	count = 0;
	if (n >= 16)
		count += ft_print_hexmaj(n / 16);
	c = "0123456789ABCDEF"[n % 16];
	count += ft_print_chr(c);
	return (count);
}
