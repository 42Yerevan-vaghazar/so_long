/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaghazar <vaghazar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 19:56:58 by vaghazar          #+#    #+#             */
/*   Updated: 2022/04/13 20:14:58 by vaghazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_type(const char *from, int *tmp, int *count, va_list ap)
{
	int	i;

	i = *tmp;
	if (from[i] == 'c' && ++i)
		ft_putchar(va_arg(ap, int), count);
	else if (from[i] == 's' && ++i)
		ft_putstr(va_arg(ap, char *), count);
	else if ((from[i] == 'p' && ft_putstr("0x", count))
		|| from[i] == 'x' || from[i] == 'X')
		ft_putnbr_base(va_arg(ap, unsigned long), count, from[i++]);
	else if ((from[i] == 'd' || from[i] == 'i' || from[i] == 'u'))
		ft_putnbr(va_arg(ap, int), count, from[i++]);
	else if (from[i] == '%')
		ft_putchar(from[i++], count);
	*tmp = i;
}
