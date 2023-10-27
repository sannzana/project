package com.example.moviefinal;


import javafx.animation.TranslateTransition;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.*;
import javafx.scene.input.MouseEvent;
import javafx.scene.layout.AnchorPane;
import javafx.scene.text.Text;
import javafx.util.Duration;

import java.sql.*;
import java.util.ArrayList;
import java.util.List;
import java.util.Date;


public class HelloController {
    @FXML
    private Text admin;

    @FXML
    private Text admin1;

    @FXML
    private AnchorPane login_form;

    @FXML
    private Button loginbtn;

    @FXML
    private Text logtxt1;
    @FXML
    private Label regtxt;
    @FXML
    private PasswordField pass;

    @FXML
    private TextField reg_ans;

    @FXML
    private Button reg_btn;

    @FXML
    private Button reg_btn1;

    @FXML
    private Button reg_btn_1;

    @FXML
    private PasswordField reg_pass;

    @FXML
    private ComboBox<?> reg_ques;

    @FXML
    private TextField reg_user;

    @FXML
    private AnchorPane side_form;

    @FXML
    private AnchorPane sign_form;

    @FXML
    private TextField user;

    @FXML
    void handleMouseEntered(MouseEvent event) {
        loginbtn.setStyle("-fx-background-color: linear-gradient(to bottom right, #0e5163, #065e49);");

    }

    @FXML
    void handleMouseEntered_1(MouseEvent event) {
        reg_btn.setStyle("-fx-background-color: #fff;" +
                "-fx-text-fill: #000;");
    }

    @FXML
    void handleMouseEntered_2(MouseEvent event) {
        reg_btn.setStyle("-fx-background-color: linear-gradient(to bottom right, #0e5163, #065e49);");

    }


