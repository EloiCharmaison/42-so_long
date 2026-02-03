/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echarmai <echarmai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 18:10:55 by echarmai          #+#    #+#             */
/*   Updated: 2025/11/17 16:06:59 by echarmai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*ptr1;
	const unsigned char	*ptr2;

	ptr1 = (const unsigned char *)s1;
	ptr2 = (const unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (i < n && ptr1[i] == ptr2[i])
		i++;
	if (i == n)
		return (ptr1[i - 1] - ptr2[i - 1]);
	else
		return (ptr1[i] - ptr2[i]);
}

// #include <stdio.h>
// int main()
// {
// 	char *s1 = "aan";
// 	char *s2 = "aaa";
// 	printf("%d\n", ft_memcmp(s1, s2, 2));
// }