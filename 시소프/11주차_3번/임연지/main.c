#include <stdio.h>
#include <string.h>

struct _list
{
	char label[10];
	char opcode[10];
	char operand[20];
};

int search_opc(struct _list list[], int size)
{
	int i;
	for (i = 0; i < size; i++)
	{
		if (!strcmp(list[size].opcode, list[i].opcode))
		{
			return 1;
		}
	}
	return 0;
}

int search_ope(struct _list list[], int size)
{
	int i;
	for (i = 0; i < size; i++)
	{
		if (!strcmp(list[size].operand, list[i].operand))
		{
			return 1;
		}
	}
	return 0;
}

int main(int argc, char* argv[])
{
	FILE* fp_i, * fp_o;
	struct _list list[100];
	int i = 0, j = 0, k = 0, order;
	char c;

	if ((fp_i = fopen(argv[1], "r")) == NULL)
	{
		printf("파일 불러오기 오류\n");
		return 0;
	}
	while (1)
	{
		c = fgetc(fp_i);
		if (c == '\n')
			c = fgetc(fp_i);
		if (c != ' ')
		{
			fseek(fp_i, -1, SEEK_CUR);

			fscanf(fp_i, "%s", list[i].label);
			i++;

			fscanf(fp_i, "%s", list[j].opcode);
			if (!search_opc(list, j))
				j++;

			fscanf(fp_i, "%s", list[k].operand);
			if (!strcmp(list[k].operand, list[1].label))
				break;
			if (!search_ope(list, k))
				k++;
		}
		else
		{
			fseek(fp_i, 8, SEEK_CUR);
			fscanf(fp_i, "%s", list[j].opcode);
			if (!search_opc(list, j))
				j++;
			if (!strcmp(list[j].opcode, "rsub"))
				continue;
			fscanf(fp_i, "%s", list[k].operand);

			if (!search_ope(list, k))
				k++;
		}
	}
	if ((fp_o = fopen(argv[2], "w")) == NULL)
	{
		printf("파일 불러오기 오류\n");
		return 0;
	}
	fprintf(fp_o, "======label======\n");

	for (order = 0; order < i; order++)
	{
		fprintf(fp_o, "%s\n", list[order].label);
	}
	fprintf(fp_o, "======opcode======\n");
	for (order = 0; order < j; order++)
	{
		fprintf(fp_o, "%s\n", list[order].opcode);
	}
	fprintf(fp_o, "======operand======\n");
	for (order = 0; order < k; order++)
	{
		fprintf(fp_o, "%s\n", list[order].operand);
	}
	fclose(fp_i);
	fclose(fp_o);
	return 0;

}