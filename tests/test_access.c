/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_access.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 16:37:43 by kmilchev          #+#    #+#             */
/*   Updated: 2022/01/11 16:37:43 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

int main(void)
{
	#include <stdio.h>
	// printf("%d\n", access("text_access.txt", R_OK));
	printf("Checking access for W on a r-only file: %d\n", access("random_test_file", W_OK));

	int i;
	int j;
	i = open("random_test_file", O_WRONLY);
	j = open("random_test_file", O_RDONLY);
	printf("%d\n", i);
	printf("%d\n", j);
	return (0);
}