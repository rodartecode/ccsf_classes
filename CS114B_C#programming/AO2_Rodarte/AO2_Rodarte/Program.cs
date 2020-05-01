using System;

public class Basic
{
    static int Id = 2321;

    public static void ShowInfo()
    {
        Console.WriteLine("This is Basic class");
        Console.WriteLine("The Id is: {0}", Id);
    }
}

public class StaticMethod
{
    static void Main()
    {
        Basic.ShowInfo();
    }
}