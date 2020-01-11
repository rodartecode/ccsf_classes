using System;
using System.Collections.Generic;
using System.IO;

namespace WebBlogPro
{
    class Program
    {
        static void Main(string[] args)
        {
            LogReader log = new LogReader();
            log.read();
            log.reverse();
            log.firstFive();
            log.firstFiveFile();

            Console.ReadKey();
        }

        class LogReader : IDisposable
        {
            FileStream fs;
            StreamReader sr;
            StreamWriter sw;
            bool isDisposed = false;
            bool isOpen = false;

            Queue<string> strQueue = new Queue<string>();
            Stack<string> strStack = new Stack<string>();
            List<string> strList = new List<string>();

            public void read()
            {            
             
                try
                {
                    // Create an instance of StreamReader to read from a file.
                    // The using statement also closes the StreamReader.
                    using (sr = new StreamReader("c:/a/weblog.txt"))
                    {
                        string line;

                        // Read and display lines from the file until 
                        // the end of the file is reached. 
                        while ((line = sr.ReadLine()) != null)
                        {
                            strQueue.Enqueue(line);
                            strList.Add(line);
                        }
                        
                    }
                }
                catch (Exception e)
                {
                    // Let the user know what went wrong.
                    Console.WriteLine("The file could not be read:");
                    Console.WriteLine(e.Message);
                }
                finally
                {
                    sr.Close();
                }
            }

            public void reverse()
            {
                using (sw = new StreamWriter("c:/a/result.txt"))
                {
                    foreach(string line in strQueue)
                    {
                        strStack.Push(line);
                    }
                    foreach(string line in strStack)
                    {
                        sw.WriteLine(line);
                    }
                }

                sw.Close();
            }

            public void firstFive()
            {
                Console.WriteLine("First 5 from COLLECTION");
                Console.WriteLine();

                for (int i = 0; i < 5; i++)
                {
                    Console.WriteLine(strList[i]);
                }

                Console.WriteLine();
            }

            public void firstFiveFile()
            {
                try
                {
                    // Create an instance of StreamReader to read from a file.
                    // The using statement also closes the StreamReader.
                    using (sr = new StreamReader("c:/a/result.txt"))
                    {
                        string line;
                        Console.WriteLine("Reading 5 from RESULT.txt");
                        Console.WriteLine();

                        // Read and display lines from the file until 
                        // the end of the file is reached. 
                        for (int i = 0; i < 5; i++)
                        {
                            if((line = sr.ReadLine()) != null)
                            {
                                Console.WriteLine(line);
                            }
                        }

                        Console.WriteLine();
                    }
                }
                catch (Exception e)
                {
                    // Let the user know what went wrong.
                    Console.WriteLine("The file could not be read:");
                    Console.WriteLine(e.Message);
                }
                finally
                {
                    sr.Close();
                }                
            }

            public void Dispose()
            {
                if (isDisposed)
                    return;

                isDisposed = true;
                isOpen = false;
                if (fs != null)
                {
                    fs.Close();
                    fs = null;
                }
            }
        }
    }
}

/*
 * EXPECTED OUTPUT:
 * 
 * 
First 5 from COLLECTION

172.138.80.174 - - [05/Aug/2001:21:06:27 -0300] "GET /~csc226 HTTP/1.0" 301 303 "http://www.goto.com/d/search/?Keywords=stringVar+%2B+savitch&view=2+80+0&did=" "Mozilla/4.61 [en] (Win98; I)"
172.138.80.174 - - [05/Aug/2001:21:06:28 -0300] "GET /~csc226/ HTTP/1.0" 200 3387 "http://www.goto.com/d/search/?Keywords=stringVar+%2B+savitch&view=2+80+0&did=" "Mozilla/4.61 [en] (Win98; I)"
172.138.80.174 - - [05/Aug/2001:21:06:37 -0300] "GET /~csc226/class HTTP/1.0" 301 309 "http://cs.stmarys.ca/~csc226/" "Mozilla/4.61 [en] (Win98; I)"
172.138.80.174 - - [05/Aug/2001:21:06:37 -0300] "GET /~csc226/class/ HTTP/1.0" 200 2777 "http://cs.stmarys.ca/~csc226/" "Mozilla/4.61 [en] (Win98; I)"
172.138.80.174 - - [05/Aug/2001:21:06:49 -0300] "GET /~csc226/ HTTP/1.0" 200 3387 "http://www.goto.com/d/search/?Keywords=stringVar+%2B+savitch&view=2+80+0&did=" "Mozilla/4.61 [en] (Win98; I)"

Reading 5 from RESULT.txt

140.184.39.111 - - [11/Sep/2001:12:02:53 -0300] "GET /~csc226/class HTTP/1.0" 301 309 "http://cs.stmarys.ca/~csc226/" "Mozilla/4.77 [en] (Windows NT 5.0; U)"
140.184.39.110 - - [11/Sep/2001:12:02:50 -0300] "GET /~csc226/class/ HTTP/1.0" 200 2065 "http://cs.stmarys.ca/~csc226/" "Mozilla/4.77 [en] (Windows NT 5.0; U)"
140.184.39.110 - - [11/Sep/2001:12:02:50 -0300] "GET /~csc226/class HTTP/1.0" 301 309 "http://cs.stmarys.ca/~csc226/" "Mozilla/4.77 [en] (Windows NT 5.0; U)"
140.184.38.122 - - [11/Sep/2001:12:02:44 -0300] "GET /~csc226/class/week-00/thursday.doc HTTP/1.0" 200 22528 "http://cs.stmarys.ca/~csc226/class/week-00/" "Mozilla/4.77 [en] (Windows NT 5.0; U)"
140.184.38.122 - - [11/Sep/2001:12:02:43 -0300] "GET /~csc226/class/week-00/ HTTP/1.0" 200 818 "http://cs.stmarys.ca/~csc226/class/" "Mozilla/4.77 [en] (Windows NT 5.0; U)"
 * 
 * 
 * 
 * */
