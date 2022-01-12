/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_unsigned_nbr_fd.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 20:51:29 by kmilchev          #+#    #+#             */
/*   Updated: 2021/12/07 20:51:29 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_put_unsigned_nbr_fd(unsigned int n, int fd)
{
	int		i;
	char	c[10];
	int		chars_printed;

	chars_printed = 0;
	if (n == 0)
	{
		return (ft_putchar_fd('0', fd));
	}
	i = 0;
	while (n > 0)
	{
		c[i] = n % 10 + '0';
		n = n / 10;
		i++;
	}
	i--;
	while (i >= 0)
		chars_printed += ft_putchar_fd(c[i--], fd);
	return (chars_printed);
}
