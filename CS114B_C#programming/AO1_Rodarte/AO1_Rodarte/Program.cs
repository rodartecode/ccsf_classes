using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AO1_Rodarte
{
    class Program
    {
        static void drawLine()
        {
            Console.WriteLine("   *");
            Console.WriteLine("   *");
        }

        static void drawTriangle()
        {
            Console.WriteLine("*******");
            Console.WriteLine(" *   *");
            Console.WriteLine("  * *");
            Console.WriteLine("   *");
        }

        static void drawSquare()
        {
            Console.WriteLine("*******");
            Console.WriteLine("*     *");
            Console.WriteLine("*     *");
            Console.WriteLine("*******");
        }

        static void Main(string[] args)
        {
            Console.WriteLine("Line: ");
            drawLine();
            Console.WriteLine("Triangle: ");
            drawTriangle();
            Console.WriteLine("Square: ");
            drawSquare();
            Console.WriteLine("Funnel: ");
            drawTriangle();
            drawLine();
            Console.WriteLine("Popsicle: ");
            drawSquare();
            drawLine();
            Console.WriteLine("Down Arrow: ");
            drawLine();
            drawTriangle();
        }
    }
}
