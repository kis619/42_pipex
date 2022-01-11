/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_piping.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 19:24:15 by kmilchev          #+#    #+#             */
/*   Updated: 2022/01/09 19:24:15 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/wait.h>

int main (int argc, char *argv[])
{
	int fd[2];
	char *elements[3];
	pipe(fd);

	int pid1 = fork();


	if (pid1 == 0)
	{
		// dup2(fd[0], file);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		close(fd[1]);
		
		
		elements[0] = "/usr/bin/cat";
		elements[1] = argv[1];
		elements[2] = NULL;
		execve("/usr/bin/cat", elements, NULL);
	}
	int fd_out;

	fd_out = open("out_file", O_WRONLY);

	int pid2 = fork();
	if (pid2 == 0)
	{
		dup2(fd[0], STDIN_FILENO);
		dup2(fd_out, STDOUT_FILENO);
		close(fd[0]);
		close(fd[1]);
		char *elements[4];
		elements[0] = "/usr/bin/grep";
		elements[1] = STDIN_FILENO;
		elements[1] = "газ";
		elements[2] = NULL;
		execve(elements[0], elements, NULL);
		// execlp("grep", "grep", "тряс", NULL);
	}
	close(fd[0]);
	close(fd[1]);

	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (0);
}