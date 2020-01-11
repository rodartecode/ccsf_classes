using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AO2_Rodarte
{
    class gork
    {
        private int personnel;

        public void welcome()
        {
            int choice = 0;
            while (choice != 2)
            {
                Console.WriteLine("Welcome to Gork\n");
                Console.Write("1. Play Gork\n2. Exit\nChoose: ");
                choice = int.Parse(Console.ReadLine());

                while (choice != 1 && choice != 2)
                {
                    Console.Write("Choose: ");
                    choice = int.Parse(Console.ReadLine());
                }

                if (choice == 1)
                {
                    playGork();
                }
            }
        }

        public void setPersonnel()
        {
            Console.Write("How many personnel are on your ship?: ");
            personnel = int.Parse(Console.ReadLine());
            Console.WriteLine();
        }

        public void setData()
        {
            int choice;

            Console.Write("You must make a decision. What will you do??\n");
            Console.WriteLine("1. Attempt to repair the ship");
            Console.WriteLine("2. Request emergency rescue from Mission Command.");
            Console.WriteLine("3. Break protocol and reveal the top secret space" +
                " ship's location to \nRussians on a nearby moon.");
            Console.Write("\nChoose: ");

            choice = int.Parse(Console.ReadLine());

            switch (choice)
            {
                case 1:
                    Console.WriteLine("The crew gets to work to repair the ship, however" +
                        "toxic \nmaterial on the moon's surface has corroded the launch " +
                        "\ngear. The crew attempts to launch, but it fails and the ship" +
                        "\nexplodes.");
                    Console.WriteLine("Personnel remaining: 0\n");
                    break;
                case 2:
                    Console.WriteLine("Mission Control dispatches a rescue ship as soon" +
                        "as \nthey can. However by the time they find your ship there are" +
                        " \nonly 2 survivors remaining.");
                    if (personnel == 1)
                        Console.WriteLine("Personnel remaining: 1\n");
                    else
                        Console.WriteLine("Personnel remaining: 2\n");
                    break;
                case 3:
                    Console.WriteLine("The Russians agree to send a rescue ship, but" +
                        " secretly \nattempt to hack into the ship's systems remotely. " +
                        "\nThis causes the ship's onboard security to automatically shut " +
                        "\ndown all communications systems and locks all mission " +
                        "\ncritical storage units, including the storage units that " +
                        "\ncontain the emergency oxygen tanks. One quarter of all personnel" +
                        "\nhave lost their lives...");
                    int quarter = (personnel / 4) * 3;
                    Console.WriteLine("Personnel remaining: {0}\n", quarter);
                    break;
                default:
                    Console.WriteLine("You have been eaten by a Grue.\n");
                    break;
            }
        }
        

        public void playGork()
        {
            Console.WriteLine("You are in charge of a top secret military mission" +
                " \nwhen your space ship makes an emergency landing on the largest moon" +
                " \nof planet Gork. The space ship is damaged. Oxygen levels in the" +
                " \nspace ship begin to drop. \n");

            setPersonnel();
            setData();

        }
    }
}
