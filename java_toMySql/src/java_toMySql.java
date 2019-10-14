
import java.sql.*;

    /**
     * A Java MySQL SELECT statement example.
     * Demonstrates the use of a SQL SELECT statement against a
     * MySQL database, called from a Java program.
     *
     * Created by Alvin Alexander, http://alvinalexander.com
     */
    public class java_toMySql
    {

        public static void main(String[] args)
        {
            try
            {
                // create our mysql database connection
                String myDriver = "org.gjt.mm.mysql.Driver";
                String myUrl = "jdbc:mysql://coms-309-sr-5.misc.iastate.edu/sr5game?serverTimezone=America/Chicago";
                Class.forName(myDriver);
                Connection conn = DriverManager.getConnection(myUrl, "sr_5", "sr5_Pass!");

                // our SQL SELECT query.
                // if you only need a few columns, specify them by name instead of using "*"
                String query = "SELECT * FROM users";

                // create the java statement
                Statement st = conn.createStatement();

                // execute the query, and get a java resultset
                ResultSet rs = st.executeQuery(query);

                // iterate through the java resultset
                while (rs.next())
                {
                    int id = rs.getInt("id");
                    int score = rs.getInt("score");
                    int username = rs.getInt("username");

                    // print the results
                    System.out.format("%s, %s, %s\n", id, score, username);
                }
                st.close();
            }
            catch (Exception e)
            {
                System.err.println("Got an exception! ");
                System.err.println(e.getMessage());
            }
        }
    }
