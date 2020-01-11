using System;
using System.Data;
using System.Data.SqlClient;



namespace Assignment5
{
    internal class Program
    {
        private static void Main(string[] args)
        {
            string source = "server=(local);" +
                "integrated security=SSPI;" +
                "database = Vets";

            string selectStaff = "SELECT * FROM vt_staff";
            string selectStaffPay = "SELECT * FROM vt_staff_pay";

            SqlConnection conn = new SqlConnection(source);
            conn.Open();

            DataSet ds = new DataSet();
            CreateTables(ds);
            ds.EnforceConstraints = false;

            SqlDataAdapter da = new SqlDataAdapter();
            SqlCommand cmd = new SqlCommand("StaffSelect", conn);
            cmd.CommandType = CommandType.StoredProcedure;
            cmd.UpdatedRowSource = UpdateRowSource.None;
            da.SelectCommand = cmd;

            da.Fill(ds, "vt_staff");

            SqlDataAdapter p_da = new SqlDataAdapter();
            SqlCommand p_cmd = new SqlCommand(selectStaffPay, conn);
            cmd.CommandType = CommandType.Text;
            p_da.SelectCommand = p_cmd;

            da.Fill(ds, "vt_staff_pay");

            DumpDataSet(ds, "Initial data selected from db");

            string answer;
            Console.WriteLine("Welcome to the main Menu! \r\n");
            Console.WriteLine("Choose an option: \r\n");
            Console.WriteLine("1) Hire a Staff Member \r\n");
            Console.WriteLine("2) Remove a staff member \r\n");
            Console.WriteLine("3) Update salary of staff member \r\n");
            Console.WriteLine("Enter a digit 1, 2, or 3:  ");

            answer = Console.ReadLine();

            switch (answer)
            {
                case "1":
                    string id;
                    string name;
                    string last;
                    DateTime today = System.DateTime.Now;
                    string title;
                    string ssn;
                    string salary;

                    string payInsert = "INSERT into vt_staff_pay (stf_id, stf_ssn, stf_salary, stf_hire_date) " +
                        "VALUES (@stf_id, @stf_ssn, @stf_salary, @stf_hire_date)";

                    Console.WriteLine("Please enter new staff id: ");
                    id = Console.ReadLine();
                    Console.WriteLine("Please enter new hire's first name: ");
                    name = Console.ReadLine();
                    Console.WriteLine("Please enter new hire's last name: ");
                    last = Console.ReadLine();
                    Console.WriteLine("Please enter new hire's title: ");
                    title = Console.ReadLine();
                    Console.WriteLine("Please enter new hire's SSN: ");
                    ssn = Console.ReadLine();
                    Console.WriteLine("Please enter new hire's salary: ");
                    salary = Console.ReadLine();

                    DataRow r = ds.Tables["vt_staff"].NewRow();
                    r["stf_id"] = id;
                    r["stf_name_last"] = last;
                    r["stf_name_first"] = name;
                    r["stf_job_title"] = title;

                    DataRow p = ds.Tables["vt_staff_pay"].NewRow();
                    p["stf_id"] = id;
                    p["stf_ssn"] = ssn;
                    p["stf_salary"] = salary;
                    p["stf_hire_date"] = today;

                    // Add the row into the DataTable
                    ds.Tables["vt_staff"].Rows.Add(r);
                    ds.Tables["vt_staff_pay"].Rows.Add(p);

                    DumpDataSet(ds, "New row pending inserting into database");
                    // Set the InsertCommand property to the SqlCommand returned by GenerateInsertCommand method
                    SqlCommand aCommand = new SqlCommand("StaffInsert", conn);
                    SqlCommand pCommand = new SqlCommand(payInsert, conn);

                    aCommand.CommandType = CommandType.StoredProcedure;
                    pCommand.CommandType = CommandType.Text;

                    aCommand.Parameters.Add(new SqlParameter("@stf_id", SqlDbType.Int, 0, "stf_id"));
                    aCommand.Parameters.Add(new SqlParameter
                                            ("@stf_name_last", SqlDbType.NChar, 25, "stf_name_last"));
                    aCommand.Parameters.Add(new SqlParameter
                                               ("@stf_name_first", SqlDbType.NChar, 25, "stf_name_first"));
                    //aCommand.Parameters.Add ( new SqlParameter 
                    //                        ( "@stf_id" , SqlDbType.Int, 0 , ParameterDirection.Output ,
                    //	                    false , 0 , 0 , "stf_id" , DataRowVersion.Default , null ) ) ;
                    aCommand.Parameters.Add(new SqlParameter
                                            ("@stf_job_title", SqlDbType.NChar, 25, "stf_job_title"));
                    aCommand.UpdatedRowSource = UpdateRowSource.OutputParameters;

                    pCommand.Parameters.Add(new SqlParameter("@stf_id", SqlDbType.Int, 0, "stf_id"));
                    pCommand.Parameters.Add(new SqlParameter("@stf_ssn", SqlDbType.NChar, 9, "stf_ssn"));
                    pCommand.Parameters.Add(new SqlParameter("@stf_salary", SqlDbType.Int, 8, "stf_salary"));
                    pCommand.Parameters.Add(new SqlParameter("@stf_hire_date", SqlDbType.Date, 8, "stf_hire_date"));

                    da.InsertCommand = aCommand;
                    da.Update(ds, "vt_staff");

                    da.InsertCommand = pCommand;
                    da.Update(ds, "vt_staff_pay");

                    DumpDataSet(ds, "New row updated and new stf_id assigned by database");
                    Console.ReadLine();
                    break;

                case "2":
                    int deleteId;

                    Console.WriteLine("Enter Staff ID to delete: ");
                    deleteId = Convert.ToInt32(Console.ReadLine()); 

                    DataRow[] foundRows;
                    foundRows = ds.Tables["vt_staff"].Select("stf_id = " + deleteId);
                    DataRow row = foundRows[0];
                    int rowIndex = ds.Tables["vt_staff"].Rows.IndexOf(row);

                    DataRow rDelete = ds.Tables["vt_staff"].Rows[rowIndex];
                    
                    rDelete.Delete();
                    DumpDataSet(ds, string.Format("Deleted stf_id {0}", deleteId));
                    //Call the GenerateDeleteCommand to get the command to execute the StaffDelete stored procedure.
                    da.DeleteCommand = GenerateDeleteCommand(conn);
                    // And use the data adapter to update the table
                    da.Update(ds, "vt_staff");

                    da.DeleteCommand = GenerateDeleteCommandP(conn);
                    da.Update(ds, "vt_staff_pay");
                                       
                    break;

                case "3":
                    int updateId;
                    int updateSalary;

                    Console.WriteLine("Enter Staff ID to update: ");
                    updateId = Convert.ToInt32(Console.ReadLine());
                    Console.WriteLine("Enter new salary: ");
                    updateSalary = Convert.ToInt32(Console.ReadLine());


                    DataRow[] Rows;
                    foundRows = ds.Tables["vt_staff_pay"].Select("stf_id = " + updateId);
                    DataRow updateRow = foundRows[0];
                    int updateRowIndex = ds.Tables["vt_staff_pay"].Rows.IndexOf(updateRow);

                    DataRow rUpdate = ds.Tables["vt_staff_pay"].Rows[updateRowIndex];

                    updateRow["stf_salary"] =  updateSalary;
                    //Call DumpDataSet to view the change to the DataSet
                    DumpDataSet(ds, string.Format("Changed stf_id {0} Salary", updateId));

                    // Set the data adapters UpdateCommand
                    da.UpdateCommand = GenerateUpdateCommandP(conn);
                    // And use the data adapter to update the table
                    da.Update(ds, "vt_staff_pay");
                    break;

                default:
                    Console.WriteLine("Invalid response! Please enter a digit 1, 2, or 3: ");
                    break;
            }

            conn.Close();
        }

