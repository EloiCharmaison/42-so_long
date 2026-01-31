/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echarmai <echarmai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 12:51:23 by echarmai          #+#    #+#             */
/*   Updated: 2025/11/17 13:21:18 by echarmai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int	size_tab(const char *s, char c);
static int	size_str(const char *s, char c);
static void	*alloc_error(int i, char **tab);
static int	fill_tab(char ***tab, const char *s, char c);

char	**ft_split(const char *s, char c)
{
	char	**tab;

	if (!s)
		return (NULL);
	tab = malloc((size_tab(s, c) + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	if (!fill_tab(&tab, s, c))
		return (NULL);
	return (tab);
}

static int	fill_tab(char ***tab, const char *s, char c)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
		{
			(*tab)[j] = malloc((size_str(s + i, c) + 1) * sizeof(char));
			if (!(*tab)[j])
				return (alloc_error(j - 1, *tab), 0);
			k = 0;
			while (s[i] && s[i] != c)
				(*tab)[j][k++] = s[i++];
			(*tab)[j++][k] = '\0';
		}
	}
	(*tab)[j] = NULL;
	return (1);
}

static void	*alloc_error(int i, char **tab)
{
	while (i >= 0)
	{
		free(tab[i]);
		i--;
	}
	free(tab);
	return (NULL);
}

static int	size_tab(const char *s, char c)
{
	int	i;
	int	size_tab;

	i = 0;
	size_tab = 0;
	while (s[i] != '\0')
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
		{
			size_tab++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (size_tab);
}

static int	size_str(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != '\0' && s[i] != c)
		i++;
	return (i);
}

// int	main(void)
// {
// 	char	*s;
// 	char	c;
// 	char	**tab1;
// 	int		i;

// 	s = "t1\0t2\0t3\0";
// 	c = '\0';
// 	tab1 = ft_split(s, c);
// 	i = 0;
// 	while (tab1[i])
// 	{
// 		printf("%s\n", tab1[i]);
// 		i++;
// 	}
// }
