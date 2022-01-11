/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_variatic.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 10:46:45 by kmilchev          #+#    #+#             */
/*   Updated: 2022/01/10 10:46:45 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
int close_desctiptors(int n_fds, ...)
{
	int number = 0;
	va_list fds;
	va_start (fds, n_fds);
	int i;
	i = 0;
	while (i < n_fds)
	{
		// close(va_arg(fds, int));
		// printf("%d\n", va_arg(fds, int));
		number += va_arg(fds, int);
		i++;
	}
	return number;
}

int main(void)
{
	
	printf("%d\n", close_desctiptors(3, 1, 2, 3));
	return (0);
}