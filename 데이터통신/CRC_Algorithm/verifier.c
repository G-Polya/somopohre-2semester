#include <stdio.h>

int main(int argc, char* argv[])
{
    int c, m = 0, n = 0, i, j;
    char M[100], G[50], R[100];/*M은 dividend polynomial, G은 divisor polynomial, R은 remainder polynomial*/
    
    //generator program 결과에서 첫번째 라인을 읽어온다. 이 결과는 polynomial을 의미한다
    while ((c = getchar()) != '\n')
	{
		G[n] = c;          //G에 polynomial을 저장한다
		n++;               
    }
    
    /*Read the second line of the output of the generator program, that represents the message treansmitted.*/
    //generator program 결과에서 두번째 라인을 읽어온다. 이 라인은 전송된 message를 의미한다
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

    j = 0;            //remainder R에 있는 '0'의 개수

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
