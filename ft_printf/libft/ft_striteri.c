/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echarmai <echarmai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 14:14:33 by echarmai          #+#    #+#             */
/*   Updated: 2025/11/17 16:44:31 by echarmai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	if (!s || !f)
		return ;
	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
	s[i] = '\0';
}

// void	f(unsigned int i, char *s)
// {
// 	*s = *s + i;
// }

// int	main()
// {
// 	char	s[] = "abcd";
// 	ft_striteri(s, f);
// 	printf("abcd\n%s\n", s);
// }