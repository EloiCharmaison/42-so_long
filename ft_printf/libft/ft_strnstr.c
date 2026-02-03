/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echarmai <echarmai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 11:43:50 by echarmai          #+#    #+#             */
/*   Updated: 2025/11/17 14:39:52 by echarmai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (*little == '\0')
		return ((char *)big);
	while (big[i] != '\0' && i < len)
	{
		j = 0;
		if (big[i] == little[j])
		{
			while (big[i + j] == little[j] && (i + j) < len)
			{
				if (j == ft_strlen(little) - 1)
					return ((char *)(big + i));
				j++;
			}
		}
		i++;
	}
	return (NULL);
}

// int	main(void)
// {
// 	char	*big = "abcdefghijkl";
// 	char	*little = "ab";
// 	size_t	len = 99;

// 	printf("%s\n%s\n", ft_strnstr(big, little, len), strnstr(big, little, len));
// }
