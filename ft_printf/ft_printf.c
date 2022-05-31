/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaghazar <vaghazar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 13:27:59 by vaghazar          #+#    #+#             */
/*   Updated: 2022/04/13 20:15:02 by vaghazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *from, ...)
{
	va_list	ap;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(ap, from);
	while (from[i] != 0)
	{
		if (from[i] == '%' && ++i)
			ft_printf_type(from, &i, &count, ap);
		if (from[i] != 0 && from[i] != '%')
			ft_putchar(from[i++], &count);
	}
	va_end(ap);
	return (count);
}
