/*
Premena jednotiek
Tibor Pelegrin;
3.A
*/

//importovanie potrebnych kniznic
import javafx.application.Application;
import javafx.stage.Stage;
import javafx.scene.Scene;
import javafx.scene.control.Label;
import javafx.scene.control.Alert;
import javafx.scene.control.Button;
import javafx.scene.control.TextField;
import javafx.scene.control.ToggleGroup;
import javafx.scene.control.RadioButton;
import javafx.scene.layout.VBox;
import javafx.scene.layout.GridPane;
import javafx.scene.layout.BorderPane;
import java.util.regex.Pattern;
import javafx.event.EventHandler;
import javafx.event.Event;
import javafx.geometry.*;



public class PrevodJednotiek extends Application{
  private Label lbHeader, lbFrom, lbTo, lbOutput;
  private TextField txtInput;
  private Button btConvert;
  private RadioButton rbtFToC, rbtCToF, rbtMToKm, rbtKmToM;
  private BorderPane borderPane;
  private VBox vBox;
  private GridPane gridPane;
  private Scene scene;
  
  @Override
  public void start(Stage stage){
    lbHeader = new Label("Prevod jednotiek");
    lbFrom = new Label("?F");
    lbTo = new Label("?C");
    rbtFToC = new RadioButton("?F -> ?C");
    rbtCToF = new RadioButton("?C -> ?F");
    rbtMToKm = new RadioButton("M -> Km");
    rbtKmToM = new RadioButton("Km -> M");
    lbOutput = new Label();
    lbOutput.setAlignment(Pos.BASELINE_RIGHT);
    txtInput = new TextField("Zadaj stupne Fahrenheita");
    txtInput.setAlignment(Pos.BASELINE_RIGHT);
    
    btConvert = new Button("Convert");
   
    final ToggleGroup group = new ToggleGroup();
    
    rbtFToC.setToggleGroup(group);
    rbtCToF.setToggleGroup(group);
    rbtMToKm.setToggleGroup(group);
    rbtKmToM.setToggleGroup(group);
    
    rbtFToC.setOnAction(new RadioButtonClick());
    rbtCToF.setOnAction(new RadioButtonClick());
    rbtMToKm.setOnAction(new RadioButtonClick());
    rbtKmToM.setOnAction(new RadioButtonClick());
    btConvert.setOnAction(new ButtonClick());
    
    
    gridPane = new GridPane();
    gridPane.add(txtInput, 0, 0, 1, 1);   
    gridPane.add(lbFrom, 1, 0, 1, 1);
    gridPane.add(lbOutput, 0, 1, 1, 1);
    gridPane.add(lbTo, 1, 1, 1, 1);
    gridPane.add(btConvert, 0, 2, 2, 1);
    gridPane.setAlignment(Pos.CENTER);
    gridPane.setHalignment(btConvert, HPos.CENTER);
  
    
    vBox = new VBox();
    vBox.getChildren().addAll(rbtFToC);
    vBox.getChildren().addAll(rbtCToF);
    vBox.getChildren().addAll(rbtMToKm);
    vBox.getChildren().addAll(rbtKmToM);
    
    
    borderPane = new BorderPane();  
    borderPane.setTop(lbHeader);
    borderPane.setLeft(vBox);
    borderPane.setCenter(gridPane);
      
    lbHeader.getStyleClass().add("nadpis");
    lbFrom.getStyleClass().add("from");
    lbTo.getStyleClass().add("to");
    lbOutput.getStyleClass().add("output");
    txtInput.getStyleClass().add("input");
    rbtFToC.getStyleClass().add("fc");
    rbtCToF.getStyleClass().add("fc");
    rbtMToKm.getStyleClass().add("mkm");
    rbtKmToM.getStyleClass().add("mkm");
      
    //vytvrosil som scenu a pridal som do nej borderPane
    scene = new Scene(borderPane);
    
    scene.getStylesheets().add("style.css");
    //vytvorenu scenu som pridal na podium
    stage.setScene(scene);
    //nastavil som nazov okna
    stage.setTitle("Premena jednotiek");
    //zrusil som moznost zmenit velkost okna
    //stage.setResizable(false);
    //zobrazenie okna
    stage.show();  
  }
  
  class ButtonClick implements EventHandler{
    @Override
    public void handle(Event evt){
      if(Pattern.matches("[-+]?[0-9]*[,]?[0-9]*", txtInput.getText())){ 
        //tu okomentujem toto hore [][][][]
        vyberAPremena();
      }else{
        //vytvoril som objekt alert druhu warning
        Alert alert = new Alert(Alert.AlertType.WARNING);
        //nastavil som titulok pre alert
        alert.setTitle("Chyba!");
        //nastavil som hlasku alertu
        alert.setContentText("Zle zadana hodnota! \nZadaj cislo!");
        //zobrazenie okna alertu
        alert.showAndWait();
      }
    }
          
    public void vyberAPremena(){
      if(rbtFToC.isSelected()){
        lbOutput.setText((String.format("%.3f", Convert.fahrenheitToCelsius(Float.parseFloat(txtInput.getText())))));
      }else if(rbtCToF.isSelected()){
        lbOutput.setText((String.format("%.3f", Convert.cesiusToFahrenheit(Float.parseFloat(txtInput.getText())))));
      }else if(rbtMToKm.isSelected()){
        lbOutput.setText((String.format("%.3f", Convert.kilometersToMiles(Float.parseFloat(txtInput.getText())))));
      }else if(rbtKmToM.isSelected()){
        lbOutput.setText((String.format("%.3f", Convert.milesToKilometers(Float.parseFloat(txtInput.getText())))));
      }else{
         //vytvoril som objekt alert druhu warning
        Alert alert = new Alert(Alert.AlertType.WARNING);
        //nastavil som titulok pre alert
        alert.setTitle("Chyba!");
        //nastavil som hlasku alertu
        alert.setContentText("Vyber mo?nos? premeny a zadaj hodnotu!");
        //zobrazenie okna alertu
        alert.showAndWait();   
    }
    }        
  }
  class RadioButtonClick implements EventHandler{
    @Override
    public void handle(Event evt){
      if(rbtFToC.isSelected()){
        lbFrom.setText("?F");
        lbTo.setText("?C");
        txtInput.setText("Zadaj stupne Fahrenheita");
      }else if(rbtCToF.isSelected()){
        lbFrom.setText("?C");
        lbTo.setText("?F");
          txtInput.setText("Zadaj stupne Celsia");
      }else if(rbtMToKm.isSelected()){
        lbFrom.setText("M");
        lbTo.setText("Km");
            txtInput.setText("Zadaj mile");
      }else if(rbtKmToM.isSelected()){
        lbFrom.setText("Km");
        lbTo.setText("M");
              txtInput.setText("Zadaj kilometre");
      }else{
         //vytvoril som objekt alert druhu warning
        Alert alert = new Alert(Alert.AlertType.WARNING);
        //nastavil som titulok pre alert
        alert.setTitle("Chyba!");
        //nastavil som hlasku alertu
        alert.setContentText("Vyber mo?nos? premeny a zadaj hodnotu!");
        //zobrazenie okna alertu
        alert.showAndWait();
      }   
    }
      
      
      
    }
   
  
        
  
      
}

