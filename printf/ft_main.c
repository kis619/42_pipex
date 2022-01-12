/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 20:54:30 by kmilchev          #+#    #+#             */
/*   Updated: 2021/12/07 20:54:30 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int main (void)
{
	int actual;
	int expected;
	int i;

	i = 1;
	actual = expected = 0;
	//1
	actual =  ft_printf("Test1");
	expected = printf("Test1");
	ft_test(expected, actual, i++);

	//2
	actual = ft_printf("Char%dacter\n", 7);
	expected = printf("Char%dacter\n", 7);
	ft_test(expected, actual, i++);

	//3
	actual =  ft_printf(" ");
	expected = printf(" ");
	ft_test(expected, actual, i++);

	//4
	actual = ft_printf("Number %d, char %d\n", -5000, 7);
	expected = printf("Number %d, char %d", -5000, 7) + 1;
	ft_test(expected, actual, i++);

	//5
	actual = ft_printf("Number %d, str %s\n", -5000, "life");
	expected = printf("Number %d, str %s", -5000, "life");
	ft_test(expected + 1, actual, i++);

	//6
	actual = ft_printf("Number %d, str %s, char%c \n", -5000, "life", 'K');
	expected = printf("Number %d, str %s, char%c ", -5000, "life", 'K');
	ft_test(expected + 1, actual, i++);

	//7
	actual = ft_printf("%s\n", "duma");
	expected = printf("%s", "duma");
	ft_test(expected + 1, actual, i++);

	//8
	actual = ft_printf("%d\n", 'a');
	expected = printf("%d", 'a');
	ft_test(expected + 1, actual, i++);
	
	//9
	actual = ft_printf("%u\n", -2);
	expected = printf("%u",    -2);
	ft_test(expected + 1, actual, i++);

	//10
	actual = ft_printf("%d\n", 0xff);
	expected = printf("%d", 0xff);
	ft_test(expected + 1, actual, i++);

	//11
	actual = ft_printf("%x\n", 0xff);
	expected = printf("%x", 0xff);
	ft_test(expected + 1, actual, i++);

	//12
	actual = ft_printf("%X\n", 0xff);
	expected = printf("%X", 0xff);
	ft_test(expected + 1, actual, i++);

	//13
	int a;
	a = 7;
	actual = ft_printf("%p\n", &a);
	expected = printf("%p", &a);
	ft_test(expected + 1, actual, i++);

	//14
	actual = ft_printf("%%p\n");
	expected = printf("%%p");
	ft_test(expected + 1, actual, i++);

	//15
	char *x = NULL;
	actual = ft_printf("%s\n", x);
	expected = printf("%s", x);
	ft_test(expected + 1, actual, i++);

	//16
	actual = ft_printf("%p\n", (void *)0);
	expected = printf("%p", (void *)0);
	ft_test(expected + 1, actual, i++);

	//17
	actual = ft_printf("%x\n", 1);
	expected = printf("%x", 1);
	ft_test(expected + 1, actual, i++);

	
	return (0);

}
