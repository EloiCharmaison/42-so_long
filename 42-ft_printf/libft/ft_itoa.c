/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echarmai <echarmai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 14:07:21 by echarmai          #+#    #+#             */
/*   Updated: 2025/11/17 15:51:00 by echarmai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

static int	ft_intlen(int n);
static char	*min_check(void);
static void	*parse_str(int n, int sign);

char	*ft_itoa(int n)
{
	int		sign;
	char	*str;

	sign = 1;
	if (n == -2147483648)
		return (min_check());
	if (n == 0)
	{
		str = malloc(2);
		if (!str)
			return (NULL);
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	if (n < 0)
	{
		sign = 2;
		n = n * -1;
	}
	return (parse_str(n, sign));
}

static void	*parse_str(int n, int sign)
{
	int		i;
	char	*str;

	i = 0;
	str = malloc((ft_intlen(n) + sign) * sizeof(char));
	if (!str)
		return (NULL);
	i = ft_intlen(n) + sign - 1;
	str[i--] = '\0';
	while (n != 0)
	{
		str[i--] = n % 10 + 48;
		n = n / 10;
	}
	if (sign == 2)
		str[i] = '-';
	return (str);
}

static int	ft_intlen(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static char	*min_check(void)
{
	char	*str;

	str = malloc(12 * sizeof(char));
	if (!str)
		return (NULL);
	ft_strlcpy(str, "-2147483648", 12);
	return (str);
}

// int	main(void)
// {
// 	int n = -0;
// 	printf("%d\n%s\n", n, ft_itoa(n));
// }