/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 10:42:14 by kmilchev          #+#    #+#             */
/*   Updated: 2021/11/27 10:42:14 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_positions(int n);
static void	ft_add_to_list(char *lst_chars, unsigned int number, int count);

char	*ft_itoa(int n)
{
	char			*chars;
	int				nbr_chars;
	int				sign;
	unsigned int	number;

	sign = 0;
	nbr_chars = ft_count_positions(n);
	chars = (char *)ft_calloc(nbr_chars + 1, sizeof(char));
	if (!(chars))
		return (NULL);
	chars[nbr_chars--] = '\0';
	number = n;
	if (n < 0)
	{
		sign = 1;
		number = n * -1;
	}
	ft_add_to_list(chars, number, nbr_chars);
	if (sign)
		chars[0] = '-';
	return (chars);
}

static int	ft_count_positions(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static void	ft_add_to_list(char *lst_chars, unsigned int number, int count)
{
	while (count >= 0)
	{
		lst_chars[count] = number % 10 + '0';
		number /= 10;
		count--;
	}
}
