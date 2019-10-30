using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace test
{
    class temp
    {
        public static int min(int x,int y,int z, int w)
        {
            int min = x;
            int[] arr = new int[4] { x, y, z, w };

            for(int i = 0;i<arr.Length;i++)
            {
                if (arr[i] < min)
                    min = arr[i];
            }

            return min;
        }
        public static void Main(string[] args)
        {
            int input_number = int.Parse(Console.ReadLine());


            int element;
            for (int col = 0; col < input_number; col++)
            {
                for (int row = 0; row < input_number; row++)
                {
                    int position = min(col, row, input_number - col - 1, input_number - row - 1);
                    if (row >= col)
                    {
                        element = row + col - 2 * position;
                    }
                    else
                    {
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

