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
void address_and_instruction(int address, char* input);

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
			char* line_length = SubString(buffer, 7, 8);
			count += strtol(line_length, NULL, 16);
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

	//printf("%s", fgets(buffer, sizeof(buffer), objfile));
	//printf("%s", fgets(buffer, sizeof(buffer), objfile));

	printf("%d\n", count);

	// address  instruction
	int address = start_addr; // 초기화

	printf("---------one line--------\n");
	char* one_line = fgets(buffer, sizeof(buffer), objfile);
	printf("%s", one_line);
	int one_line_length = strlen(one_line) - 2; // 문자열의 마지막 널문자 제거(-1), 공백문자 제거(-1)
	

	char* temp = SubString(one_line, 9, one_line_length);
	
	int temp_length = strlen(temp) -1;
	printf("%s\n\n", temp);
	
	for (int i = 0; i < temp_length; i *= 2)
	{
		printf("%d %s\n", address, SubString(temp, 0, 1));

		temp = SubString(temp, 2, temp_length);
		temp_length = strlen(temp) - 1;
		address += 1;
	}
	
	printf("---------two line--------\n");
	char* two_line = fgets(buffer, sizeof(buffer), objfile);
	printf("%s", two_line);
	int two_line_length = strlen(two_line) - 2;
	temp = SubString(two_line, 9, two_line_length);
	temp_length = strlen(temp) - 1;
	printf("%s\n\n", temp);

	for (int i = 0; i < temp_length; i *= 2)
	{
		printf("%d %s\n", address, SubString(temp, 0, 1));

		temp = SubString(temp, 2, temp_length);
		temp_length = strlen(temp) - 1;
		address += 1;
	}


	return 0;
}

void address_and_instruction(int address, char* input)
{
	int temp_length = strlen(input) - 1;
	char* temp = SubString(input, 2, temp_length);

	printf("%d %s\n", address, SubString(input, 0, 1));
}