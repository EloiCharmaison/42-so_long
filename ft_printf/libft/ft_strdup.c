/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echarmai <echarmai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 11:02:25 by echarmai          #+#    #+#             */
/*   Updated: 2025/11/17 16:43:51 by echarmai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*s2;
	int		i;

	s2 = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!s2)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		s2[i] = s[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

// int main()
// {
//   const char  *s = "abcdef";
//   printf("%s\n%s\n%s", s, ft_strdup(s), strdup(s));
// }
