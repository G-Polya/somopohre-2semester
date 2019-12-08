#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <limits.h>

#define  random_range (32758);



int get_Upcasting(long x)
{
	//x�� 16������ 1�ڸ��� +16(16���� 10)	�� ���� ù��° �ڸ�
	//x�� 16������ 2�ڸ�(10~99) +256(16���� 100)
	//x�� 16������ 3�ڸ�(100~999) +4096(16���� 1000)
	int upcasting_x = 0;
	
	
	if (x < 16)
		upcasting_x = x / 16;
	else if (x >= 16 && x < 256) 
		upcasting_x = (x + 16) / 16;
	else if (x >= 256 && x < 4096)
		upcasting_x = (x + 256) / 256;
	else if (x >= 4096 && x < 65536)
		upcasting_x = (x + 4096) / 4096;

	return upcasting_x;
}

int get_remainer(int x)
{
	int remainder;
	
	if (x >= 16 && x < 256)
		remainder = get_Upcasting(x) * 256 - x;
	else if (x >= 256 && x < 4096)
		remainder = get_Upcasting(x) * 4096 - x;
	else if (x >= 4096 && x < 65536)
		remainder = get_Upcasting(x) * 65536 - x;

	return remainder
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

	char buffer[255];	//���� �ϳ��� �о ������ buffer
	int len = 0;
	int count = 0;		//�����ڵ��� �� ����
	int location_count = 0;
	int T_count = 0;	//������ T�� ���ڿ�
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
			char* location = SubString(buffer, 1, 6); // relocation�� �Ͼ���ϴ� ��ġ
			locations[location_count] = strtol(location,NULL,16);
			
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

	printf("memory storage capacity: %X\n", strtol(SubString(buffer, 15, 19),NULL,16));

	long start_addr = (int)rand() % random_range;
	start_addr =15;
	
	printf("memory start address : %d\n", start_addr);
	int end_addr = start_addr + count - 1;
	printf("memory last address : %d\n", end_addr);

	

	// address  instruction
	int address = start_addr; // �ʱ�ȭ

	
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
	
	all_length -= 1;
	
	
	char* all_instruction = (char*)malloc(sizeof(char));	//T�� �����ϴ� �����ڵ�鿡�� �����ּҿ� ���̸� ������ "�������� �ڵ�"�κ��� �ϳ��� ���ڿ��� ��ħ. �� �ϳ��� ���ڿ� 
	all_instruction = SubString(all_instruction, 5, all_length);
	all_instruction[0] = 0;
	for (int i = 0; i < T_count; i++)
	{
		strcat(all_instruction, temps[i]);
	}

	
	char* temp_all = SubString(all_instruction, 0, all_length);
	
	
	//FILE* after_relocation = fopen(argv[2], "w");
	FILE* after_relocation = fopen("after.txt", "w");

	
	
	for (int i = 0; i < all_length; i++)
	{
		int instruction = strtol(SubString(temp_all,0,1),NULL,16); 
			
		for (int j = 0; j < location_count; j++)
		{	
			
			if (i == locations[i])
			{
				;
			}
				
			else if (i - 1 == locations[j])
			{
				instruction += get_Upcasting(start_addr);		//�� �� 9�� 16���� 2260> 8D4 > 900(2304) - 2C(44) // 2 
				
			}
			else if (i - 2 == locations[j])
			{
				instruction -= 44;		//�� �� 44�� 10����
			}
		}
		

		fprintf(after_relocation,"%d %02X\n", address, instruction);
		temp_all = SubString(temp_all, 2, all_length);
		all_length = strlen(temp_all);
		address += 1;
	}
	
	int relocation_addr[3];
	for(int i=0;i<3;i++)
		relocation_addr[i] = strtol(SubString(all_instruction, locations[i] * 2, locations[i] * 2 + 5), NULL, 16);
	

	address = start_addr;
	printf("before modification:\n");
	printf("Address  instruction\n");
	for(int i= 0 ;i<3;i++)
		printf("%d %10X\n", address + locations[i], relocation_addr[i]);

	printf("\n");
	printf("after modification:\n");
	printf("Address  instruction\n");
	for (int i = 0; i < 3; i++)
		printf("%d %10X\n", address + locations[i], relocation_addr[i] + start_addr);

	

	
	free(lines);
	free(temps);
	fclose(after_relocation);
	fclose(objfile);
	return 0;
}
