package com.example.moviefinal;

import javafx.application.Application;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.event.ActionEvent;
import javafx.event.Event;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.fxml.Initializable;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.*;
import javafx.scene.control.cell.PropertyValueFactory;
import javafx.scene.image.ImageView;
import javafx.scene.input.MouseEvent;
import javafx.scene.layout.AnchorPane;
import javafx.stage.Stage;
import javafx.stage.StageStyle;

import java.net.URL;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.Statement;
import java.util.ResourceBundle;

import static com.example.moviefinal.getData.username;

public class dashboard  implements Initializable {

    @FXML
    private Button addMovie_btn;

    @FXML
    private Button addMovie_clearBtn;

    @FXML
    private TableColumn<moviesData,String> addMovie_col_duration;

    @FXML
    private TableColumn<moviesData,String> addMovie_col_genre;

    @FXML
    private TableColumn<moviesData,String> addMovie_col_movieTitle;

    @FXML
    private TableColumn<moviesData,String> addMovie_col_publishedDate;

    @FXML
    private TextField addMovie_date;

    @FXML
    private Button addMovie_deleteBtn;

    @FXML
    private TextField addMovie_duration;

    @FXML
    private AnchorPane addMovie_form;

    @FXML
    private TextField addMovie_genre;

    @FXML
    private ImageView addMovie_imageview;

    @FXML
    private Button addMovie_import;

    @FXML
    private Button addMovie_insertBtn;

    @FXML
    private TextField addMovie_search;

    @FXML
    private TableView<moviesData> addMovie_tableView;

    @FXML
    private TextField addMovie_title;

    @FXML
    private Button addMovie_updateBtn;

    @FXML
    private Label admin;

    @FXML
    private Label availableMovie_NormalClass_price;

    @FXML
    private Spinner<?> availableMovie_NormalClass_quantity;

    @FXML
    private Label availableMovie_SpecialClass_pricr;

    @FXML
    private Spinner<?> availableMovie_SpecialClass_quantity;

    @FXML
    private Button availableMovie_btn;

    @FXML
    private Button availableMovie_buyBtn;

    @FXML
    private Button availableMovie_clearBtn;

    @FXML
    private TableColumn<?, ?> availableMovie_col_date;

    @FXML
    private TableColumn<?, ?> availableMovie_col_genre;

    @FXML
    private TableColumn<?, ?> availableMovie_col_movieTitle;

    @FXML
    private TextField availableMovie_date;

    @FXML
    private AnchorPane availableMovie_form;

    @FXML
    private TextField availableMovie_genre;

    @FXML
    private ImageView availableMovie_imageView;

    @FXML
    private TextField availableMovie_movieTitle;

    @FXML
    private Button availableMovie_receiptBtn;

    @FXML
    private Button availableMovie_selectMovie_btn;

    @FXML
    private TableView<?> availableMovie_tableView;

    @FXML
    private Label availableMovie_title;

    @FXML
    private Button close;

    @FXML
    private Label customer_MovieTitle;

    @FXML
    private Button customer_btn;

    @FXML
    private Button customer_clearBtn;

    @FXML
    private TableColumn<?, ?> customer_col_date;

    @FXML
    private TableColumn<?, ?> customer_col_genre;

    @FXML
    private TableColumn<?, ?> customer_col_movieTitle;

    @FXML
    private TableColumn<?, ?> customer_col_ticketNum;

    @FXML
    private TableColumn<?, ?> customer_col_time;

    @FXML
    private Label customer_date;

    @FXML
    private Button customer_deleteBtn;

    @FXML
    private AnchorPane customer_form;

    @FXML
    private Label customer_genre;

    @FXML
    private TextField customer_search;

    @FXML
    private Label customer_ticketNumber;

    @FXML
    private Label customer_time;

    @FXML
    private AnchorPane dashboard_availableMovies;

    @FXML
    private Button dashboard_btn;

    @FXML
    private AnchorPane dashboard_form;

    @FXML
    private AnchorPane dashboard_totalEarnToday;

    @FXML
    private AnchorPane dashboard_totalSold;

    @FXML
    private AnchorPane ediScreening_form;

    @FXML
    private Button editScreen_btn;

    @FXML
    private TableColumn<?, ?> editScreening_col_current;

