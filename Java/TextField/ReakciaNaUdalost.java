/*
Reakcia na udalost TextField
Tibor Pelegrin;
3.A
*/

//importovnie kniznic
import javafx.application.Application;
import javafx.stage.Stage;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;
import javafx.scene.control.Button;
import javafx.scene.Scene;
import javafx.scene.layout.VBox;
import javafx.scene.text.Font;
import javafx.scene.text.*;
import javafx.geometry.Pos;
import javafx.event.EventHandler;
import javafx.event.Event;

public class ReakciaNaUdalost extends Application{
  //datove polozky
  private Label lbHeading, lbInfo;
  private TextField txtInput;
  private Button btKlik;
  private VBox vbox;
  private Scene scene;
  
  public void start(Stage stage){
    lbHeading = new Label("Reakcia na udalost");
    
    lbHeading.setStyle("-fx-font-weight: bold; -fx-font-size: 18px;");
    lbHeading.setAlignment(Pos.CENTER); //vycentrovanie
    
    lbInfo = new Label("Klikni na tlacidlo");
    lbInfo.setAlignment(Pos.CENTER);  //vycentrovanie
    
    txtInput = new TextField("Zadaj text");
    txtInput.setMaxWidth(120);       //nastavil som maximalnu sirku TextFieldu
    txtInput.setAlignment(Pos.CENTER); //vycentrovanie    
    
    btKlik = new Button("KLIK");
    btKlik.setStyle("-fx-alignment: center;");
    btKlik.setOnAction(new ButtonKlik()); //po kliknuti na button sa zavola trieda ButtonKlik
    
    vbox = new VBox(10);
    vbox.setAlignment(Pos.CENTER);
    vbox.getChildren().addAll(lbHeading, txtInput, lbInfo, btKlik); //pridavanie elementov naraz do vboxu
    
    scene = new Scene(vbox, 400, 200);
    stage.setTitle("Reakcia na udalost"); 
    stage.setScene(scene); //nastavenie sceny
    stage.show(); //spustenie sceny
    
  }
  
  //vnorena trieda
  class ButtonKlik implements EventHandler{
    @Override
    public void handle(Event evt){
      lbInfo.setText(txtInput.getText()); //po spusteni sa do lbInfo vlozi text z TextFieldu
    }
  } 
}

