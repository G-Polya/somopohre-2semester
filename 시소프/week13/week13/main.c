#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <limits.h>

#define  random_range (32758);



int get_Upcasting(long x)
{
	//x가 16진수로 1자리면 +16(16진수 10)	후 제일 첫번째 자리
	//x가 16진수로 2자리(10~99) +256(16진수 100)
	//x가 16진수로 3자리(100~999) +4096(16진수 1000)


	if (x < 16)
		return x / 16;
	else if (x >= 16 && x < 256)		//10~99 
		return x / 16;
	else if (x >= 256 && x < 4096)		//100~999
		return x / 256;
	else if (x >= 4096 && x < 65536)	//1000~9999
		return (x + 4096) / 4096;

}

long get_remainer(int x)
{


	if (x >= 16 && x < 256)
		return get_Upcasting(x) * 16 - x;
	else if (x >= 256 && x < 4096)
		return get_Upcasting(x) * 256 - x;
	else if (x >= 4096 && x < 65536)
		return get_Upcasting(x) * 4096 - x;


}

int loop(int k, int instruction, int start_addr, int location_count, int i, int* location, int limit)
{
	if (instruction + start_addr < limit * k)
	{
		for (int j = 0; j < location_count; j++)
		{
			if (i - 1 == location[j])
			{
				return 1;
			}
			else if (i - 2 == location[j])
			{
				return (instruction + start_addr - limit * i);
			}
		}
	}
}

char* SubString(char* input, int begin, int end)
{
	char* substring = (char*)malloc(sizeof(char) * (end - begin + 2));
	strncpy(substring, input + begin, end - begin + 1);
	substring[end - begin + 1] = 0;
	return substring;
}


int main(int argc, char* argv[])
{
	srand(time(NULL));

	char buffer[255];	//라인 하나를 읽어서 저장할 buffer
	int len = 0;
	int count = 0;		//목적코드의 총 길이
	int location_count = 0;
	int T_count = 0;	//시작이 T인 문자열
	int* locations = (int*)malloc(sizeof(int) * location_count);
	//FILE* objfile = fopen(argv[1], "r");
	FILE* objfile = fopen("source.obj", "r");

	while (!feof(objfile))
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
			locations[location_count] = strtol(location, NULL, 16);

			location_count++;
		}

		len = strlen(buffer);

		if (len == 0)
			break;

		buffer[0] = '\0';
	}

	fseek(objfile, 0, SEEK_SET);

	fgets(buffer, sizeof(buffer), objfile);

	printf("---------------------Result-------------------\n");

	printf("memory storage capacity: %X\n", strtol(SubString(buffer, 15, 19), NULL, 16));

	long start_addr = (int)rand() % random_range;


	printf("memory start address : %d\n", start_addr);
	int end_addr = start_addr + count - 1;
	printf("memory last address : %d\n", end_addr);



	// address  instruction
	int address = start_addr; // 초기화


	int all_length = 0;

	char** lines = (char**)malloc(sizeof(char*) * T_count);
	char** temps = (char**)malloc(sizeof(char*) * T_count);
	int* temps_length = (int*)malloc(sizeof(int) * T_count);
	for (int i = 0; i < T_count; i++)
	{
		lines[i] = fgets(buffer, sizeof(buffer), objfile);
		int line_length = strlen(lines[i]) - 2;
		char* temp = SubString(lines[i], 9, line_length);
		temps_length[i] = strlen(temp);
		temps[i] = temp;
		all_length += temps_length[i];

	}



	char* all_instruction = (char*)malloc(sizeof(char));	//T로 시작하는 목적코드들에서 시작주소와 길이를 제외한 "실질적인 코드"부분을 하나의 문자열로 합침. 그 하나의 문자열 
	all_instruction = SubString(all_instruction, 5, all_length);
	all_instruction[0] = 0;
	for (int i = 0; i < T_count; i++)
	{
		strcat(all_instruction, temps[i]);
	}


	char* temp_all = SubString(all_instruction, 0, all_length);

	//FILE* after_relocation = fopen(argv[2], "w");
	FILE* after_relocation = fopen("after.txt", "w");

	int relocation_addr_int[3];
	char relocation_addr_string[3][7];

	for (int i = 0; i < 3; i++)
	{
		relocation_addr_int[i] = strtol(SubString(all_instruction, locations[i] * 2, locations[i] * 2 + 5), NULL, 16) + start_addr;

		sprintf(relocation_addr_string[i], "%X", relocation_addr_int[i]);	// 런타임 에러나는 이유
		relocation_addr_string[i][6] = '\0';

	}


	all_length -= 1;

	for (int i = 0; i < all_length; i++)
	{
		for (int j = 0; j < location_count; j++)
		{
			if (i == locations[j] * 2)
			{

				for (int k = 0; k < 6; k++)
				{
					all_instruction[i + k] = relocation_addr_string[j][k];
				}
			}

		}
	}

	for (int i = 0; i < all_length; i++)
	{
		int instruction = strtol(SubString(all_instruction, 0, 1), NULL, 16);


		fprintf(after_relocation, "%d %02X\n", address, instruction);
		all_instruction = SubString(all_instruction, 2, all_length);
		all_length = strlen(all_instruction);
		address += 1;
	}


	address = start_addr;
	printf("before modification:\n");
	printf("Address  instruction\n");
	for (int i = 0; i < 3; i++)
		printf("%d %10X\n", address + locations[i], relocation_addr_int[i] - start_addr);

	printf("\n");
	printf("after modification:\n");
	printf("Address  instruction\n");
	for (int i = 0; i < 3; i++)
		printf("%d %10X\n", address + locations[i], relocation_addr_int[i]);




	free(lines);
	free(temps);
	fclose(after_relocation);
	fclose(objfile);
	return 0;
}
