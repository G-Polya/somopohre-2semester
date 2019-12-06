#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

typedef struct
{
	char symbol[20];
	int value;
	//char value[20];
}stdata;

int main()
{
	stdata data[100];
	char buffer[100];
	FILE* optTable = fopen("optab.txt", "r");
	if (!optTable)
	{
		printf("File open Error");
		return;
	}

	int count = 0;

	while (!feof(optTable))
	{

		fscanf(optTable, "\n%[^,],%x", data[count].symbol, &data[count].value);
		printf("%s %02X\n", data[count].symbol, data[count].value);


		count++;

	}


	while (1)
	{
		printf("\n");
		int i;

		printf("찾고자 Value의 Symbol 입력(종료는 quit 입력): ");
		char input_symbol[5];

		scanf("%s", input_symbol);

		int temp;
		for (i = 0; i < count; i++)
		{

			temp = strcmp(data[i].symbol, input_symbol);
			if (temp == 0)
			{

				printf("Value : %02X\n", data[i].value);
				continue;
			}
		}

		if ((strcmp(data[0].symbol, input_symbol) != 0) &&
			(strcmp(data[1].symbol, input_symbol) != 0) &&
			(strcmp(data[2].symbol, input_symbol) != 0) &&
			(strcmp(data[3].symbol, input_symbol) != 0) &&
			(strcmp(data[4].symbol, input_symbol) != 0))
		{
			printf("Symbol을 찾지 못했습니다.\n");
		}


		if (strcmp(input_symbol, "quit") == 0)
		{
			printf("종료합니다.\n");
			break;
		}

	}



	fclose(optTable);
	return 0;
}