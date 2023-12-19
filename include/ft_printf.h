/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlouro-c <tlouro-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:04:51 by tlouro-c          #+#    #+#             */
/*   Updated: 2023/12/12 19:39:16 by tlouro-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdarg.h>
# include <stdio.h>
# include <math.h>

# define FALSE 0
# define TRUE 1

typedef int	t_bool;

/* -------------------------------------------------------------------------- */
/*                            FT_PRINTF_STRUCTURES                            */
/* -------------------------------------------------------------------------- */

typedef struct s_inc
{
	size_t	i;
	size_t	written;
}	t_inc;

typedef struct s_flags_c_p
{
	int		width;
	t_bool	hifen;
	t_bool	zero;
}	t_flags_c_p;

typedef struct s_flags_s
{
	int		width;
	int		precision;
	t_bool	precision_on;
	t_bool	hifen;
	t_bool	zero;
}	t_flags_s;

typedef struct s_flags_x
{
	int		width;
	int		precision;
	t_bool	precision_on;
	t_bool	hifen;
	t_bool	zero;
	t_bool	hash;
	t_bool	upper_case;
}	t_flags_x;

typedef struct s_flags_i_d
{
	int		width;
	int		precision;
	t_bool	precision_on;
	t_bool	hifen;
	t_bool	zero;
	t_bool	plus;
	t_bool	space;
	t_bool	written_minus;
}	t_flags_i_d;

typedef struct s_flags_u
{
	int		width;
	int		precision;
	t_bool	precision_on;
	t_bool	hifen;
	t_bool	zero;
}	t_flags_u;

//*PRINTF
int				ft_printf(const char *format, ...);
void			action(const char *format, va_list *args, t_inc *incrementors);
char			find_specifier(const char *format, t_inc *incrementors);
t_bool			isflag(char c);
int				apply_c(const char *format, va_list *args, int pos);
int				apply_s(const char *format, va_list *args, int pos);
int				apply_p(const char *format, va_list *args, int pos);
int				apply_x(const char *format, va_list *args, int pos,
					char specifier);
int				apply_i_d(const char *format, va_list *args, int pos);
int				apply_u(const char *format, va_list *args, int pos);
int				write_c_x_times(char c, int x);
void			alloc_error_exit(int error_value, va_list *args);
int				number_len(int number);
int				number_len_u(unsigned int number);
int				hexa_len(unsigned long n, int base_size, char *base);
int				ft_putnbr_bases(unsigned long n, int base_size, char *base);
int				invalid_specifier_or_special(char specifier, va_list *args);
int				ft_atoi(const char *s);
int				ft_isspace(int c);
int				ft_isdigit(int c);
int				ft_putstr_fd(char *s, int fd);
size_t			ft_strlen(const char *s);
char			*ft_strdup(const char *s1);
int				ft_abs(int n);
int				ft_putchar_fd(int c, int fd);
void			putnbr_d_i(long n);
int				ft_strcmp(char *s1, char *s2);
int				quick_edge(int n, t_flags_i_d flags);

//* END OF PRINTF

#endif /* FT_PRINTF_H */
