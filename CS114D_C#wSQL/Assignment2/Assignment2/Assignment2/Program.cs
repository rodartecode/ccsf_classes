using System;
using System.Collections.Generic;

namespace Assignment2
{
    class Program
    {
        static void Main(string[] args)
        {
            Gamer player1 = new Gamer("Jesse", "Rodarte", "SeizeTheMeans", 10, 2);
            Gamer player2 = new Gamer();
            Gamer player3 = new Gamer();

            player2.getInfo();
            player3.getInfo();

            LinkedList<Gamer> list1 = new LinkedList<Gamer>();

            list1.AddLast(player1);
            list1.AddLast(player2);
            list1.AddLast(player3);

            foreach (Gamer player in list1)
                player.printInfo();
        }
    }
}

/****
 * 
 * 
 OUTPUT:

Please enter the gamer's first name: BuBu
Please enter the gamer's last name: Cat
Now enter their gamertag: BigGameHunter00
How many wins?: 4234
How many losses?: 2341
Please enter the gamer's first name: Annie
Please enter the gamer's last name: Roo
Now enter their gamertag: XxProfPawsxX
How many wins?: 23
How many losses?: 55
Jesse Rodarte(SeizeTheMeans), 10 wins 2 losses, win-to-loss: 5, KtD: 1
BuBu Cat(BigGameHunter00), 4234 wins 2341 losses, win-to-loss: 1.81, KtD: 6
Annie Roo(XxProfPawsxX), 23 wins 55 losses, win-to-loss: 0.42, KtD: 0.8
 * 
 * 
 ****/
