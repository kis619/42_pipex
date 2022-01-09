#include <stdio.h>
#include "libft/libft.h"
#include <fcntl.h>
#include <sys/wait.h>
//#include <error.h>?
// errno: some number
//#include <string.h>?

void print_strings_array(int count, char **args)
{
	int i;

	i = 0;
	while (i < count)
	{
		printf("Argument number %d: %s\n", i, args[i]);
		i++;
	}
}

char *get_input_file(char **arguments)
{
	char *input_file;

	input_file = arguments[1];
	return (input_file);
}

char * get_output_file(int argc, char **arguments)
{
	char *output_file;

	output_file = arguments[argc - 1];
	return (output_file);
}

char	**get_commands(int argc, char *argv[])
{
	char	**arr;
	int i;
	int j;

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

void execute_command(char *command, char *argv[], char *envp[]) //should receive fd and direct there
{
	char *elements[3];
	char *path_cmds;

	path_cmds = "/usr/bin/";
	elements[0] = ft_strjoin(path_cmds, command);
	elements[1] = get_input_file(argv);
	elements[2] = "file2";
	elements[3] = NULL;
	// int fd = open("NEW_FILE", O_RDWR); ///////////// redirect output
	// dup2(fd, 1);                       /////////////
	// close(fd);                         /////////////
	execve(elements[0], elements, envp);
}

int main (int argc, char *argv[], char *envp[])
{
	int pid1;
	char **commands;
	// int fd[2];

	if (argc < 4) //remeber to change back to 5
		return (printf("Error! Get your shit together... Too few arguments...\n"));

	// if (pipe(fd) == -1)
	// 	return (-1);
	commands = malloc((argc - 2) * sizeof(char *));
	commands = get_commands(argc, argv);
	pid1 = fork();
	if (pid1 == 0)
		{
			// dup2(fd[1], STDOUT_FILENO);
			// close(fd[0]);
			// close(fd[1]);
			execute_command(commands[0], argv, envp);
		}
	
	
	waitpid(pid1, NULL, 0);
	// int fd_input;
	// fd_input = open(get_input_file(argv), O_RDWR);
	// dup2(fd_input, 0);
	
	return (0);
}