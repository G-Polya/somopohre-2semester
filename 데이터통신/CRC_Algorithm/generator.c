#include <stdio.h>

int main(int argc, char* argv[])
{
    int c, m = 0, n = 0, i, j;
    char Dividend[100], Divisor[50], Remainder[100];/*Dividend�� dividend polynomial, G�� divisor polynomial, R�� remainder*/
	
    //���Ͽ��� 0�� 1�� ������ m-bit �޽����� �����ϴ� �ƽ�Ű �ؽ�Ʈ�� ù��° ������ �о�´�
    while((c = getchar()) != '\n')
	{
		//putchar(c);
		Dividend[m] = c;        
		m++;             
    }

    //n-bit polyinomial�� ǥ���ϴ� �ι�° ������ ���Ͽ��� �о�´�
	printf("\nThe polynomial is: ");
    while((c = getchar()) != '\n')
	{
		putchar(c);
		Divisor[n] = c;        //store the divisor polynomial in G
		Dividend[m + n] = '0';  //append 0 bits after M[m - 1]
		n++;             //the number of bits in G
    }
    printf("\n");

    //�ʱ⿡�� remainder�� dividend�� �����ϰ� �����
	for (i = 0; i < m + n - 1; i++)
	{
		Remainder[i] = Dividend[i];
    }
    
    // remainder R�� ���ϱ� ���ؼ� (m-1)�� ����� �ǽ�
	for (i = 0; i < m - 1; i++)
	{
		if (Remainder[i] == '1')
		{
			for (j = i; j < n + i; j++)
			{
				if (Remainder[j] == Divisor[j - i]) 
					Remainder[j] = '0';
				else
					Remainder[j] = '1';
			}
		}
		else
		{
			for (j = i; j < n + i; j++)
			{
				if (Remainder[j] == '0')
					Remainder[j] = '0';
				else 
					Remainder[j] = '1';
			}
		}
    }
    
    //���۵Ǵ� �޽����� dividend�� remainder�� ���̿� ����
	printf("\nThe message to be transmitted is: ");
    for (i = 0; i < m + n - 1; i++)
	{
		if (Remainder[i] == Dividend[i])
			Dividend[i] = '0';
		else 
			Dividend[i] = '1';
		putchar(Dividend[i]);
    }
    printf("\n");

    return 0;
}
