/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echarmai <echarmai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 15:50:57 by echarmai          #+#    #+#             */
/*   Updated: 2025/11/12 16:23:56 by echarmai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	(n / 10 && (ft_putnbr_fd(n / 10, fd), 1)) || (write(fd, "-", n < 0), 0);
	if (n < 0)
		write(fd, &(char){(n % 10 * -1) + 48}, 1);
	else
		write(fd, &(char){n % 10 + 48}, 1);
}

// int	main(void)
// {
// 	int	fd;
// 	int	n;

// 	fd = 2;
// 	n = 2147483647;
// 	ft_putnbr_fd(n, fd);
// }
