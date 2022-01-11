#include <stdio.h>
char *get_command(char *command_args)
{
	int i;

	i = 0;
	
	while (command_args[i] != ' ')
	{
		i++;
	}
	command_args[i] = '\0';
	return (command_args);
}
int main(void)
{

	printf("%s\n", get_command("edno dve"));
	return (0);
}