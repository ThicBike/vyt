import javafx.application.Application;
import javafx.stage.Stage;
import javafx.scene.control.Label;
import javafx.scene.control.Button; 
import javafx.scene.control.TextField;
import javafx.scene.layout.GridPane; 
import javafx.scene.Scene;
import javafx.scene.text.Font;
import javafx.scene.text.*;
import javafx.geometry.Pos;
import javafx.event.EventHandler;
import javafx.event.Event;     


public class FahrenheitToCelsius_01 extends Application{
  private Label lbFahrenheit, lbCelsius, lbOutput;
  private TextField txtInput;
  private Button btConvert;
  private GridPane gridPane;
  private Scene scene;
  
  @Override
  public void start(Stage stage){
    
    
    
    txtInput = new TextField("Zadaj stupne Fahrenheita");
    lbFahrenheit = new Label("°F");
    lbOutput = new Label("ddd");
    lbOutput.setStyle("-fx-background-color: yellow;");
    lbCelsius = new Label("°C");
    btConvert = new Button("°F to °Csfsfesefrearseefsrfefsefesffssf");
    btConvert.setStyle("-fx-background-color: red;");
    
    gridPane = new GridPane();
    
    gridPane.setAlignment(Pos.CENTER);
    
    gridPane.add(txtInput, 0, 0, 1, 1);
    gridPane.add(lbFahrenheit, 1, 0, 1, 1);
    gridPane.add(lbOutput, 0, 1, 1, 1);
    gridPane.add(lbCelsius, 1, 1, 1, 1);
    gridPane.add(btConvert, 0, 2, 2, 1);

    scene = new Scene(gridPane, 400, 200);
    stage.setScene(scene);
    stage.show();
  }
}
