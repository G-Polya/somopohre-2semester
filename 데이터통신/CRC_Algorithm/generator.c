#include <stdio.h>

int main(int argc, char* argv[])
{
    int c, m = 0, n = 0, i, j;
    char Dividend[100], Divisor[50], Remainder[100];/*Dividend은 dividend polynomial, G는 divisor polynomial, R은 remainder*/
	
    //파일에서 0과 1로 구성된 m-bit 메시지를 포함하는 아스키 텍스트의 첫번째 라인을 읽어온다
    while((c = getchar()) != '\n')
	{
		//putchar(c);
		Dividend[m] = c;        
		m++;             
    }

    //n-bit polyinomial을 표현하는 두번째 파일을 파일에서 읽어온다
	printf("\nThe polynomial is: ");
    while((c = getchar()) != '\n')
	{
		putchar(c);
		Divisor[n] = c;        //store the divisor polynomial in G
		Dividend[m + n] = '0';  //append 0 bits after M[m - 1]
		n++;             //the number of bits in G
    }
    printf("\n");

    //초기에는 remainder와 dividend를 동일하게 만든다
	for (i = 0; i < m + n - 1; i++)
	{
		Remainder[i] = Dividend[i];
    }
    
    // remainder R을 구하기 위해서 (m-1)번 계산을 실시
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
    
    //전송되는 메시지는 dividend와 remainder의 차이와 같다
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
