/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echarmai <echarmai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 11:28:51 by echarmai          #+#    #+#             */
/*   Updated: 2025/11/21 14:11:45 by echarmai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

int	ft_print_chr(char c);
int	ft_print_unsigned(unsigned int n);
int	ft_print_str(char *str);
int	ft_print_hex(unsigned int n);
int	ft_print_hexmaj(unsigned int n);
int	ft_print_nbr(int n);
int	ft_print_ptr(void *ptr);
int	ft_printf(const char *str, ...);

#endif