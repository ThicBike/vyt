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
    lbFahrenheit.setFont(Font.font("Segoe Print", FontWeight.BOLD, 14));
    lbOutput = new Label();
    lbOutput.setStyle("-fx-background-color: yellow;");
    
    lbOutput.setMinWidth(150);
    lbCelsius = new Label("°C");
    lbCelsius.setFont(Font.font("Segoe Print", FontWeight.BOLD, 14));
    btConvert = new Button("°F to °C");
    btConvert.setFont(Font.font("Segoe Print", FontWeight.BOLD, 14));
  
    
    InputStream iconStream = getClass().getResourceAsStream("icon/tmeter.png");
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
    stage.getIcons().add(new Image("file:thermometer.png"));
    stage.setTitle("°F to °C");
    stage.setScene(scene);
    stage.show();
  }
}
