using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _2016112158_실습3주_1번
{
    class 문제1
    {
        public static void Main(string[] args)
        {
            Console.Write("수를 입력하시오: ");

            int input_number = int.Parse(Console.ReadLine());

            int[,] matrix = new int[input_number, input_number]; // 2차원 배열

            for (int col = 0; col < matrix.GetLength(0); col++) // (i,j) 행렬. i행 j열
            {
                for (int row = 0; row < matrix.GetLength(1); row++)
                {
                    matrix[col, row] = row + col * input_number; // 2차원 배열을 1차원 배열처럼
                }
            }


            //2차원 배열 출력
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
