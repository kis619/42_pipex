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

#include "pipex.h"

void	execute_command(char *argv, char **possible_paths, char **envp)
{
	char	*cmd;
	char	**cmd_flags;
	int		idx;

	idx = 0;
	cmd_flags = ft_split(argv, ' ');
	while (possible_paths[idx] != NULL)
	{
		cmd = ft_strjoin(possible_paths[idx], cmd_flags[0]);
		execve(cmd, cmd_flags, envp);
		free(cmd);
		idx++;
	}
	ft_free(possible_paths);
	perror(cmd_flags[0]);
	ft_free(cmd_flags);
	exit(1);
}

void	spawn_process(char *argv[], char **possible_paths, char *envp[])
{
	pid_t	pid;
	int		fd[2];

	ft_validity_check(pipe(fd), "Piping error");
	pid = fork();
	ft_validity_check(pid, "Forking error");
	if (pid == 0)
	{
		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		execute_command(argv[0], possible_paths, envp);
	}
	dup2(fd[0], STDIN_FILENO);
	waitpid(pid, NULL, 1);
	close(fd[1]);
}

int	main(int argc, char *argv[], char *envp[])
{
	int		fd_input;
	int		fd_out;
	int		counter;
	char	**possible_paths;

	check_number_of_arguments(argc);
	fd_input = open(argv[1], O_RDONLY);
	ft_validity_check(fd_input, argv[1]);
	fd_out = open(argv[argc - 1], O_CREAT | O_WRONLY | O_TRUNC, 0777);
	ft_validity_check(fd_out, argv[1]);
	dup2(fd_input, STDIN_FILENO);
	dup2(fd_out, STDOUT_FILENO);
	possible_paths = get_paths(envp);
	counter = 2;
	while (counter < argc - 2)
	{
		spawn_process(argv + counter, possible_paths, envp);
		counter++;
	}
	execute_command(argv[argc - 2], possible_paths, envp);
	close_desctiptors(2, fd_out, fd_input);
	return (0);
}
