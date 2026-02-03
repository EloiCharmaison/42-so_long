/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echarmai <echarmai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 11:23:31 by echarmai          #+#    #+#             */
/*   Updated: 2025/11/17 14:40:08 by echarmai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	is_in_set(char c, const char *set);
static int	sizestr(const char *s1, const char *set);

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		size;
	char	*s2;

	if (!s1 && !set)
		return (NULL);
	size = sizestr(s1, set);
	s2 = malloc((size + 1) * sizeof(char));
	if (!s2)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] && is_in_set(s1[i], set))
		i++;
	while (j != size)
	{
		s2[j] = s1[i];
		i++;
		j++;
	}
	s2[j] = '\0';
	return (s2);
}

static int	sizestr(const char *s1, const char *set)
{
	int	size;
	int	start;
	int	end;

	size = ft_strlen(s1);
	start = 0;
	end = size - 1;
	while (start <= end && is_in_set(s1[start], set))
	{
		size--;
		start++;
	}
	while (end >= start && is_in_set(s1[end], set))
	{
		size--;
		end--;
	}
	return (size);
}

static int	is_in_set(const char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

// int main( ea)
// {
//   char *s1 = "_$%#test_$_";
//   char  *set = "_$#%";
//   printf("%s\n%s\n", s1, ft_strtrim(s1, set));
// }
