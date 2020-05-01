using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Administrator
{
    class Program
    {
        static public void Main(string[] args)
        {
            string name = "John Smith";
            string ssn = "444-56-7777";
            hourlyEmp newHire = new hourlyEmp(ref name, ref ssn, 65.50, 3);
            newHire.setHours(45.45);
            Console.WriteLine("New Employee: \n" + newHire.getName() + "\n" +
               newHire.getSsn() + "\n" + "Hours: " + newHire.getHours());
            newHire.giveRaise(3.2);
            newHire.setHours(40.0);
            newHire.printCheck();
            Console.WriteLine();

            administrator newAdmin = new administrator();
            newAdmin.getInfo();
            newAdmin.print();
            newAdmin.printCheck();

            Console.ReadKey();
        }
    }

    public interface Iemployee
    {  //base interface
        void changeName(ref string newName);
        void changeSsn(ref string newSsn);
        string getName();
        string getSsn();
        void printCheck();
    }

    class hourlyEmp : Iemployee  //derived class child class
    {
        protected string name;
        protected string ssn;
        protected double netPay;
        private double hours;
        private double payRate;

        public void setHours(double newHours)
        {
            this.hours = newHours;


            //this.setHours(newHours);
            this.netPay = this.payRate * this.hours;
        }

        public void giveRaise(double amount)
        {
            this.payRate += amount;
            this.netPay = this.payRate * hours;
        }

        public double getHours()
        {
            return this.hours;
        }

        public void changeSsn(ref string newSsn)
        {
            ssn = newSsn;
        }

        public string getSsn()
        {
            return ssn;
        }

        public void changeName(ref string newName)
        {
            name = newName;
        }

        public string getName()
        {
            return name;
        }

        public void printCheck()
        {
            Console.WriteLine("Pay " + this.name + " the sum of " + this.netPay + " Dollars.");
            Console.WriteLine("Check Stub: ");
            Console.WriteLine("Employee number: " + this.ssn);
            Console.WriteLine("This is an hourly employee.  Hours worked: " + this.hours);
            Console.WriteLine("Rate: " + this.payRate + "    Pay: " + this.netPay);
        }

        public hourlyEmp()
        {
            this.payRate = 0;
            this.hours = 0;
        }

        public hourlyEmp(ref string newName,
                             ref string newSsn,
                             double newPayRate,
                             double newHours)
        {
            this.payRate = newPayRate;
            this.hours = newHours;
            this.netPay = this.hours * this.payRate;
        }

    }

    class salariedEmp : Iemployee
    {
        protected string name;
        protected string ssn;
        protected double netPay;
        protected double salary;
        public void giveRaise(double amount)
        {
            salary += amount;
            netPay += amount;
        }

        public salariedEmp()
        {
            salary = 0;
            netPay = 0;
        }

        public salariedEmp(ref string newName,
                             ref string newSsn,
                             double newWeeklySalary)
        {
            salary = newWeeklySalary;
            netPay = salary;
        }

        public void changeSsn(ref string newSsn)
        {
            ssn = newSsn;
        }

        public string getSsn()
        {
            return ssn;
        }

        public void changeName(ref string newName)
        {
            name = newName;
        }

        public string getName()
        {
            return name;
        }

        public void printCheck()
        {
            Console.WriteLine("Pay " + this.name + " the sum of " + this.netPay + " Dollars.");
            Console.WriteLine("Check Stub: ");
            Console.WriteLine("Employee number: " + this.ssn);
            Console.WriteLine("This is a salaried employee.  Regular pay: ");
            Console.WriteLine(this.salary);
        }
    }

    class administrator : Iemployee
    {
        protected string name;
        protected string ssn;
        protected double netPay;
        protected double salary;
        private string title;
        private string dep;
        private string sup;

        public administrator()
        {
            salary = 0;
            netPay = 0;
        }

        public administrator(ref string newName,
                             ref string newSsn,
                             double newWeeklySalary)
        {
            salary = newWeeklySalary;
            netPay = salary;
        }

        public void getInfo()
        {
            string newName, newSsn, newTit, newDep, newSup;
            double newSal;
            Console.WriteLine("New Administrator Registration");
            Console.WriteLine("Please enter new admin name: ");
            newName = Console.ReadLine();
            Console.WriteLine("Please enter admin social security number: ");
            newSsn = Console.ReadLine();

            Console.WriteLine("Please enter admin weekly salary: ");
            string sal = Console.ReadLine();
            if (double.TryParse(sal, out newSal))
            {
                salary = newSal;
                netPay = newSal;
            }
            else
            {
                Console.WriteLine("Invalid Salary, no pay for you...");
            }

            Console.WriteLine("Please enter admin Title: ");
            newTit = Console.ReadLine();
            Console.WriteLine("Please enter department: ");
            newDep = Console.ReadLine();
            Console.WriteLine("Please enter admin supervisor: ");
            newSup = Console.ReadLine();

            name = newName;
            ssn = newSsn;
            title = newTit;
            dep = newDep;
            sup = newSup;

            Console.WriteLine();
        }

        public void changeSsn(ref string newSsn)
        {
            ssn = newSsn;
        }

        public string getSsn()
        {
            return ssn;
        }

        public void changeName(ref string newName)
        {
            name = newName;
        }

        public string getName()
        {
            return name;
        }

        public void changeSupervisor(ref string newSup)
        {
            sup = newSup;
        }

        public void print()
        {
            Console.WriteLine("Name: " + name);
            Console.WriteLine("SocSecNum: " + ssn);
            Console.WriteLine("Pay: " + netPay);
            Console.WriteLine("Title: " + title);
            Console.WriteLine("Department: " + dep);
            Console.WriteLine("Supervisor: " + sup);
            Console.WriteLine();
        }

        public void printCheck()
        {
            Console.WriteLine("Pay " + this.name + " the sum of " + this.netPay + " Dollars.");
            Console.WriteLine("Check Stub: ");
            Console.WriteLine("Employee number: " + this.ssn);
            Console.WriteLine("This is an Administrator.  Regular pay: ");
            Console.WriteLine(this.salary);
            Console.WriteLine();
        }
    }
}

/*
 * EXPECTED OUTPUT:

New Employee:

Hours: 45.45
Pay  the sum of 2748 Dollars.
Check Stub:
Employee number:
This is an hourly employee.  Hours worked: 40
Rate: 68.7    Pay: 2748

New Administrator Registration
Please enter new admin name:
Jesse
Please enter admin social security number:
666-66-6666
Please enter admin weekly salary:
2,000.00
Please enter admin Title:
Head
Please enter department:
Development
Please enter admin supervisor:
Sarah

Name: Jesse
SocSecNum: 666-66-6666
Pay: 2000
Title: Head
Department: Development
Supervisor: Sarah

Pay Jesse the sum of 2000 Dollars.
Check Stub:
Employee number: 666-66-6666
This is an Administrator.  Regular pay:
2000

 * 
 * 
 * */
