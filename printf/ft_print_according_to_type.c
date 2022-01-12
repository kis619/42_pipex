/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_according_to_type.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 20:50:02 by kmilchev          #+#    #+#             */
/*   Updated: 2021/12/07 20:50:02 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_print_according_to_type(char letter, va_list args)
{
	if (letter == 's')
		return (ft_putstr_fd(va_arg(args, char *), 1));
	else if (letter == 'c')
		return (ft_putchar_fd(va_arg(args, int), 1));
	else if (letter == 'i' || letter == 'd')
		return (ft_putnbr_fd(va_arg(args, int), 1));
	else if (letter == 'u')
		return (ft_put_unsigned_nbr_fd(va_arg(args, unsigned int), 1));
	else if (letter == 'x' || letter == 'X')
		return (ft_put_hexa_x_fd(va_arg(args, long long unsigned), 1, letter));
	else if (letter == 'p')
		return (ft_put_hexa_x_fd(va_arg(args, long long unsigned), 1, letter));
	else if (letter == '%')
		return (ft_putchar_fd('%', 1));
	return (0);
}
