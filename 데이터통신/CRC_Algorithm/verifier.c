#include <stdio.h>

int main(int argc, char* argv[])
{
    int c, m = 0, n = 0, i, j;
    char M[100], G[50], R[100];/*M�� dividend polynomial, G�� divisor polynomial, R�� remainder polynomial*/
    
    //generator program ������� ù��° ������ �о�´�. �� ����� polynomial�� �ǹ��Ѵ�
    while ((c = getchar()) != '\n')
	{
		G[n] = c;          //G�� polynomial�� �����Ѵ�
		n++;               
    }
    
    /*Read the second line of the output of the generator program, that represents the message treansmitted.*/
    //generator program ������� �ι�° ������ �о�´�. �� ������ ���۵� message�� �ǹ��Ѵ�
	while ((c = getchar()) != '\n')
	{
		M[m] = c;          //store the message in M
		m++;               //the number of bits in M
    }
    
    for (i = 0; i < m; i++)
	{
		R[i] = M[i];
    }

    for (i = 0; i < m - n + 1; i++)
	{
		if (R[i] == '1')
		{
			for (j = i; j < n + i; j++)
			{
				if (R[j] == G[j - i]) R[j] = '0';
				else R[j] = '1';
			}
		}
		else
		{
			for (j = i; j < n + i; j++)
			{
				if (R[j] == '0') R[j] = '0';
				else R[j] = '1';
			}
		}
    }

    j = 0;            //remainder R�� �ִ� '0'�� ����

	for (i = 0; i < m; i++)
	{
		if (R[i] == '0')
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
			putchar(M[i]);
		putchar('\n');
    }

    return 0;
}
