#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    int arg, c, i, m = 0;
    char M[100];
    
    /*오직 두개의 매개변수만 인정한다*/
    if (argc != 2) 
		return;

	// argv[1]의 매개변수를 정수형으로 바꾼다
    arg = atoi(argv[1]);
    
    //generator program 결과에서 첫번째 라인을 읽어온다. polynomial을 가져와서 verifier program에 입력한다
	while ((c = getchar()) != '\n')
	{
		putchar(c);
    }
    printf("\n");
    
    /*Read the second line of the output of the generator program, get the message transmitted.*/
    //generator program 결과에서 두번째 라인을 읽어온다. 즉, 전송된 메시지를 가져온다
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