    @FXML
    private TableColumn<?, ?> editScreening_col_duration;

    @FXML
    private TableColumn<?, ?> editScreening_col_genre;

    @FXML
    private TableColumn<?, ?> editScreening_col_movieTitle;

    @FXML
    private ComboBox<?> editScreening_current;

    @FXML
    private Button editScreening_deleteBtn;

    @FXML
    private ImageView editScreening_imageView;

    @FXML
    private TextField editScreening_search;

    @FXML
    private TableView<?> editScreening_tableView;

    @FXML
    private Label editScreening_title;

    @FXML
    private Button editScreening_updateBtn;

    @FXML
    private Button minimize;

    @FXML
    private Button signout_btn;

    @FXML
    private AnchorPane topForm;

    @FXML
    private AnchorPane username_form;



    @FXML
    void handleMouseEntered_1(MouseEvent event) {
        addMovie_btn.setStyle("-fx-background-color: #fff;" +
                "-fx-text-fill: #000;-fx-font-size: 14px;");
    }

    @FXML
    void handleMouseExit_1(MouseEvent event) {
        addMovie_btn.setStyle("-fx-background-color: TRANSPARENT; -fx-text-fill: #fff;-fx-alignment: CENTER_LEFT;");

    }
    @FXML
    void handleMouseEntered_2(MouseEvent event) {
        availableMovie_btn.setStyle("-fx-background-color: #fff;" +
                "-fx-text-fill: #000;-fx-font-size: 14px");
    }

    @FXML
    void handleMouseExit_2(MouseEvent event) {
        availableMovie_btn.setStyle("-fx-background-color: TRANSPARENT; -fx-text-fill: #fff;-fx-alignment: CENTER_LEFT;");

    }
    @FXML
    void handleMouseEntered_3(MouseEvent event) {
        customer_btn.setStyle("-fx-background-color: #fff;" +
                "-fx-text-fill: #000;-fx-font-size: 14px");
    }

    @FXML
    void handleMouseExit_3(MouseEvent event) {
        customer_btn.setStyle("-fx-background-color: TRANSPARENT; -fx-text-fill: #fff;-fx-alignment: CENTER_LEFT;");

    }
    @FXML
    void handleMouseEntered_4(MouseEvent event) {
        dashboard_btn.setStyle("-fx-background-color: #fff;" +
                "-fx-text-fill: #000;-fx-font-size: 14px");
    }

    @FXML
    void handleMouseExit_4(MouseEvent event) {
        dashboard_btn.setStyle("-fx-background-color: TRANSPARENT; -fx-text-fill: #fff;-fx-alignment: CENTER_LEFT;");

    }
    @FXML
    void handleMouseEntered_5(MouseEvent event) {
        editScreen_btn.setStyle("-fx-background-color: #fff;" +
                "-fx-text-fill: #000;-fx-font-size: 14px");
    }

    @FXML
    void handleMouseExit_5(MouseEvent event) {
        editScreen_btn.setStyle("-fx-background-color: TRANSPARENT; -fx-text-fill: #fff;-fx-alignment: CENTER_LEFT;");

    }


    @FXML
    void handleMouseEntered_6(MouseEvent event) {
        signout_btn.setStyle("-fx-background-color: #fff;" +
                "-fx-text-fill: #000;-fx-font-size: 14px");
    }

    @FXML
    void handleMouseExit_6(MouseEvent event) {
        signout_btn.setStyle("-fx-background-color: TRANSPARENT; -fx-text-fill: #fff;-fx-alignment: CENTER_LEFT;");

    }
    @FXML
    void handleMouseEntered_7(MouseEvent event) {
       close.setStyle("-fx-background-color: #ea1111;" +
                "-fx-font-size: 14px ;-fx-text-fill: #fff");
    }

    @FXML
    void handleMouseExit_7(MouseEvent event) {
       close.setStyle("-fx-background-color: transparent ;-fx-text-fill: #000");

    }
    @FXML
    void handleMouseEntered_8(MouseEvent event) {
       minimize.setStyle("-fx-background-color: #ea1111;" +
                "-fx-font-size: 14px; -fx-text-fill: #fff");
    }

