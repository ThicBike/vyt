import javafx.application.Application;
import javafx.stage.Stage;
import javafx.scene.control.Label;
import javafx.scene.control.Button; 
import javafx.scene.control.TextField;
import javafx.scene.layout.GridPane; 
import javafx.geometry.HPos;
import javafx.scene.Scene;
import javafx.scene.text.Font;
import javafx.scene.text.*;
import javafx.geometry.Pos;
import javafx.event.EventHandler;
import javafx.event.Event;     
import javafx.geometry.Insets;
import java.io.InputStream;
import javafx.scene.image.*;
import java.util.regex.Pattern;
import java.lang.Float;
import java.lang.String;
import javafx.scene.control.Alert; 

public class FahrenheitToCelsius_01 extends Application{
  private Label lbFahrenheit, lbCelsius, lbOutput;
  private TextField txtInput;
  private Button btConvert;
  private GridPane gridPane;
  private Scene scene;
  
  @Override
  public void start(Stage stage){
    txtInput = new TextField("Zadaj stupne Fahrenheita");
    txtInput.setMinWidth(150);
    txtInput.setAlignment(Pos.TOP_RIGHT);
    
    lbFahrenheit = new Label("°F");
    lbFahrenheit.setStyle("-fx-font-family: 'Segoe Print'; -fx-font-weight: bold; -fx-font-size: 14px;");
    
    lbOutput = new Label();
    lbOutput.setStyle("-fx-background-color: yellow;");
    lbOutput.setAlignment(Pos.TOP_RIGHT);
    lbOutput.setMinWidth(150);
    
    lbCelsius = new Label("°C");
    lbCelsius.setStyle("-fx-font-family: 'Segoe Print'; -fx-font-weight: bold; -fx-font-size: 14px;");
    
    btConvert = new Button("°F to °C");
    btConvert.setStyle("-fx-font-family: 'Segoe Print'; -fx-font-weight: bold; -fx-font-size: 14px;");
    btConvert.setOnAction(new ButtonClick());

    InputStream iconStream = getClass().getResourceAsStream("thermometer.png");
    
    Image icon = new Image(iconStream);
    stage.getIcons().add(icon);
    
    gridPane = new GridPane();
    gridPane.setVgap(10);
    gridPane.setHgap(10);
    gridPane.setAlignment(Pos.CENTER);
    gridPane.setHalignment(btConvert, HPos.CENTER);
    
    
    gridPane.setMargin(txtInput, new Insets(15, 0, 0, 15));
    gridPane.setMargin(lbFahrenheit, new Insets(15, 15, 0, 0));
    gridPane.setMargin(lbOutput, new Insets(0, 0, 0, 15));
    gridPane.setMargin(lbCelsius, new Insets(0, 15, 0, 0));
    gridPane.setMargin(btConvert, new Insets(0, 0, 15, 0));
      
    gridPane.add(txtInput, 0, 0, 1, 1);   
    gridPane.add(lbFahrenheit, 1, 0, 1, 1);
    gridPane.add(lbOutput, 0, 1, 1, 1);
    gridPane.add(lbCelsius, 1, 1, 1, 1);
    gridPane.add(btConvert, 0, 2, 2, 1);

    scene = new Scene(gridPane);
    stage.setTitle("°F to °C");
    stage.setScene(scene);
    stage.setResizable(false);
    stage.show();
  }
  
  
  class ButtonClick implements EventHandler{
    @Override
    public void handle(Event evt){
      String input = txtInput.getText();
      
      if(Pattern.matches("[-+]?[0-9]*[.]?[0-9]*", input)){
        lbOutput.setText(String.valueOf((String.format("%.3F" ,Convert.fahrenheitToCelsius(Float.parseFloat(input)))));
      }else{
        Alert alert = new Alert(Alert.AlertType.WARNING);
        alert.setTitle("Chyba!");
        alert.setContentText("Zle zadana hodnota! \nZadaj cislo!");
        alert.showAndWait();
      }

    }
  } 
}
