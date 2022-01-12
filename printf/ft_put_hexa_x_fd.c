/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hexa_x_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 15:22:33 by kmilchev          #+#    #+#             */
/*   Updated: 2021/12/07 15:22:33 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_mapper(int num, char letter);

int	ft_put_hexa_x_fd(long long unsigned n, int fd, char letter)
{
	int		chars_printed;
	char	c[20];
	int		i;

	chars_printed = 0;
	if (letter == 'p')
	{
		if (n == 0)
			return (ft_putstr_fd("0x0", 1));
		chars_printed = ft_putstr_fd("0x", fd);
	}
	if (n == 0)
		return (ft_putnbr_fd(0, 1));
	i = 0;
	while (n > 0)
	{
		c[i] = ft_mapper(n % 16, letter);
		n = n / 16;
		i++;
	}
	i--;
	while (i >= 0)
		chars_printed += ft_putchar_fd(c[i--], fd);
	return (chars_printed);
}

int	ft_mapper(int num, char letter)
{
	if (10 <= num && num <= 15 && letter == 'X')
		return (num + 55);
	else if (10 <= num && num <= 15)
		return (num + 87);
	else
		return (num + '0');
}
