/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echarmai <echarmai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 15:47:38 by echarmai          #+#    #+#             */
/*   Updated: 2025/11/21 14:49:58 by echarmai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../ft_printf.h"
#include <unistd.h>

int	ft_print_nbr(int n)
{
	long	nb;
	int		count;

	nb = n;
	count = 0;
	if (nb < 0)
	{
		write(1, "-", 1);
		nb *= -1;
		count++;
	}
	if (nb >= 10)
		count += ft_print_nbr(nb / 10);
	count += ft_print_chr(nb % 10 + 48);
	return (count);
}
