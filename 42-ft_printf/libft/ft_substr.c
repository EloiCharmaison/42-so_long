/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echarmai <echarmai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 12:00:11 by echarmai          #+#    #+#             */
/*   Updated: 2025/11/17 17:32:35 by echarmai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	sizsub(const char *s, unsigned int start, size_t len);

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	int		size_sub;
	char	*sub;
	int		i;

	if (start >= ft_strlen(s))
		return (ft_calloc(1, 1));
	size_sub = sizsub(s, start, len);
	sub = malloc((size_sub + 1) * sizeof(char));
	if (!sub)
		return (NULL);
	i = 0;
	while (i < size_sub)
	{
		sub[i] = s[start];
		i++;
		start++;
	}
	sub[i] = '\0';
	return (sub);
}

static int	sizsub(const char *s, unsigned int start, size_t len)
{
	int		i;
	size_t	size_sub;

	i = start;
	size_sub = 0;
	while (s[i] != '\0' && size_sub < len)
	{
		size_sub++;
		i++;
	}
	return (size_sub);
}

// int main()
// {
//   const char *s = "abcdefghijkl";
//   unsigned int start = 189;
//   size_t len = 4;

//   printf("%s\n%s\n", ft_substr(s, start, len), s);
// }
