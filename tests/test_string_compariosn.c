#include <stdio.h>
int main(void)
{
	char *word1;
	char *word2;

	word1 = "word";
	word2 = "word";
	if (word1 == word2)
	{
		printf("equal but different\n");
	}
}
