using System;

namespace hallmark
{
    class Program
    {
        static void Main(string[] args)
        {
            Hallmark christmas = new Hallmark();
            Hallmark birthday = new Hallmark();

            string NameFrom = "Jesse";
            string xmasName = "Ava";
            string xmasMsg = "To my little baby neice";
            string xmasOccasion = "Merry Christmas!";
            string bdayName = "Emma";
            string bdayMsg = "To my little baby puppy";
            string bdayOccasion = "Happy Birthday!";

            christmas.makeCard(xmasName, NameFrom, xmasMsg, xmasOccasion);
            birthday.makeCard(bdayName, NameFrom, bdayMsg, bdayOccasion);

            christmas.display();
            birthday.display();

            Console.ReadKey();
        }

        /**********
         * 
         * EXPECTED OUTPUT:
         * 
         * To: Ava, From: Jesse, To my little baby neice, Merry Christmas!
         * To: Emma, From: Jesse, To my little baby puppy, Happy Birthday!
         *
         * 
         *********/
    }
}
