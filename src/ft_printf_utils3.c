/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlouro-c <tlouro-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 21:51:15 by tlouro-c          #+#    #+#             */
/*   Updated: 2023/12/12 19:20:58 by tlouro-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	invalid_specifier_or_special(char specifier, va_list *args)
{
	if (specifier == '%')
		return (write(1, "%", 1));
	va_end(*args);
	ft_putstr_fd("Error: Invalid conversion specifier '", 2);
	ft_putchar_fd(specifier, 2);
	ft_putstr_fd("'\n", 2);
	exit(3);
}

int	ft_atoi(const char *s)
{
	int	n;
	int	i;
	int	negative;

	n = 0;
	i = 0;
	while (ft_isspace(s[i]))
		i++;
	negative = s[i] == '-';
	if (s[i] == '-' || s[i] == '+')
		i++;
	while (s[i] != '\0' && ft_isdigit(s[i]))
		n = n * 10 + (s[i++] - '0');
	if (negative)
		return (n * -1);
	return (n);
}

int	ft_isspace(int c)
{
	return (c == ' ' || c == '\n' || c == '\t'
		|| c == '\v' || c == '\f' || c == '\r');
}

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	ft_putstr_fd(char *s, int fd)
{
	return (write(fd, s, ft_strlen(s)));
}
