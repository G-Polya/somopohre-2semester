#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <limits.h>

#define  random_range (32758);

char* SubString(char* input, int begin, int end)
{
	char* substring = (char*)malloc(sizeof(char) * (end - begin + 2));
	strncpy(substring, input + begin, end - begin + 1);
	substring[end - begin + 1] = 0;
	return substring;
}

void get_capacity(char* input)
{
	printf("memory storage capacity: %s", SubString(input, 15, 19));
}

int main(int argc, char* argv[])
{
	srand(time(NULL));
	char buffer[255];
	int len = 0;
	int count = 0;

	//FILE* objfile = fopen(argv[1], "r");
	FILE* objfile = fopen("source.obj", "r");
	
	while (1)
	{

		fgets(buffer, sizeof(buffer), objfile);
		if (buffer[0] == 'T')
		{
			char* temp_length = SubString(buffer, 7, 8);
			count += strtol(temp_length, NULL, 16);
		}
		
		len = strlen(buffer);

		if (len == 0)
			break;
		
		buffer[0] = '\0';
	}

	fseek(objfile, 0, SEEK_SET);

	fgets(buffer, sizeof(buffer), objfile);

	get_capacity(buffer);

	int start_addr = (int)rand() % random_range;
	printf("memory start address : %d\n", start_addr);
	int end_addr = start_addr + count - 1;
	printf("memory last address : %d\n", end_addr);

	printf("%s\n", fgets(buffer, sizeof(buffer), objfile));
	printf("%d\n", count);


	return 0;
}