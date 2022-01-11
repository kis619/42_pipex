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
#include <errno.h>

// errno: some number
//#include <string.h>?

static char	**ft_free(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
	return (NULL);
}

void	execute_command(char *argv)
{
	char *cmd;
	char **cmd_flags;

	cmd_flags = ft_split(argv, ' ');

	cmd = ft_strjoin("/usr/bin/", cmd_flags[0]);
	execve(cmd, cmd_flags, NULL);
	perror(cmd_flags[0]);
	ft_free(cmd_flags);
	free(cmd);
	exit(1);
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

void ft_validity_check(int n, char *error_message)
{
	if (n == -1)
	{
		perror(error_message);
		exit(errno);
	}
}

void ft_pipe_fork(int n, char *error_message)
{
	if (n == -1)
	{
		perror(error_message);
		exit(errno);
	}
	
}
void check_number_of_arguments(int n)
{
	if (n < 5)
	{
		printf("Error! Too few arguments...\n");
		exit(1);
	}
}

void spawn_process(char *argv[])
{
	int pid;
	int fd[2];

	ft_pipe_fork(pipe(fd), "Piping error");
	pid = fork();
	ft_validity_check(pid, "Forking error");
	if (pid == 0)
	{
		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		execute_command(argv[0]);
	}

	dup2(fd[0], STDIN_FILENO);
	close(fd[1]);
	waitpid(pid, NULL, 0);
}

int	main(int argc, char *argv[])
{
	int fd_input;
	int	fd_out;
	int counter;

	check_number_of_arguments(argc);
	fd_input = open(argv[1], O_RDONLY);
	ft_validity_check(fd_input, argv[1]);
	fd_out = open(argv[argc - 1], O_CREAT | O_WRONLY | O_TRUNC, S_IWUSR);
	ft_validity_check(fd_input, argv[1]);
	dup2(fd_input, STDIN_FILENO);
	dup2(fd_out, STDOUT_FILENO);	// close_desctiptors(2, fd_out, fd_input);  //Warning: invalid file descriptor -1 in syscall close()
	counter = 2;
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

