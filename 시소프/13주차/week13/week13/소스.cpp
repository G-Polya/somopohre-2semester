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
	int location_count = 0;
	int T_count = 0;
	int* locations = (int*)malloc(sizeof(int) * location_count);
	//FILE* objfile = fopen(argv[1], "r");
	FILE* objfile = fopen("source.obj", "r");
	
	while (1)
	{

		fgets(buffer, sizeof(buffer), objfile);
		if (buffer[0] == 'T')
		{
			char* line_length = SubString(buffer, 7, 8);
			count += strtol(line_length, NULL, 16);
			T_count++;
		}
		else if (buffer[0] == 'M')
		{
			char* location = SubString(buffer, 1, 6); // relocation이 일어나야하는 위치
			locations[location_count] = atoi(location);
			printf("%d\n", locations[location_count]);

			location_count++;
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
	start_addr = 2260;
	printf("memory start address : %d\n", start_addr);
	int end_addr = start_addr + count - 1;
	printf("memory last address : %d\n", end_addr);

	

	// address  instruction
	int address = start_addr; // 초기화

	FILE* after_relocation = fopen("after.txt", "w");

	char* all_instruction = (char*)malloc(sizeof(char));
	int all_length = strlen(all_instruction) - 1;
	all_instruction = SubString(all_instruction, 5, all_length);

	char** lines = (char**)malloc(sizeof(char*) * T_count);

	for (int i = 0; i < T_count; i++)
	{
		lines[i] = fgets(buffer, sizeof(buffer), objfile);
		int line_length = strlen(lines[i]) - 2;
		char* temp = SubString(lines[i], 9, line_length);
		strcat(all_instruction, temp);
	}

	printf("%s\n", all_instruction);
	
	/*int location_temp = 1 + 6 + 2 + locations[0];
	fseek(objfile, 0, SEEK_SET);
	fgets(buffer, sizeof(buffer), objfile);
	fseek(objfile, location_temp, SEEK_CUR);
	char* temp_ = fgets(buffer, sizeof(buffer), objfile);
	*/
	
	return 0;
}
