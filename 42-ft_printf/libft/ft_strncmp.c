/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echarmai <echarmai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 11:07:12 by echarmai          #+#    #+#             */
/*   Updated: 2025/11/17 17:13:26 by echarmai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t				i;
	int					diff;
	const unsigned char	*ptr1;
	const unsigned char	*ptr2;

	ptr1 = (const unsigned char *)s1;
	ptr2 = (const unsigned char *)s2;
	i = 0;
	while (i < n && (ptr1[i] || ptr2[i]))
	{
		diff = ptr1[i] - ptr2[i];
		if (diff != 0)
			return (diff);
		i++;
	}
	return (0);
}

// int	main()
// {
// 	char *s1 = "€";
// 	char *s2 = "";
// }
