/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaghazar <vaghazar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 21:30:52 by vaghazar          #+#    #+#             */
/*   Updated: 2022/04/13 20:15:13 by vaghazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(long nb, int *count, char c)
{
	unsigned int	num;
	int				size;

	size = 1;
	if (c == 'u')
		nb = (unsigned int)nb;
	if (nb < 0)
	{
		ft_putchar('-', count);
		nb = -nb;
	}
	num = nb;
	while (num >= 10)
	{
		num = num / 10;
		size *= 10;
	}
	num = nb;
	while (size)
	{
		ft_putchar((num / size) + '0', count);
		num %= size;
		size /= 10;
	}
}