        private static void CreateTables(DataSet ds)
        {
            DataTable dt = new DataTable("vt_staff");
            DataTable pay = new DataTable("vt_staff_pay");

            DataColumn stf_id = new DataColumn("stf_id", typeof(int));
            stf_id.AllowDBNull = false;
            stf_id.AutoIncrement = true;
            stf_id.AutoIncrementSeed = 1;

            DataColumn stf_name_first = new DataColumn("stf_name_first", typeof(string));
            stf_name_first.AllowDBNull = false;

            DataColumn stf_name_last = new DataColumn("stf_name_last", typeof(string));
            stf_name_first.AllowDBNull = false;

            DataColumn stf_job_title = new DataColumn("stf_job_title", typeof(string));
            stf_name_first.AllowDBNull = false;

            dt.Columns.Add(stf_id);
            dt.Columns.Add(stf_name_first);
            dt.Columns.Add(stf_name_last);
            dt.Columns.Add(stf_job_title);



            DataColumn p_stf_id = new DataColumn("stf_id", typeof(int));
            p_stf_id.AllowDBNull = false;
            p_stf_id.AutoIncrement = true;
            p_stf_id.AutoIncrementSeed = 1;

            DataColumn stf_ssn = new DataColumn("stf_ssn", typeof(int));
            stf_ssn.AllowDBNull = false;

            DataColumn stf_salary = new DataColumn("stf_salary", typeof(int));
            stf_ssn.AllowDBNull = false;

            DataColumn stf_hire_date = new DataColumn("stf_hire_date", typeof(string));
            stf_hire_date.AllowDBNull = false;

            pay.Columns.Add(p_stf_id);
            pay.Columns.Add(stf_ssn);
            pay.Columns.Add(stf_salary);
            pay.Columns.Add(stf_hire_date);



            ds.Tables.Add(dt);
            ds.Tables.Add(pay);
        }

