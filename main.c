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
char *get_flags(char *command_args)
{
	while (*command_args != ' ')
		command_args++;
	return (++command_args);
}

char *get_command(char *command_args)
{
	char *command;
	int i;

	i = 0;
	while (command_args[i] != ' ')
		command[i] = command_args[i++];
	command[i] = '\0';
	return (command);
}
void	execute_first_command(char *argv[])
{
	char	*elements[4];
	char	*path_cmds;

	path_cmds = "/usr/bin/";
	elements[0] = ft_strjoin(path_cmds, argv[2]);
	elements[1] = argv[1];
	elements[2] = NULL;
	if (ft_strchr(argv[2], ' '))
		elements[2] = get_flags(argv[2]);
	elements[3] = NULL;
	execve(elements[0], elements, NULL);
}

void	execute_second_command(char *argv[])
{
	char	*elements[3];
	char	*path_cmds;

	path_cmds = "/usr/bin/";
	elements[0] = ft_strjoin(path_cmds, argv[3]);
	elements[1] = STDIN_FILENO;
	elements[2] = NULL;
	execve(elements[0], elements, NULL);
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

int	main(int argc, char *argv[])
{
	int	fd[2];
	int	pid1;
	int	pid2;
	int	fd_out;

	if (argc < 5)
		return (printf("Error! Too few arguments...\n"));
	pipe(fd);
	pid1 = fork();
	if (pid1 == 0)
	{
		dup2(fd[1], STDOUT_FILENO);
		close_desctiptors(2, fd[0], fd[1]);
		execute_first_command(argv);
	}
	pid2 = fork();
	fd_out = open(argv[4], O_WRONLY);
	if (pid2 == 0)
	{
		dup2(fd[0], STDIN_FILENO);
		dup2(fd_out, STDOUT_FILENO);
		close_desctiptors(3, fd[0], fd[1], fd_out);
		execute_second_command(argv);
	}
	close_desctiptors(3, fd[0], fd[1], fd_out);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (0);
}
