package sample;

import javafx.application.Application;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.layout.StackPane;
import javafx.stage.Stage;


import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;

public class Main extends Application  { //implements EventHandler<ActionEvent>


    public static void main(String[] args) {
        launch(args);
    }


    @Override
    public void start(Stage primaryStage) throws Exception{
        primaryStage.setTitle("Title of the Window");

        Button button = new Button();
        button.setText("Click me");
        button.setOnAction(Controller::methodTest);

        StackPane layout = new StackPane();
        layout.getChildren().add(button);

        Scene scene = new Scene(layout, 300, 250);
        primaryStage.setScene(scene);
        primaryStage.show();



    }


//    @Override
//    public void handle(ActionEvent event) {
//        if(event.getSource() == button){
//            System.out.println("klik button");
//
//        }
//        System.out.println("any");
//    }

    public void handle2(ActionEvent event) {
        System.out.println("klikkk");
    }
}
