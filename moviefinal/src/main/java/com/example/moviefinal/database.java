package com.example.moviefinal;

import java.sql.*;

public class database {

    public static Connection connectDB() {

        try{
            Class.forName("com.mysql.cj.jdbc.Driver");
            String url = "jdbc:mysql://localhost/inventory";
            Connection connection = DriverManager.getConnection("jdbc:mysql://localhost/employe","root","rooT13far");
            return connection;
        }
        catch(Exception e){
            e.printStackTrace();
        }
        return null;
    }
}