using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 문제4
{
    class 문제4
    {
        public static void Main(string[] args)
        {
            Console.Write("수를 입력하시오: ");
            int input_number = int.Parse(Console.ReadLine());

            int[,] matrix = new int[input_number, input_number]; // 2차원 배열

            int count = 0;
            int col, row;

            for (col = 0; col < (input_number/ 2) + 1; col++)
            {
                for (row = col; row < input_number - col; row++)            // 왼족에서 오른쪽으로 값을 넣는다
                {
                    matrix[col, row] = count++;
                }
                
                
                for (row = col + 1; row < input_number - col; row++)        // 위쪽에서 아래쪽으로 값을 넣는다
                {
                    matrix[row, input_number - col - 1] = count++;
                }

                for (row = input_number - col - 2; row >= col; row--)       // 오른쪽에서 왼쪽으로 값을 넣는다
                {
                    matrix[input_number - col - 1, row] = count++;
                }

                for (row = input_number - col - 2; row >= col + 1; row--)   // 아래쪽에서 위로 값을 넣는다
                {
                    matrix[row, col] = count++;
                
                }
            }



            for (int new_col = 0; new_col < input_number; new_col++)
            {
                for (int new_row = 0; new_row < input_number; new_row++)
                {
                    Console.Write("{0,-3} ", matrix[new_col, new_row]);
                }
                Console.WriteLine();
            }

        }
    }
}
//https://redforce01.tistory.com/189