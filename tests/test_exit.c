/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 17:29:50 by kmilchev          #+#    #+#             */
/*   Updated: 2022/01/11 17:29:50 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int main(void)
{	
	char *word;

	word = malloc(3);
	word[0] = 'a';
	word[1] = 'b';
	word[2] = '\0';
	#include <stdio.h>
	
	printf("%s\n", word);
	free(word);
	exit(8);
}