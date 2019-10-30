using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 문제2
{
    class 문제2
    {
        public static void Main(string[] args)
        {
            Console.Write("수를 입력하시오: ");
            int input_number = int.Parse(Console.ReadLine());

            int[,] matrix = new int[input_number, input_number]; // 2차원 배열

            for (int col = 0; col < matrix.GetLength(0); col++)
            {
                for (int row = 0; row < matrix.GetLength(1); row++)
                {
                    if (col % 2 == 0)
                    {
                        matrix[col, row] = row + col * input_number;
                    }
                    else if (col % 2 == 1)
                    {
                        //matrix안의 원소와 index간의 관계를 고려할것
                        matrix[col, row] = (input_number - row - 1) + col * input_number;


                    }
                }
            }



            for (int col = 0; col < matrix.GetLength(0); col++)
            {
                for (int row = 0; row < matrix.GetLength(1); row++)
                {
                    Console.Write("{0,-3} ", matrix[col, row]);
                }
                Console.WriteLine();
            }

        }
    }
}
