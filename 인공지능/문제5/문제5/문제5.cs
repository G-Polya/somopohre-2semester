using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 문제5
{
    class 문제5
    {
        // 주어진 위치에서 가장자리까지 떨어져있는 최소거리를 구하는 함수
        public static int min(int x, int y, int z, int w)
        {
            int min = x;
            int[] arr = new int[4] { x, y, z, w };

            for (int i = 0; i < arr.Length; i++)
            {
                if (arr[i] < min)
                    min = arr[i];
            }

            return min;
        }

        // 결국 Spiral 행렬을 큰 ㅁ안에 작은 ㅁ가 들어가 있는 모습이다
        public static void Main(string[] args)
        {
            int input_number = int.Parse(Console.ReadLine());


            int element;


            // 규칙1
            // row >= col 일때 (row,col)위치의 원소는 (row+col)이고 
            // row < col 일 때의 원소는 (n - 1) *4 - (row + col)이다. 이때 n은 input_number(행렬의 크기)
            // 제일 바깥의 ㅁ안에서는  규칙1이 잘들어맞는다. 단 두번쨰 ㅁ부터는 들어맞지 않는다
            for (int col = 0; col < input_number; col++)
            {
                for (int row = 0; row < input_number; row++)
                {
                    // position은 (row,col)의 요소가 가장자리에서 떨어져 있는 정도를 나타낸다
                    // position가 필요한 이유는 안쪽(숫자 20부터)는 규칙1이 맞지 않는다.
                    
                    int position = min(row, col, input_number - 1 - col, input_number - 1 - row);
                    if (row >= col)
                    {
                        // 2 * position을 빼는 이유는 빼주면 규칙1에 맞기 때문이다
                        element = row + col - 2 * position;
                    }
                    else
                    {
                        // 2 * position을 빼는 이유는 빼주면 규칙1에 맞기 때문이다
                        element = (input_number - 1 - 2 * position) * 4 - (col + row - 2 * position);
                    }

                    element += 4 * (position * input_number - (position * position));
                    Console.Write("{0, -3}", element);
                }
                Console.WriteLine();
            }


        }
    }
}

