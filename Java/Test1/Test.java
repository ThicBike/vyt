import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.layout.Pane;
import javafx.stage.Stage;
import javafx.scene.control.Label;
import javafx.scene.control.Button;
import javafx.scene.Scene;
import javafx.scene.layout.VBox;
import javafx.scene.text.*;
import javafx.geometry.Pos;

import javafx.event.Event;
import javafx.event.EventHandler;
//import javafx.scene.*;


public class Test extends Application {
  private Scene scene;
  private Label lbKlik, lbInfo;
  private Button btKlik;
  private VBox vbox;
  
  public void initGUI(Stage stage){
    lbInfo = new Label("Reakcia na udalost");
    lbInfo.setFont(Font.font("Times New Roman", FontWeight.BOLD, 24));
    
    lbKlik = new Label("Klikni na tlacidlo");
    
    btKlik = new Button("KLIK");
    btKlik.setOnAction(new KlikBtKlik());
    
    vbox = new VBox(10);
    vbox.getChildren().add(lbInfo);
    vbox.getChildren().add(lbKlik);
    vbox.getChildren().add(btKlik);
    vbox.setAlignment(Pos.BASELINE_CENTER);
   
    
    scene = new Scene(vbox, 400, 200);
    stage.setScene(scene);
    stage.setTitle("Moja Prva FX Apka");
    
    stage.show();       
  }
    
  public void start(Stage stage){
    initGUI(stage);
         
  }
  
  class KlikBtKlik implements EventHandler{
    public void handle(Event event){
      lbKlik.setText("AHOJ JAVA a EVENT");     
    }
  }  

  public static void main(String arg){
  //volám statickú metódu launch
    Application.launch(arg);
  }
}