        private static void DumpDataSet(DataSet ds, string message)
        {
            Console.WriteLine(message);

            foreach (DataRow aRow in ds.Tables["vt_staff"].Rows)
            {
                Console.WriteLine("  {0,-3} {1,-50} {2}", aRow[0], aRow[1], aRow.RowState);
            }

            foreach (DataRow aRow in ds.Tables["vt_staff_pay"].Rows)
            {
                Console.WriteLine("   {0,-3} {1,-50} {2}", aRow[0], aRow[1], aRow.RowState);
            }
        }

        private static SqlCommand GenerateUpdateCommand(SqlConnection conn)
        {
            SqlCommand aCommand = new SqlCommand("StaffUpdate", conn);

            aCommand.CommandType = CommandType.StoredProcedure;
            aCommand.Parameters.Add(new SqlParameter
                                        ("@stf_id", SqlDbType.Int, 0, "cl_id"));
            aCommand.Parameters.Add(new SqlParameter
                                    ("@stf_job_title", SqlDbType.NChar, 25, "stf_job_title"));
            aCommand.UpdatedRowSource = UpdateRowSource.None;

            return aCommand;
        }

        private static SqlCommand GenerateUpdateCommandP(SqlConnection conn)
        {
            SqlCommand aCommand = new SqlCommand("StaffPayUpdate", conn);

            aCommand.CommandType = CommandType.StoredProcedure;
            aCommand.Parameters.Add(new SqlParameter
                                        ("@stf_id", SqlDbType.Int, 0, "stf_id"));
            aCommand.Parameters.Add(new SqlParameter
                                    ("@stf_salary", SqlDbType.Int, 8, "stf_salary"));
            aCommand.UpdatedRowSource = UpdateRowSource.None;

            return aCommand;
        }

        private static SqlCommand GenerateDeleteCommand(SqlConnection conn)
        {
            SqlCommand aCommand = new SqlCommand("StaffDelete", conn);

            aCommand.CommandType = CommandType.StoredProcedure;
            aCommand.Parameters.Add(new SqlParameter
                                        ("@stf_id", SqlDbType.Int, 0, "stf_id"));
            aCommand.UpdatedRowSource = UpdateRowSource.None;

            return aCommand;
        }

        private static SqlCommand GenerateDeleteCommandP(SqlConnection conn)
        {
            SqlCommand aCommand = new SqlCommand("StaffPayDelete", conn);

            aCommand.CommandType = CommandType.StoredProcedure;
            aCommand.Parameters.Add(new SqlParameter
                                        ("@stf_id", SqlDbType.Int, 0, "stf_id"));
            aCommand.UpdatedRowSource = UpdateRowSource.None;

            return aCommand;
        }

        private static SqlCommand GenerateInsertCommand(SqlConnection conn)
        {
            SqlCommand aCommand = new SqlCommand("StaffInsert", conn);

            aCommand.CommandType = CommandType.StoredProcedure;

            aCommand.Parameters.Add(new SqlParameter("@stf_id", SqlDbType.Int, 0, "stf_id"));
            aCommand.Parameters.Add(new SqlParameter
                                    ("@stf_name_last", SqlDbType.NChar, 25, "stf_name_last"));
            aCommand.Parameters.Add(new SqlParameter
                                       ("@stf_name_first", SqlDbType.NChar, 25, "stf_name_first"));
            //aCommand.Parameters.Add ( new SqlParameter 
            //                        ( "@stf_id" , SqlDbType.Int, 0 , ParameterDirection.Output ,
            //	                    false , 0 , 0 , "stf_id" , DataRowVersion.Default , null ) ) ;
            aCommand.Parameters.Add(new SqlParameter
                                    ("@stf_job_title", SqlDbType.NChar, 25, "stf_job_title"));
            aCommand.UpdatedRowSource = UpdateRowSource.OutputParameters;

            return aCommand;
        }

        private static SqlCommand GenerateInsertCommandP(SqlConnection conn)
        {
            SqlCommand aCommand = new SqlCommand("StaffPayInsert", conn);

            aCommand.CommandType = CommandType.StoredProcedure;

            aCommand.Parameters.Add(new SqlParameter("@stf_id", SqlDbType.Int, 0, "stf_id"));
            aCommand.Parameters.Add(new SqlParameter
                                    ("@stf_ssn", SqlDbType.NChar, 9, "stf_ssn"));
            aCommand.Parameters.Add(new SqlParameter
                                       ("@stf_salary", SqlDbType.Int, 8, "stf_salary"));
            //aCommand.Parameters.Add ( new SqlParameter 
            //                        ( "@stf_id" , SqlDbType.Int, 0 , ParameterDirection.Output ,
            //	                    false , 0 , 0 , "stf_id" , DataRowVersion.Default , null ) ) ;
            aCommand.Parameters.Add(new SqlParameter
                                    ("@stf_hire_date", SqlDbType.Date));
            aCommand.UpdatedRowSource = UpdateRowSource.OutputParameters;

            return aCommand;
        }



    }        
}