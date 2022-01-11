/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   while_to_execute_many_processes.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 12:22:03 by kmilchev          #+#    #+#             */
/*   Updated: 2022/01/11 12:22:03 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <fcntl.h>

void	close_desctiptors(int n_fds, ...)
{
	va_list	fds;
	int		i;

	va_start(fds, n_fds);
	i = 0;
	while (i < n_fds)
	{
		close(va_arg(fds, int));
		i++;
	}
}

void	create_process(int argc, char *argv[])
{
	int	pid;

	pid = fork();
	if (pid == 0)
	{
		printf("%d\n", fd[0]);
		printf("%d\n", fd[1]);
	}
}

int	main(int argc, char *argv[])
{
	int fd_input_file;
	int fd_output_file;

	fd_input_file = open(argv[1], O_RDONLY);
	fd_output_file = open(argv[argc - 1], O_WRONLY);
	dup2(fd_input_file, STDIN_FILENO);
	dup2(fd_output_file, STDOUT_FILENO);
	close_desctiptors(2, fd_input_file, fd_output_file);

	create_process(argc, argv);
}
