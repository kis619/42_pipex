/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 20:49:02 by kmilchev          #+#    #+#             */
/*   Updated: 2021/12/07 20:49:02 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_test(int expected, int actual, int index)
{
	if (actual == expected)
		printf("\nGood job!\n");
	else
	{	
		printf("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
		printf("\nExpected = %d\nActual = %d\n", expected, actual);
	}
	printf("End of Test %d\n", index);
	printf("-------------------------------\n");
}
