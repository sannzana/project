package com.example.moviefinal;


import javafx.animation.TranslateTransition;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.*;
import javafx.scene.input.MouseEvent;
import javafx.scene.layout.AnchorPane;
import javafx.scene.text.Text;
import javafx.stage.Stage;
import javafx.util.Duration;

import java.sql.*;
import java.util.ArrayList;
import java.util.List;
import java.util.Date;


public class HelloController {
    @FXML
    private Label login;

    @FXML
    private Button loginbtn;

    @FXML
    private AnchorPane si_loginForm;

    @FXML
    private PasswordField si_password;

    @FXML
    private TextField si_username;

    @FXML
    private Button side_CreateBtn;


    @FXML
    private TextField su_username;

    @FXML
    private Button side_alreadyHave;

    @FXML
    private AnchorPane side_form;

    @FXML
    private TextField su_answer;

    @FXML
    private PasswordField su_password;

    @FXML
    private ComboBox<?> su_question;

    @FXML
    private Button su_signupBtn;

    @FXML
    private AnchorPane su_signupForm;
    @FXML
    void handleMouseEntered(MouseEvent event) {
        loginbtn.setStyle("-fx-background-color: linear-gradient(to bottom right, #0e5163, #065e49);");

    }

    @FXML
    void handleMouseEntered_1(MouseEvent event) {
        side_CreateBtn.setStyle("-fx-background-color: #fff;" +
                "-fx-text-fill: #000;");
    }

    @FXML
    void handleMouseEntered_2(MouseEvent event) {
       side_CreateBtn.setStyle("-fx-background-color: linear-gradient(to bottom right, #0e5163, #065e49);");

    }


    @FXML
    void handleMouseEntered_4(MouseEvent event) {
       side_alreadyHave.setStyle("-fx-background-color: #fff;" +
                "-fx-text-fill: #000;");

    }

    @FXML
    void handleMouseExited(MouseEvent event) {
        loginbtn.setStyle("-fx-background-color: linear-gradient(to bottom right, #246861, #098c53);" +
                "-fx-text-fill: #fff;" +
                "-fx-font-size: 14px"
        );

    }

    @FXML
    void handleMouseExited_1(MouseEvent event) {
        side_CreateBtn.setStyle("-fx-background-color: transparent; -fx-cursor: hand; -fx-text-fill: #fff;");
    }

    @FXML
    void handleMouseExited_2(MouseEvent event) {
       side_CreateBtn.setStyle("-fx-background-color: linear-gradient(to bottom right, #246861, #098c53);" +
                "-fx-text-fill: #fff;" +
                "-fx-font-size: 14px");
    }

    @FXML
    void handleMouseExited_4(MouseEvent event) {
       side_alreadyHave.setStyle("-fx-background-color: transparent; -fx-cursor: hand; -fx-text-fill: #fff;");


    }


    @FXML
    void handleMouseEntered_5(MouseEvent event) {
        su_signupBtn.setStyle("-fx-background-color: linear-gradient(to bottom right, #0e5163, #065e49);");

    }

    @FXML
    void handleMouseExited_5(MouseEvent event) {
        su_signupBtn.setStyle("-fx-background-color: linear-gradient(to bottom right, #246861, #098c53);" +
                "-fx-text-fill: #fff;" +
                "-fx-font-size: 14px"
        );


    }

    private Connection connect;
    private PreparedStatement prepare;
    private ResultSet result;
    private Alert alert;


    public void loginBtn() {

        if (si_username.getText().isEmpty() || si_password.getText().isEmpty()) {
            alert = new Alert(Alert.AlertType.ERROR);
            alert.setTitle("Error Message");
            alert.setHeaderText(null);
            alert.setContentText("Enter username/password");
            alert.showAndWait();
        } else {

            String selctData = "SELECT username, password FROM takedata2 WHERE username = ? and password = ?";

            connect = database.connectDB();

            try {

                prepare = connect.prepareStatement(selctData);
                prepare.setString(1, si_username.getText());
                prepare.setString(2, si_password.getText());

                result = prepare.executeQuery();
                // IF SUCCESSFULLY LOGIN, THEN PROCEED TO ANOTHER FORM WHICH IS OUR MAIN FORM
                if (result.next()) {
                    // TO GET THE USERNAME THAT USER USED
                    getData.username = si_username.getText();

                    alert = new Alert(Alert.AlertType.INFORMATION);
                    alert.setTitle("Information Message");
                    alert.setHeaderText(null);
                    alert.setContentText("Successfully Login!");
                    alert.showAndWait();

                    // LINK YOUR MAIN FORM
                    Parent root = FXMLLoader.load(getClass().getResource("dash.fxml"));

                    Stage stage = new Stage();
                    Scene scene = new Scene(root);

                    stage.setTitle("Cafe Shop Management System");
                    stage.setMinWidth(1100);
                    stage.setMinHeight(600);

                    stage.setScene(scene);
                    stage.show();

                    loginbtn.getScene().getWindow().hide();

                } else { // IF NOT, THEN THE ERROR MESSAGE WILL APPEAR
                    alert = new Alert(Alert.AlertType.ERROR);
                    alert.setTitle("Error Message");
                    alert.setHeaderText(null);
                    alert.setContentText("Incorrect Username/Password");
                    alert.showAndWait();
                }

            } catch (Exception e) {
                e.printStackTrace();
            }

        }

    }

