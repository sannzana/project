module com.example.moviefinal {
    requires javafx.controls;
    requires javafx.fxml;
    requires java.sql;


    opens com.example.moviefinal to javafx.fxml;
    exports com.example.moviefinal;
}