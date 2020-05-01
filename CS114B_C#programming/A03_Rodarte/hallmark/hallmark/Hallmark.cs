using System;

namespace hallmark
{
    class Hallmark
    {
        string nameTo;
        string nameFrom;
        string occasion;
        string message;

        private string msg
        {
            get
            {
                return "To: " + nameTo + ", From: " + nameFrom + ", " + message + ", " + occasion;
            }
            set
            {
                message = value;
            }
        }
        
        public void display()
        {
            Console.WriteLine(msg);
        }

        public void makeCard(string NameTo, string NameFrom, string Message, String Occasion)
        {
            nameTo = NameTo;
            nameFrom = NameFrom;
            msg = Message;
            occasion = Occasion;
        }
    }
}
