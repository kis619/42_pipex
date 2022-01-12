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
#include <fcntl.h>
// #include <process.h>

int main (void)
{
	int fd = open("../file2", O_WRONLY);
	int fd1 = open("random_test_file", O_RDONLY);
	char *arr[8] = {"/usr/bin/awk", "print $1", NULL};
	dup2(fd, 1);
	dup2(fd1, 0);
	close(fd);
	close(fd1);
	execve("/usr/bin/awk", arr, NULL);

	return (0);
}