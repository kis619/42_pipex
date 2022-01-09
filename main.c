#include <stdio.h>
#include "libft/libft.h"
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

void get_arguments(int argc, char **arguments)
{
	char *input_file;
	char *output_file;

	input_file = arguments[1];
	output_file = arguments[argc - 1];

	printf("Input file: %s\n", input_file);
	printf("Output file: %s\n", output_file);
}
int main (int argc, char **args)
{
	int id;
	printf("Number of arguments: %d\n", argc);
	id = fork();
	if (id == 0)
		return (0);
	if (argc < 5)
	{
		printf("Error! Get your shit together... Too few arguments...\n");
		return (1);
	}
	get_arguments(argc, args);
	return (0);
}