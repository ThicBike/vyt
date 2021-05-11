import javafx.application.Application;
import javafx.stage.Stage;
import javafx.scene.control.Label;
import javafx.scene.control.Button; 
import javafx.scene.layout.VBox;  //(vertical), moze byt aj HBox (horizontal)
import javafx.scene.Scene;
import javafx.scene.text.Font;
import javafx.scene.text.*;
import javafx.geometry.Pos;
import javafx.event.EventHandler;
import javafx.event.Event;     


public class ReakciaNaUdalost extends Application{
  private Label lbInfo, lbKlik;
  private Button btKlik, btStlac;
  private VBox vbox;
  private Scene scene;
  
  @Override
  public void start(Stage stage){
    lbInfo = new Label("Reaction to the event - CLICK");
    lbInfo.setFont(Font.font("Times New Roman", FontWeight.BOLD, 24));
    lbInfo.setStyle("-fx-background-color: #FF7899");
    
    
    lbKlik = new Label("Klikni na tlacidlo");
    
    btKlik = new Button("KLIK");
    btKlik.setStyle("-fx-font-weight: bold; -fx-background-radius: 20;");
    //moznost 1 vnorena trieda
    btKlik.setOnAction(new ButtonKlik());
    
    btStlac = new Button("STLAC");
    btStlac.setOnAction(new ButtonKlik());

    vbox = new VBox(10);                      
    vbox.setAlignment(Pos.CENTER);
    vbox.getChildren().add(lbInfo);
    vbox.getChildren().add(lbKlik);
    vbox.getChildren().add(btKlik);
    vbox.getChildren().add(btStlac);

    scene = new Scene(vbox, 400, 200);
    stage.setScene(scene);
    stage.show();
  }
  
  //moznost 1 vnorena trieda
  class ButtonKlik implements EventHandler{
    @Override
    public void handle(Event evt){
      Button button = (Button)evt.getSource();
      
      if(button.equals(btKlik)) lbKlik.setText("Ahoj, JavaFx");
      else lbKlik.setText("Ahoj, Java");

      
      
      /*if(lbKlik.getText().equals("Klikni na tlacidlo")){
        lbKlik.setText("Ahoj, JavaFx");
      }else lbKlik.setText("Klikni na tlacidlo");*/
    }
  }   
  
  

  
  
  
  

}
