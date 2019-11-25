#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

typedef struct table
{
	char label[10];
	char opcode[10];
	char operand[20];
} table;

int search_opcode(table _table[], int size);
int search_operand(table _table[], int size);

int main(int argc, char* argv[])
{
<<<<<<< HEAD
	if (argc == 3)
	{
		FILE* fp_input = fopen(argv[1], "r");
=======
	
	if(argc == 3)
	{
		FILE* fp_input = fopen(argv[1],"r");
>>>>>>> origin/master
		table list[100];
		int i = 0, j = 0, k = 0;
		char c;

		while (!feof(fp_input))
		{
			c = fgetc(fp_input);
			if (c == '\n')
				c = fgetc(fp_input);
			if (c != ' ')
			{
				fseek(fp_input, -1, SEEK_CUR);

				fscanf(fp_input, "%s", list[i].label);
				i++;

				fscanf(fp_input, "%s", list[j].opcode);
				if (!search_opcode(list, j))
					j++;

				fscanf(fp_input, "%s", list[k].operand);
				if (!strcmp(list[k].operand, list[1].label))
					break;
				if (!search_operand(list, k))
					k++;
			}
			else  //첫글자가 공백이라면 
			{
				fseek(fp_input, 8, SEEK_CUR);	//파일의 읽기/쓰기 위치이동. 이제 현재 읽기/쓰기 포인터위치는 8이 된다
				fscanf(fp_input, "%s", list[j].opcode);
				if (!search_opcode(list, j))
					j++;
				if (!strcmp(list[j].opcode, "rsub"))
					continue;
				fscanf(fp_input, "%s", list[k].operand);

				if (!search_operand(list, k))
					k++;
			}
		}

<<<<<<< HEAD
		FILE* fp_output = fopen(argv[2], "w");
		if (!feof(fp_output))
		{
			fprintf(fp_output, "======label======\n");

			for (int order = 0; order < i; order++)
=======
		FILE* fp_output = fopen(argv[2],"w");
	
		if(!feof(fp_output))
		{
			fprintf(fp_output, "======label======\n");

			for (order = 0; order < i; order++)
>>>>>>> origin/master
			{
				fprintf(fp_output, "%s\n", list[order].label);
			}
			fprintf(fp_output, "======opcode======\n");
<<<<<<< HEAD
			for (int order = 0; order < j; order++)
=======
			for (order = 0; order < j; order++)
>>>>>>> origin/master
			{
				fprintf(fp_output, "%s\n", list[order].opcode);
			}
			fprintf(fp_output, "======operand======\n");
<<<<<<< HEAD
			for (int order = 0; order < k; order++)
=======
			for (order = 0; order < k; order++)
>>>>>>> origin/master
			{
				fprintf(fp_output, "%s\n", list[order].operand);
			}
		}


		fclose(fp_input);
		fclose(fp_output);
	}
	else
<<<<<<< HEAD
		printf("Segmentation Error\n");
=======
	{
		printf("Segmentation fault\n");
	}
	

>>>>>>> origin/master
	return 0;

}


int search_opcode(table _table[], int size)
{

	for (int i = 0; i < size; i++)
	{
		if (!strcmp(_table[size].opcode, _table[i].opcode))
		{
			return 1;
		}
	}
	return 0;
}


int search_operand(table _table[], int size)
{

	for (int i = 0; i < size; i++)
	{
		if (!strcmp(_table[size].operand, _table[i].operand))
		{
			return 1;
		}
	}
	return 0;
}
