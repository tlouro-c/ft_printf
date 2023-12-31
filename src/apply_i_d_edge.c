/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlouro-c <tlouro-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:38:30 by tlouro-c          #+#    #+#             */
/*   Updated: 2023/12/12 19:17:41 by tlouro-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	quick_edge(int n, t_flags_i_d flags)
{
	return (flags.zero == TRUE && n < 0 
		&& flags.written_minus == FALSE && flags.precision_on == TRUE);
}
