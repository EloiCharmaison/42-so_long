/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eloi <eloi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 11:13:06 by echarmai          #+#    #+#             */
/*   Updated: 2025/11/13 11:25:15 by eloi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

void	*ft_memset(void *s, int value, size_t count)
{
	size_t	i;
	char	c;

	c = (int)value;
	i = 0;
	while (i < count)
	{
		((unsigned char *)s)[i] = c;
		i++;
	}
	return (s);
}
