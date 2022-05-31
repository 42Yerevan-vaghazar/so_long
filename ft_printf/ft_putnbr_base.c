/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaghazar <vaghazar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 17:25:02 by vaghazar          #+#    #+#             */
/*   Updated: 2022/04/13 20:15:10 by vaghazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_base(unsigned long nbr, int *count, char c)
{
	unsigned long	num;
	int				call[50];
	int				base_len;
	int				i;
	char			*base;

	num = nbr;
	base_len = 16;
	i = 0;
	base = ft_check_base(c, &nbr, &num);
	while (num)
	{
		call[i] = num % base_len;
		num = num / base_len;
		i++;
	}
	while (--i >= 0)
		ft_putchar(base[call[i]], count);
	if (nbr == 0)
		ft_putchar('0', count);
}
