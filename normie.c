/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normie.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 15:06:51 by kmilchev          #+#    #+#             */
/*   Updated: 2022/01/09 15:06:51 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
char	**get_commands(int argc, char *argv[])
{
	char	**arr;
	int i;
	int j;

	i = 0;
	j = 2;
	arr = malloc((argc - 2) * sizeof(char *)); //-2 че да добавя NULL at the end
	while (j < argc)
	{
		arr[i++] = argv[j++];
	}
	arr[i] = NULL;
	return (arr);
}

void print_array(int argc, char *array[])
{

	int i = 0;
	while (array[i] != NULL)
	{
		printf("%s\n", array[i]);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	char **test;
	
	test = malloc(argc - 2 * sizeof(char *));
	test = get_commands(argc, argv);
	print_array(argc, test);
	return (0);
}