    @FXML
    void handleMouseEntered_4(MouseEvent event) {
        reg_btn_1.setStyle("-fx-background-color: #fff;" +
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
        reg_btn.setStyle("-fx-background-color: transparent; -fx-cursor: hand; -fx-text-fill: #fff;");
    }

    @FXML
    void handleMouseExited_2(MouseEvent event) {
        reg_btn.setStyle("-fx-background-color: linear-gradient(to bottom right, #246861, #098c53);" +
                "-fx-text-fill: #fff;" +
                "-fx-font-size: 14px");
    }

    @FXML
    void handleMouseExited_4(MouseEvent event) {
        reg_btn_1.setStyle("-fx-background-color: transparent; -fx-cursor: hand; -fx-text-fill: #fff;");


    }


    @FXML
    void handleMouseEntered_5(MouseEvent event) {
        reg_btn1.setStyle("-fx-background-color: linear-gradient(to bottom right, #0e5163, #065e49);");

    }

    @FXML
    void handleMouseExited_5(MouseEvent event) {
        reg_btn1.setStyle("-fx-background-color: linear-gradient(to bottom right, #246861, #098c53);" +
                "-fx-text-fill: #fff;" +
                "-fx-font-size: 14px"
        );


    }

    private Connection connect;
    private PreparedStatement prepare;
    private ResultSet result;
    private Alert alert;


    public void loginBtn() {
        if (user.getText().isEmpty() || pass.getText().isEmpty()) {
            alert = new Alert(Alert.AlertType.ERROR);
            alert.setTitle("ERROR");
            alert.setHeaderText(null);
            alert.setContentText("Please give Username/Password!");
            alert.showAndWait();

        } else {
            String selectData = "SELECT username,password FROM employee2 WHERE username= ? and password =?";
            connect = database.connectDB();

            try {
                prepare = connect.prepareStatement(selectData);
                prepare.setString(1, user.getText());
                prepare.setString(2, pass.getText());
                result = prepare.executeQuery();
                if (result.next()) {
                    getData.username=user.getText();
                    alert = new Alert(Alert.AlertType.INFORMATION);
                    alert.setTitle("CONGRATULATION");
                    alert.setHeaderText(null);
                    alert.setContentText("Login Successful!");
                    alert.showAndWait();
                } else {
                    alert = new Alert(Alert.AlertType.ERROR);
                    alert.setTitle("ERROR");
                    alert.setHeaderText(null);
                    alert.setContentText("Incorrect Username or Password");
                    alert.showAndWait();
                }


            } catch (Exception e) {
                e.printStackTrace();
            }


        }


    }

    public void registration() {
        if (reg_user.getText().isEmpty() || reg_pass.getText().isEmpty()
                || reg_ques.getSelectionModel().getSelectedItem() == null || reg_ans.getText().isEmpty()) {
            alert = new Alert(Alert.AlertType.ERROR);
            alert.setTitle("ERROR");
            alert.setHeaderText(null);
            alert.setContentText("Please fill the blank fields");
            alert.showAndWait();
        } else {
            //  System.out.println("heyyy");
            String regdata = "Insert into data2(username, password, question,answer,date)"
                    + "VALUES(?,?,?,?,?)";
            //System.out.println("heyyy");
            connect = database.connectDB();

            try {
                //check if user name is already used
                String checkUsername = "SELECT username FROM employee2 WHERE= ' "
                        + reg_user.getText() + " ' ";
                prepare = connect.prepareStatement(checkUsername);
                result = prepare.executeQuery();
                if (result.next()) {

                    alert = new Alert(Alert.AlertType.ERROR);
                    alert.setTitle("ERROR");
                    alert.setHeaderText(null);
                    alert.setContentText(reg_user.getText() + " is already used");
                    alert.showAndWait();

                } else if (reg_pass.getText().length() < 6) {
                    alert = new Alert(Alert.AlertType.ERROR);
                    alert.setTitle("ERROR");
                    alert.setHeaderText(null);
                    alert.setContentText("Password is too short");
                    alert.showAndWait();
                } else {


                    prepare = connect.prepareStatement(regdata);
                    prepare.setString(1, reg_user.getText());
                    prepare.setString(2, reg_pass.getText());
                    prepare.setString(3, (String) reg_ques.getSelectionModel().getSelectedItem());
                    prepare.setString(4, reg_ans.getText());
                    Date date = new Date();
                    java.sql.Date sqlDate = new java.sql.Date(date.getTime());
                    prepare.setString(5, String.valueOf(sqlDate));
                    prepare.executeUpdate();


                    prepare.executeUpdate();

                    alert = new Alert(Alert.AlertType.INFORMATION);
                    alert.setTitle("Information Message");
                    alert.setHeaderText(null);
                    alert.setContentText("Successfully Registered");
                    alert.showAndWait();
                    reg_user.setText("");
                    reg_pass.setText("");
                    reg_ques.getSelectionModel().clearSelection();
                    reg_ans.setText("");
                    TranslateTransition slide = new TranslateTransition();
                    slide.setNode(side_form);
                    slide.setToX(300);
                    slide.setDuration(Duration.seconds(0.1));
                    slide.setOnFinished((ActionEvent e) ->
                            {
                                reg_btn_1.setVisible(true);
                                reg_btn.setVisible(false);
                                sign_form.setVisible(true);
                                login_form.setVisible(false);

                                reqQuestion();

                            }

                    );


                    slide.play();
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
        ObservableList listdata = FXCollections.observableArrayList(listQ);
        reg_ques.setItems(listdata);

    }

    @FXML
    void handleMouseEntered_3(MouseEvent event) {


        //public void switchForm(ActionEvent event)
        {
            TranslateTransition slide = new TranslateTransition();
            if (event.getSource() == reg_btn) {
                slide.setNode(side_form);
                slide.setToX(300);
                slide.setDuration(Duration.seconds(0.1));
                slide.setOnFinished((ActionEvent e) ->
                        {
                            reg_btn_1.setVisible(true);
                            reg_btn.setVisible(false);
                            sign_form.setVisible(true);
                            login_form.setVisible(false);

                            reqQuestion();

                        }

                );


                slide.play();
            } else if (event.getSource() == reg_btn_1) {
                slide.setNode(side_form);
                slide.setToX(0);
                slide.setDuration(Duration.seconds(0.1));
                slide.setOnFinished((ActionEvent e) ->
                        {
                            reg_btn_1.setVisible(false);
                            reg_btn.setVisible(true);
                            sign_form.setVisible(false);
                            login_form.setVisible(true);

                        }

                );


                slide.play();
            }


        }
    }


    @FXML
    void handleMouseEntered_pass(MouseEvent event) {
        pass.setStyle("-fx-background-color: transparent; -fx-border-color:linear-gradient(to bottom right,#343d86,#065e49); -fx-border-width: 1.2px;");
    }

    @FXML
    void handleMouseExited_pass(MouseEvent event) {
        pass.setStyle("-fx-background-color: transparent; -fx-border-color:linear-gradient(to bottom right,#343d86,#065e49); -fx-border-width: .5px;");
    }

    @FXML
    void handleMouseEntered_txt(MouseEvent event) {
        user.setStyle("-fx-background-color: transparent; -fx-border-color:linear-gradient(to bottom right,#343d86,#065e49); -fx-border-width: 1.2px;");
    }

    @FXML
    void handleMouseExited_txt(MouseEvent event) {
        user.setStyle("-fx-background-color: transparent; -fx-border-color:linear-gradient(to bottom right,#343d86,#065e49); -fx-border-width: .5px;");

    }


}





