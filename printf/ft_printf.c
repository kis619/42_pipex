/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 20:50:16 by kmilchev          #+#    #+#             */
/*   Updated: 2021/12/07 20:50:16 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_printf(const char *str, ...)
{
	int		i;
	int		chars_printed;
	va_list	args;

	chars_printed = 0;
	i = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] != '%')
			chars_printed += ft_putchar_fd(str[i], 1);
		else
		{
			chars_printed += ft_print_according_to_type(str[i + 1], args);
			i++;
		}
		i++;
	}
	return (chars_printed);
}
