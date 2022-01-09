/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_addresses_after_fork.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 20:25:04 by kmilchev          #+#    #+#             */
/*   Updated: 2022/01/08 20:25:04 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main (void)
{
	int a = 5;
	int id;
	char *word;

	word = malloc(2);
	word[0] = 'K';
	word[1] = '\0';
	
	id = fork();
	if (id == 0)
	{
		a = 6;
		printf("%d\n", a);
		printf("%s\n", word);
		exit(-1);
		free(word);
	}
	else
	{
		printf("%d\n", a);
		printf("%s\n", word);
		// free(word);
	}
	free(word);
}