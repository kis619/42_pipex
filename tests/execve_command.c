/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 20:57:52 by kmilchev          #+#    #+#             */
/*   Updated: 2022/01/08 20:57:52 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #include <process.h>

int main (void)
{
	char *arr[8];

	arr[0] = "/usr/bin/wc -l";
	arr[1] = "../file1";
	arr[2] = "wc";
	arr[3] = "echo";
	arr[4] = "ls";
	arr[5] = "../file2";
	arr[6] = "../file2";
	arr[7] = NULL;
	execve(arr[0], arr, NULL);
	return (0);
}