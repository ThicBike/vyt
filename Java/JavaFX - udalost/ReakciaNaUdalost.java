import javafx.application.Application;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.layout.VBox;
import javafx.scene.Scene;
import javafx.stage.Stage;
import javafx.geometry.Pos;
import javafx.event.EventHandler;
import javafx.event.Event;
import javafx.scene.text.Font;
import javafx.scene.text.*;


public class ReakciaNaUdalost extends Application{
  private Button btKlik;
  private Label lbKlik, lbInfo;
  private VBox vbox;
  private Scene scene;
  
  public void start(Stage stage){
    lbInfo = new Label("Reakcia na udalost");
    lbInfo.setFont(Font.font("Times New Roman", FontWeight.BOLD, 24));
    lbInfo.setAlignment(Pos.BASELINE_CENTER);
    lbKlik = new Label("Klikni na tlacidlo");
    
    btKlik = new Button("KLIK");
    btKlik.setOnAction(new KlikBtKlik());
    
    vbox = new VBox(10);
    vbox.setAlignment(Pos.CENTER);
    vbox.getChildren().add(lbInfo);
    vbox.getChildren().add(lbKlik);
    vbox.getChildren().add(btKlik);
    
    
    scene = new Scene(vbox, 400, 200);
    stage.setScene(scene);
    stage.setTitle("Reakcia na udalost");
    stage.show(); 
  }
    
  //vnorena trieda
  class KlikBtKlik implements EventHandler{
    public void handle(Event evt){
      lbKlik.setText("Ahoj, JavaFX");
    }
  }

}

