/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echarmai <echarmai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 17:40:15 by echarmai          #+#    #+#             */
/*   Updated: 2025/11/12 16:55:29 by echarmai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*alloc;
	size_t			i;

	alloc = malloc(nmemb * size);
	if (!alloc)
		return (NULL);
	i = 0;
	if (size != 0 && nmemb > (size_t)-1 / size)
	{
		return (NULL);
	}
	while (i < nmemb * size)
	{
		alloc[i] = 0;
		i++;
	}
	return ((void *)alloc);
}
//
// int main()
// {
//   int *tab = ft_calloc(10, sizeof(int));
//   int i = 0;
//   while (i < 10)
//   {
//     printf("%d\n", tab[i]);
//     i++;
//   }
// }
