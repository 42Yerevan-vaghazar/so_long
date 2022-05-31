/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaghazar <vaghazar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 13:44:00 by vaghazar          #+#    #+#             */
/*   Updated: 2022/04/13 20:14:46 by vaghazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

char	*ft_check_base(char c, unsigned long *nbr, unsigned long *num);
void	ft_printf_type(const char *from, int *tmp, int *count, va_list ap);
int		ft_printf(const char *from, ...);
void	ft_putchar(char c, int *count);
void	ft_putnbr_base(unsigned long nbr, int *count, char c);
void	ft_putnbr(long nb, int *count, char c);
int		ft_putstr(char *str, int *count);

#endif
