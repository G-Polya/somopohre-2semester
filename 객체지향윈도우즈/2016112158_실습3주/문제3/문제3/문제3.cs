using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 문제3
{
    class 문제3
    {
        public static void Main(string[] args)
        {
            Console.Write("수를 입력하시오: ");
            int input_number = int.Parse(Console.ReadLine());


            int element = 0;

            for (int col = 0; col < input_number; col++)
            {
                int temp = element;


                for (int row = 0; row < input_number; row++)
                {

                    if (col % 2 == 0)
                    {
                        Console.Write("{0,-3}", element);

                    }
                    else if (col % 2 == 1)
                    {

                        Console.Write("{0,-3}", (input_number - 1) + temp);
                        temp--;

                    }
                    element++;
                }
                Console.WriteLine();
            }

        }
    }
}