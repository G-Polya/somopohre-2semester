#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    int arg, c, i, m = 0;
    char M[100];
    
    /*���� �ΰ��� �Ű������� �����Ѵ�*/
    if (argc != 2) 
		return;

	// argv[1]�� �Ű������� ���������� �ٲ۴�
    arg = atoi(argv[1]);
    
    //generator program ������� ù��° ������ �о�´�. polynomial�� �����ͼ� verifier program�� �Է��Ѵ�
	while ((c = getchar()) != '\n')
	{
		putchar(c);
    }
    printf("\n");
    
    /*Read the second line of the output of the generator program, get the message transmitted.*/
    //generator program ������� �ι�° ������ �о�´�. ��, ���۵� �޽����� �����´�
	while ((c = getchar()) != '\n')
	{
		M[m] = c;          
		m++;               
    }
    
    if (M[arg - 1] == '0') 
		M[arg - 1] = '1';
    else 
		M[arg - 1] = '0';

    for (i = 0; i < m; i++) 
		putchar(M[i]);
    printf("\n");
    
    return 0;
}
