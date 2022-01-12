/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 20:52:28 by kmilchev          #+#    #+#             */
/*   Updated: 2021/12/07 20:52:28 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int	ft_min_num_0(int n, int fd)
{
	if (n == -2147483648)
		return (ft_putstr_fd("-2147483648", fd));
	else
		return (ft_putchar_fd('0', fd));
}

int	ft_putnbr_fd(int n, int fd)
{
	int		i;
	char	c[10];
	int		printed_chars;

	printed_chars = 0;
	if (fd < 0)
		return (0);
	if (n == 0 || n == -2147483648)
		return (ft_min_num_0(n, fd));
	if (n < 0)
	{
		printed_chars += ft_putchar_fd('-', fd);
		n = -n;
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
		printed_chars += ft_putchar_fd(c[i--], fd);
	return (printed_chars);
}
