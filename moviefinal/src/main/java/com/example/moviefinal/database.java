package com.example.moviefinal;

import java.sql.Connection;
import java.sql.DriverManager;

public class database {

    public static Connection connectDB() {
        try {

            Class.forName("com.mysql.jdbc.Drive");
            Connection connect = DriverManager.getConnection("jdbc:mysql://localhost/employee2","root","rooT13far");
            System.out.println("CONNECTED");
            return connect;
        } catch (Exception e) {

            e.printStackTrace();
            return null;

        }

    }
}