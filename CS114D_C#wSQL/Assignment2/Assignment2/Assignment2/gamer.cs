using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Assignment2
{
    class Gamer
    {

        private string firstName;
        public string FirstName
        {
            get
            {
                return this.firstName;
            }
            set
            {
                this.firstName = value;
            }
        }




        private string lastName;
        public string LastName
        {
            get
            {
                return this.lastName;
            }
            set
            {
                this.lastName = value;
            }
        }





        private string tag;
        public string Tag
        {
            get
            {
                return this.tag;
            }
            set
            {
                this.tag = value;
            }
        }





        private decimal ktd;
        public decimal Ktd
        {
            get
            {
                return this.ktd;
            }
            set
            {
                this.ktd = value;
            }
       
        }





        private decimal wtl;
        public decimal Wtl
        {
            get
            {
                return this.wtl;
            }
            set
            {
                this.wtl = value;
            }
        }





        private int wins;
        public int Wins
        {
            get
            {
                return this.wins;
            }
            set
            {
                this.wins = value;
            }
        }





        private int loss;
        public int Loss
        {
            get
            {
                return this.loss;
            }
            set
            {
                this.loss = value;
            }
        }





        public Gamer()
        {
            this.firstName = "";
            this.lastName = "";
            this.tag = "";
            this.ktd = 0;
            this.wtl = 0;
            this.wins = 0;
            this.loss = 1;
        }





        public Gamer(string first, string last, string tag, int wins, int loss)
        {
            this.firstName = first;
            this.lastName = last;
            this.wins = wins;
            this.loss = loss;
            this.tag = tag;
            this.ktd = 1;
            if (loss != 0)
            {
                this.Wtl = (decimal)wins / (decimal)loss;
            }
            else
            {
                this.Wtl = wins;
            }
        }





        public void setName()
        {
            Console.Write("Please enter the gamer's first name: ");
            this.FirstName = Console.ReadLine();
            Console.Write("Please enter the gamer's last name: ");
            this.LastName = Console.ReadLine();
        }





    
        public void setTag()
        {
            Console.Write("Now enter their gamertag: ");
            this.Tag = Console.ReadLine();
        }





        public void setWL()
        {
            bool result = false;
            do
            {
                Console.Write("How many wins?: ");
                string input = Console.ReadLine();
                int output;
                if (Int32.TryParse(input, out output))
                {
                    this.Wins = output;
                    result = true;
                }
                else
                    Console.Write("Invalid input.  Try Again. ");
            } while (result == false);

            result = false;
            do
            {
                Console.Write("How many losses?: ");
                string input = Console.ReadLine();
                int output;
                if (Int32.TryParse(input, out output))
                {
                    this.Loss = output;
                    result = true;
                }         
                else
                    Console.Write("Invalid input.  Try Again. ");
            } while (result == false);
            this.setWinLoss();
        }





        public void setWinLoss()
        {
            this.Wtl = (decimal)Wins / (decimal)Loss;
        }





        public void getInfo()
        {
            Random random = new Random();
            int kills = random.Next(51);
            int deaths = random.Next(51);
            this.setName();
            this.setTag();
            this.setWL();
            if (deaths != 0)
            {
                this.Ktd = (decimal)kills / (decimal)deaths;
            }
            else
            {
                this.Ktd = kills;
            }
            this.setWinLoss();
        }





        public void printInfo()
        {
            Console.WriteLine("{0} {1}({2}), {3} wins {4} losses, win-to-loss: {5}, KtD: {6}", 
                this.FirstName, this.LastName, this.Tag, this.Wins, this.Loss, this.wtl.ToString("0.##"), this.ktd.ToString("0.##"));
        }
    }
}
