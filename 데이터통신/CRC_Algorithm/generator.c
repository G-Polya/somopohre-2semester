#include <stdio.h>

int main(int argc, char* argv[])
{
    int c, m = 0, n = 0, i, j;
    char M[100], G[50], R[100];/*M�� dividend polynomial, G�� divisor polynomial, R�� remainder*/
	
    //���Ͽ��� 0�� 1�� ������ m-bit �޽����� �����ϴ� �ƽ�Ű �ؽ�Ʈ�� ù��° ������ �о�´�
    while((c = getchar()) != '\n')
	{
		//putchar(c);
		M[m] = c;        //store the message in M
		m++;             //the number of bits in M
    }

    //n-bit polyinomial�� ǥ���ϴ� �ι�° ������ ���Ͽ��� �о�´�
	printf("\nThe polynomial is: ");
    while((c = getchar()) != '\n')
	{
		putchar(c);
		G[n] = c;        //store the divisor polynomial in G
		M[m + n] = '0';  //append 0 bits after M[m - 1]
		n++;             //the number of bits in G
    }
    printf("\n");

    //�ʱ⿡�� remainder�� dividend�� �����ϰ� �����
	for (i = 0; i < m + n - 1; i++)
	{
		R[i] = M[i];
    }
    
    // remainder R�� ���ϱ� ���ؼ� (m-1)�� ����� �ǽ�
	for (i = 0; i < m - 1; i++)
	{
		if (R[i] == '1')
		{
			for (j = i; j < n + i; j++)
			{
				if (R[j] == G[j - i]) 
					R[j] = '0';
				else
					R[j] = '1';
			}
		}
		else
		{
			for (j = i; j < n + i; j++)
			{
				if (R[j] == '0')
					R[j] = '0';
				else 
					R[j] = '1';
			}
		}
    }
    
    //���۵Ǵ� �޽����� dividend�� remainder�� ���̿� ����
	printf("\nThe message to be transmitted is: ");
    for (i = 0; i < m + n - 1; i++)
	{
		if (R[i] == M[i])
			M[i] = '0';
		else 
			M[i] = '1';
		putchar(M[i]);
    }
    printf("\n");

    return 0;
}
