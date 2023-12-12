/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_i_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlouro-c <tlouro-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 13:56:21 by tlouro-c          #+#    #+#             */
/*   Updated: 2023/12/12 15:29:39 by tlouro-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	write_i_d(t_flags_i_d flags, int n);
static void	initialize_flags(t_flags_i_d *flags);
static int	write_number(int n, t_flags_i_d flags, int track_flag_usage);
static void	putnbr_d_i(long n);

int	apply_i_d(const char *format, va_list *args, int pos)
{
	t_flags_i_d	flags;

	initialize_flags(&flags);
	while (format[pos] != '\0' && isflag(format[pos]))
	{
		if (format[pos] == '-')
			flags.hifen = true;
		if (format[pos] == '0')
			flags.zero = true;
		if (format[pos] == '+')
			flags.plus = true;
		if (format[pos] == ' ')
			flags.space = true;
		pos++;
	}
	flags.width = ft_atoi(&format[pos]);
	while (format[pos] != '\0' && ft_isdigit(format[pos]))
		pos++;
	if (format[pos] == '.')
	{
		flags.precision_on = true;
		flags.precision = ft_atoi(&format[++pos]);
	}
	return (write_i_d(flags, va_arg(*args, int)));
}

static int	write_i_d(t_flags_i_d flags, int n)
{
	int		written;
	int		track_flag_usage;

	written = 0;
	track_flag_usage = 0;
	if (flags.plus || flags.space)
		track_flag_usage += 1;
	if (flags.precision > number_len(n))
		track_flag_usage += flags.precision;
	else
		track_flag_usage += number_len(n);
	if (flags.plus && n >= 0)
		written += write(1, "+", 1);
	else if (flags.space && n >= 0)
		written += write(1, " ", 1);
	written += write_number(n, flags, track_flag_usage);
	return (written);
}

static int	write_number(int n, t_flags_i_d flags, int track_flag_usage)
{
	int	written;
	int	zeros;

	written = 0;
	zeros = flags.precision - number_len(n);
	if (flags.hifen)
	{
		if (flags.precision && zeros > 0)
			written += write_c_x_times('0', zeros);
		putnbr_d_i((long)n);
		written += number_len(n);
		written += write_c_x_times(' ', flags.width - written);
	}
	else
	{
		if (flags.zero == true && flags.precision_on == false)
			written += write_c_x_times('0', flags.width - track_flag_usage);
		else
			written += write_c_x_times(' ', flags.width - track_flag_usage);
		if (flags.precision && zeros > 0)
			written += write_c_x_times('0', zeros);
		putnbr_d_i((long)n);
		written += number_len(n);
	}
	return (written);
}

static void	initialize_flags(t_flags_i_d *flags)
{
	flags -> width = 0;
	flags -> precision_on = false;
	flags -> precision = 0;
	flags -> hifen = false;
	flags -> zero = false;
	flags -> plus = false;
	flags -> space = false;
}

static void	putnbr_d_i(long n)
{
	char	toprint;

	if (n < 0)
	{
		write(1, "-", 1);
		n = n * -1;
	}
	if (n >= 10)
		putnbr_d_i(n / 10);
	toprint = (n % 10) + 48;
	write(1, &toprint, 1);
}
