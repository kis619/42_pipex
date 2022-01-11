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

char	*get_input_file(char **arguments)
{
	char	*input_file;

	input_file = arguments[1];
	return (input_file);
}

char	*get_output_file(int argc, char **arguments)
{
	char	*output_file;

	output_file = arguments[argc - 1];
	return (output_file);
}

char	**get_commands(int argc, char *argv[])
{
	char	**arr;
	int		i;
	int		j;

	i = 0;
	j = 2;
	arr = malloc((argc - 2) * sizeof(char *)); //-2 че да добавя NULL at the end
	while (j < argc - 1)
	{
		arr[i++] = argv[j++];
	}
	arr[i] = NULL;
	return (arr);
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
void process_1(int fd_input, int *fd, char *argv[2])
{
	dup2(fd_input, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close_desctiptors(3, fd[0], fd[1], fd_input);
	execute_command(argv[2]);
}
int	main(int argc, char *argv[])
{
	int	fd[2];
	int	pid1;
	int	pid2;
	int fd_input;
	int	fd_out;

	if (argc < 5)
		return (printf("Error! Too few arguments...\n"));
	pipe(fd);
	pid1 = fork();
	fd_input = open(argv[1], O_RDONLY);
	if (pid1 == 0)
		process_1(fd_input, fd, argv);
	pid2 = fork();
	fd_out = open(argv[4], O_WRONLY);
	if (pid2 == 0)
	{
		dup2(fd[0], STDIN_FILENO);
		dup2(fd_out, STDOUT_FILENO);
		close_desctiptors(3, fd[0], fd[1], fd_out);
		execute_command(argv[argc - 2]);
	}
	close_desctiptors(3, fd[0], fd[1], fd_out);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (0);
}
