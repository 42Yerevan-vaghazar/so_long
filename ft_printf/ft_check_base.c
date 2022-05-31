/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaghazar <vaghazar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 19:55:24 by vaghazar          #+#    #+#             */
/*   Updated: 2022/05/23 15:49:16 by vaghazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_check_base(char c, unsigned long *nbr, unsigned long *num)
{
	if (c == 'x' || c == 'X')
	{
		*nbr = ((unsigned int)*nbr);
		*num = ((unsigned int)*num);
	}
	if (c == 'x')
		return ("0123456789abcdef");
	if (c == 'X')
		return ("0123456789ABCDEF");
	if (c == 'p')
		return ("0123456789abcdef");
	return (0);
}
