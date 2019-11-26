#include <stdio.h>

int main(int argc, char* argv[])
{
    int c, m = 0, n = 0, i, j;
    char Dividend[100], Divisor[50], Remainder[100];/*M�� dividend polynomial, G�� divisor polynomial, R�� remainder polynomial*/
    
    //generator program ������� ù��° ������ �о�´�. �� ����� polynomial�� �ǹ��Ѵ�
    while ((c = getchar()) != '\n')
	{
		Divisor[n] = c;          //G�� polynomial�� �����Ѵ�
		n++;               
    }
    
    //generator program ������� �ι�° ������ �о�´�. �� ������ ���۵� message�� �ǹ��Ѵ�
	while ((c = getchar()) != '\n')
	{
		Dividend[m] = c;          //store the message in M
		m++;               //the number of bits in M
    }
    
    for (i = 0; i < m; i++)
	{
		Remainder[i] = Dividend[i];
    }

    for (i = 0; i < m - n + 1; i++)
	{
		if (Remainder[i] == '1')
		{
			for (j = i; j < n + i; j++)
			{
				if (Remainder[j] == Divisor[j - i]) Remainder[j] = '0';
				else Remainder[j] = '1';
			}
		}
		else
		{
			for (j = i; j < n + i; j++)
			{
				if (Remainder[j] == '0') Remainder[j] = '0';
				else Remainder[j] = '1';
			}
		}
    }

    j = 0;            //remainder R�� �ִ� '0'�� ����

	for (i = 0; i < m; i++)
	{
		if (Remainder[i] == '0')
		{
			j++;
			continue;
		}
		else
		{
			printf("Errors accur while transmitting.\n");
			return;
		}
    }
    if (j == m)
	{
		printf("The message is transmitted correctly.\n");
		printf("The original message is: ");
		for (i = 0; i < m - n + 1; i++) 
			putchar(Dividend[i]);
		putchar('\n');
    }

    return 0;
}
