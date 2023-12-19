/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils4.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlouro-c <tlouro-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:34:07 by tlouro-c          #+#    #+#             */
/*   Updated: 2023/12/12 17:30:04 by tlouro-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	if (s == NULL)
		return (len);
	while (s[len] != '\0')
		len++;
	return (len);
}

char	*ft_strdup(const char *s1)
{
	char	*s2;
	int		i;

	i = 0;
	while (s1[i] != '\0')
		i++;
	s2 = malloc((i + 1) * sizeof(char));
	if (s2 == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

int	ft_abs(int n)
{
	if (n < 0)
		return (n * -1);
	return (n);
}

int	ft_putchar_fd(int c, int fd)
{
	return (write(fd, &c, 1));
}

int	number_len_u(unsigned int number)
{
	int	number_len;

	number_len = number == 0;
	while (number > 0)
	{
		number = number / 10;
		number_len++;
	}
	return (number_len);
}
