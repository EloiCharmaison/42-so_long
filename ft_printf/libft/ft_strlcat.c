/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echarmai <echarmai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 16:27:08 by echarmai          #+#    #+#             */
/*   Updated: 2025/11/17 14:39:14 by echarmai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t siz)
{
	size_t	i;
	size_t	j;
	size_t	dst_len;
	size_t	src_len;

	dst_len = 0;
	while (dst_len < siz && dst[dst_len])
		dst_len++;
	src_len = ft_strlen(src);
	if (dst_len == siz)
		return (siz + src_len);
	i = dst_len;
	j = 0;
	while (src[j] && i < siz - 1)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	if (i < siz)
		dst[i] = '\0';
	return (dst_len + src_len);
}
