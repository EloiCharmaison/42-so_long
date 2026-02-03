/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echarmai <echarmai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 14:07:47 by echarmai          #+#    #+#             */
/*   Updated: 2025/11/17 14:39:06 by echarmai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	sizestr(const char *s1, const char *s2);

char	*ft_strjoin(const char *s1, const char *s2)
{
	int		i;
	int		j;
	int		size;
	char	*s3;

	size = sizestr(s1, s2);
	s3 = malloc(size * sizeof(char));
	if (!s3)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		s3[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		s3[i] = s2[j];
		i++;
		j++;
	}
	s3[i] = '\0';
	return (s3);
}

static int	sizestr(const char *s1, const char *s2)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (s1[i] != '\0')
		i++;
	while (s2[j] != '\0')
		j++;
	return (i + j + 1);
}

// int main()
// {
//   char *s1 = "abcde";
//   char *s2 = "fghij";
//   printf("%s\n %s, %s\n", ft_strjoin(s1, s2), s1, s2);
// }
