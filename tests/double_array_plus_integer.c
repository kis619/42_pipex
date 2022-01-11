/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_array_plus_integer.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 12:50:21 by kmilchev          #+#    #+#             */
/*   Updated: 2022/01/11 12:50:21 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
void	print_strings_array(int count, char **args)
{
	int	i;

	i = 1;
	while (i < count)
	{
		printf("Argument number %d: %s\n", i, args[i]);
		i++;
	}
}

int main (int argc, char *argv[])
{


	print_strings_array(6, argv);
	printf("\n");
	print_strings_array(5, argv + 1);
	// printf("%s\n", (argv)[0]);
	// printf("%s\n", (argv + 1)[0]);
	// printf("%s\n", (argv)[1]);
	// printf("%s\n", (argv + 2)[0]);
	// printf("%s\n", (argv)[2]);
	// printf("%s\n", (argv + 3)[0]);
	// printf("%s\n", (argv)[3]);
	
	
	return (0);
}