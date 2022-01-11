/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 11:10:44 by kmilchev          #+#    #+#             */
/*   Updated: 2022/01/10 11:10:44 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft/libft.h"
#include <fcntl.h>
#include <sys/wait.h>
#include <stdarg.h>
//#include <error.h>?
// errno: some number
//#include <string.h>?

void	print_strings_array(int count, char **args)
{
	int	i;

	i = 0;
	while (i < count)
	{
		printf("Argument number %d: %s\n", i, args[i]);
		i++;
	}
}


void	execute_command(char *argv)
{
	char *cmd;
	char **cmd_flags;

	cmd_flags = ft_split(argv, ' ');

	cmd = ft_strjoin("/usr/bin/", cmd_flags[0]);
	execve(cmd, cmd_flags, NULL);
}

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

void spawn_process(char *argv[])
{
	int pid;
	int fd[2];

	pipe(fd);
	printf("%s\n", argv[0]);
	pid = fork();
	if (pid == 0)
	{
		dup2(fd[1], STDOUT_FILENO);
		close_desctiptors(2, fd[0], fd[1]);
		execute_command(argv[0]);
	}

	dup2(fd[0], STDIN_FILENO);
	close_desctiptors(2, fd[0], fd[1]);
	waitpid(pid, NULL, 0);
}
int	main(int argc, char *argv[])
{
	int	fd[2];
	int fd_input;
	int	fd_out;

	fd_input = open(argv[1], O_RDONLY);
	fd_out = open(argv[argc - 1], O_WRONLY);
	dup2(fd_input, STDIN_FILENO);
	dup2(fd_out, STDOUT_FILENO);
	close_desctiptors(2, fd_out, fd_input);
	pipe(fd);
	int counter = 2;
	while (counter < argc - 2)
	{
		spawn_process(argv + counter);
		counter++;
	}
	execute_command(argv[argc - 2]);
	return (0);
}

/* 
	if (argc < 5)
		return (printf("Error! Too few arguments...\n")); */

