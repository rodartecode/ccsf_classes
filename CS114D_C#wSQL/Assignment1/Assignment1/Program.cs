/* 
 Assignment1.cs
 Guest List
 Jesse E Rodarte
 1/31/18
 CS114D
 Ladawn Meade

 */

using System;

namespace GuestList
{
    class GuestList
    {
        const int MAX = 10;

        static void Main(string[] args)
        {
            string[] guestList = new string[MAX];
            inputGuest(guestList);
            printList(guestList);
            Console.Write("Guest search for 'Jesse' returned: {0}", lookUp("Jesse", guestList));
        }


        public static void inputGuest(string[] list)
        {
            bool tryAgain = true;
            int index = 0;
            while(tryAgain == true)
            {
                Console.Write("Enter a guest into the guest list: ");
                list[index] = (Console.ReadLine());
                Console.Write("Would you like to enter another? (Y/N): ");
                char result = Convert.ToChar(Console.ReadLine());
                if (result != 'y' && result != 'Y')
                    tryAgain = false;
                index++;
                if (index >= MAX)
                {
                    Console.WriteLine("Sorry! The Guest List is Full!!");
                    tryAgain = false;
                }
                if (tryAgain == false)
                    Console.WriteLine("Thank You!");
            }

        }




        public static void printList(string[] list)
        {
            Console.WriteLine("Tonight's Guest List is:");
            for (int i = 0; i < list.Length; i++)
            {
                Console.WriteLine("#{0}) {1}", i + 1, list[i]);
            }
        }




        public static bool lookUp(string name, string[] list)
        {
            bool result = false;
            for (int i = 0; i < list.Length; i++)
                if (list[i] == name)
                    result = true;
            return result;
        }
    }
}