    @FXML
    void handleMouseExit_8(MouseEvent event) {
        minimize.setStyle("-fx-background-color: transparent ;-fx-text-fill: #000");

    }

//public String c="helllo" username at the place of c;
  public void displayUsername()
  {
    admin.setText(getData.c);

  }

  public void switchForm(ActionEvent event) {
      if (event.getSource() == dashboard_btn) {
          dashboard_form.setVisible(true);
          addMovie_form.setVisible(false);
          availableMovie_form.setVisible(false)
          ;
          ediScreening_form.setVisible(false);
          customer_form.setVisible(false);

      } else if (event.getSource() == addMovie_btn) {
          dashboard_form.setVisible(false);
          addMovie_form.setVisible(true);
          availableMovie_form.setVisible(false)
          ;
          ediScreening_form.setVisible(false);
          customer_form.setVisible(false);


      } else if (event.getSource() == availableMovie_btn) {
          dashboard_form.setVisible(false);
          addMovie_form.setVisible(false);
          availableMovie_form.setVisible(true)
          ;
          ediScreening_form.setVisible(false);
          customer_form.setVisible(false);

      } else if (event.getSource() == editScreen_btn) {
          dashboard_form.setVisible(false);
          addMovie_form.setVisible(false);
          availableMovie_form.setVisible(false)
          ;
          ediScreening_form.setVisible(true);
          customer_form.setVisible(false);


      } else if (event.getSource() == customer_btn) {
          dashboard_form.setVisible(false);
          addMovie_form.setVisible(false);
          availableMovie_form.setVisible(false)
          ;
          ediScreening_form.setVisible(false);
          customer_form.setVisible(true);


      }
  }

  private double x=0;
    private double y=0;

//database tools
   private PreparedStatement prepare;
   private Statement statement;
   private ResultSet result;
    private Connection connect;

    public ObservableList<moviesData> addMoviesList()
    { ObservableList<moviesData>listData= FXCollections.observableArrayList();
        String sql="SELECT * FROM NAME";
        connect=database.connectDB();
        try {
            prepare = connect.prepareStatement(sql);
            result = prepare.executeQuery();
            moviesData movD;
            while (result.next()) {
                movD = new moviesData(result.getString("movieTitle"), result.getString("genre")
                        , result.getString("duration"), result.getString("image"), result.getDate("date"));

                listData.add(movD);
            }
        } catch(Exception e){e.printStackTrace();}
        return listData;
    }

    private ObservableList<moviesData>listAddMovies;
    public void showAddMoviesList()
    {
        listAddMovies=addMoviesList();

        addMovie_col_movieTitle.setCellValueFactory(new PropertyValueFactory<>("title"));
        addMovie_col_genre.setCellValueFactory(new PropertyValueFactory<>("genre"));
        addMovie_col_duration.setCellValueFactory(new PropertyValueFactory<>("duration"));
        addMovie_col_publishedDate.setCellValueFactory(new PropertyValueFactory<>("date"));
addMovie_tableView.setItems(listAddMovies);


    }


    public void selectAddMoviesList()
    {
        moviesData movD=addMovie_tableView.getSelectionModel().getSelectedItem();
        int num=addMovie_tableView.getSelectionModel().getSelectedIndex();


        if((num -1)<-1){return;}



    }




public void logout()
      {
signout_btn.getScene().getWindow().hide();
try{
Parent root= FXMLLoader.load(getClass().getResource("hello-view.fxml"));
Stage stage=new Stage();
Scene scene=new Scene(root);

root.setOnMousePressed((MouseEvent event)->{
    x=event.getSceneX();
    y=event.getSceneY();

    });
root.setOnMouseDragged((MouseEvent event)->{
    stage.setX(event.getScreenX() - x);
    stage.setY(event.getScreenY() - y);


});



stage.initStyle(StageStyle.TRANSPARENT);
stage.setScene(scene);
stage.show();

  }
     catch(Exception e){e.printStackTrace();}
      }


public void close()
{
    System.exit(0);


}
public void minimize()
{
    Stage stage=(Stage)topForm.getScene().getWindow();
    stage.setIconified(true);

}
    @Override
    public void initialize(URL url, ResourceBundle resourceBundle) {
displayUsername();
showAddMoviesList();
    }
}