    public void regBtn() {

        if (su_username.getText().isEmpty() || su_password.getText().isEmpty()
                || su_question.getSelectionModel().getSelectedItem() == null
                || su_answer.getText().isEmpty()) {
            alert = new Alert(Alert.AlertType.ERROR);
            alert.setTitle("Error Message");
            alert.setHeaderText(null);
            alert.setContentText("Please fill all blank fields");
            alert.showAndWait();
        } else {

            String regData = "INSERT INTO takedata2 (username, password, question, answer, date) "
                    + "VALUES(?,?,?,?,?)";
            connect = database.connectDB();

            try {
                // CHECK IF THE USERNAME IS ALREADY RECORDED
                String checkUsername = "SELECT username FROM takedata2 WHERE username = '"
                        + su_username.getText() + "'";

                prepare = connect.prepareStatement(checkUsername);
                result = prepare.executeQuery();

                if (result.next()) {
                    alert = new Alert(Alert.AlertType.ERROR);
                    alert.setTitle("Error Message");
                    alert.setHeaderText(null);
                    alert.setContentText(su_username.getText() + " is already taken");
                    alert.showAndWait();
                } else if (su_password.getText().length() < 8) {
                    alert = new Alert(Alert.AlertType.ERROR);
                    alert.setTitle("Error Message");
                    alert.setHeaderText(null);
                    alert.setContentText("Invalid Password, atleast 8 characters are needed");
                    alert.showAndWait();
                } else {
                    prepare = connect.prepareStatement(regData);
                    prepare.setString(1, su_username.getText());
                    prepare.setString(2, su_password.getText());
                    prepare.setString(3, (String) su_question.getSelectionModel().getSelectedItem());
                    prepare.setString(4, su_answer.getText());

                    Date date = new Date();
                    java.sql.Date sqlDate = new java.sql.Date(date.getTime());
                    prepare.setString(5, String.valueOf(sqlDate));
                   prepare.executeUpdate();







                    alert = new Alert(Alert.AlertType.INFORMATION);
                    alert.setTitle("Information Message");
                    alert.setHeaderText(null);
                    alert.setContentText("Successfully registered Account!");
                    alert.showAndWait();

                    su_username.setText("");
                    su_password.setText("");
                    su_question.getSelectionModel().clearSelection();
                    su_answer.setText("");

                    TranslateTransition slider = new TranslateTransition();

                    slider.setNode(side_form);
                    slider.setToX(0);
                    slider.setDuration(Duration.seconds(.1));

                    slider.setOnFinished((ActionEvent e) -> {
                        side_alreadyHave.setVisible(false);
                        side_CreateBtn.setVisible(true);
                        su_signupForm.setVisible(false);
                        si_loginForm.setVisible(true);
                    });

                    slider.play();
                }

            } catch (Exception e) {
                e.printStackTrace();
            }
        }

    }


    private String[] questionlist = {"What's your favourite color?", "What's your favourite food?", "What's your pet's name", "Choose a number from 1 to 10", "What's your birth of date?"};

    public void reqQuestion() {
        List<String> listQ = new ArrayList<>();

        for (String data : questionlist) {
            listQ.add(data);
        }

        ObservableList listData = FXCollections.observableArrayList(listQ);
        su_question.setItems(listData);
    }


    @FXML
    void handleMouseEntered_3(MouseEvent event) {


        //public void switchForm(ActionEvent event)
        {
            TranslateTransition slide = new TranslateTransition();
            if (event.getSource() == side_CreateBtn) {
                slide.setNode(side_form);
                slide.setToX(300);
                slide.setDuration(Duration.seconds(0.1));
                slide.setOnFinished((ActionEvent e) ->
                        {
                            side_alreadyHave.setVisible(true);
                            side_CreateBtn.setVisible(false);
                            su_signupForm.setVisible(true);
                           si_loginForm.setVisible(false);

                            reqQuestion();

                        }

                );


                slide.play();
            } else if (event.getSource() == side_alreadyHave) {
                slide.setNode(side_form);
                slide.setToX(0);
                slide.setDuration(Duration.seconds(0.1));
                slide.setOnFinished((ActionEvent e) ->
                        {
                            side_alreadyHave.setVisible(false);
                            side_CreateBtn.setVisible(true);
                           su_signupForm.setVisible(false);
                            si_loginForm.setVisible(true);

                        }

                );


                slide.play();
            }


        }
    }


    @FXML
    void handleMouseEntered_pass(MouseEvent event) {
        si_password.setStyle("-fx-background-color: transparent; -fx-border-color:linear-gradient(to bottom right,#343d86,#065e49); -fx-border-width: 1.2px;");
    }

    @FXML
    void handleMouseExited_pass(MouseEvent event) {
       si_password.setStyle("-fx-background-color: transparent; -fx-border-color:linear-gradient(to bottom right,#343d86,#065e49); -fx-border-width: .5px;");
    }

    @FXML
    void handleMouseEntered_txt(MouseEvent event) {
       si_username.setStyle("-fx-background-color: transparent; -fx-border-color:linear-gradient(to bottom right,#343d86,#065e49); -fx-border-width: 1.2px;");
    }

    @FXML
    void handleMouseExited_txt(MouseEvent event) {
       si_username.setStyle("-fx-background-color: transparent; -fx-border-color:linear-gradient(to bottom right,#343d86,#065e49); -fx-border-width: .5px;");

    }


}