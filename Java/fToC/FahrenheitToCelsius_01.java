/*
Fahrenheit to Celsius
Tibor Pelegrin;
3.A
*/

//importovanie potrebnych kniznic
import javafx.application.Application;
import javafx.stage.Stage;
import javafx.scene.Scene;
import javafx.scene.control.Label;
import javafx.scene.control.Button; 
import javafx.scene.control.TextField;
import javafx.scene.control.Alert;
import javafx.scene.layout.GridPane;
import javafx.scene.text.*;
import javafx.scene.image.Image;
import javafx.geometry.HPos;
import javafx.geometry.Pos;
import javafx.event.EventHandler;
import javafx.event.Event;     
import javafx.geometry.Insets;
import java.io.InputStream;
import java.util.regex.Pattern;
import java.lang.Float;
import java.lang.String;
  

public class FahrenheitToCelsius_01 extends Application{
  //datove polozky ktore predstavuju graficke komponenty
  private Label lbFahrenheit, lbCelsius, lbOutput;
  private TextField txtInput;
  private Button btConvert;
  private GridPane gridPane;
  private Scene scene;
  
  @Override
  public void start(Stage stage){
    //vytvoril som textove pole ktore sluzi na zadanie hodnoty
    txtInput = new TextField("Zadaj stupne Fahrenheita");
    //textovemu polu nastavujem minimalny sirku a zarovnanie jeho obsahu
    txtInput.setMinWidth(150);
    txtInput.setAlignment(Pos.TOP_RIGHT);
    
    //vytvoril som stitok 
    lbFahrenheit = new Label("°F");
    //nastavujem vlastnosti pre dany stitok pomocou css
    lbFahrenheit.setStyle("-fx-font-family: 'Segoe Print'; -fx-font-weight: bold; -fx-font-size: 14px;");
    
    //vytvoril som stitok
    lbOutput = new Label();
    //nastavil som pozadie pre dany stitok
    lbOutput.setStyle("-fx-background-color: yellow;");
    //nastavil som zarovannie stitku a maximalnu sirku
    lbOutput.setAlignment(Pos.TOP_RIGHT);
    lbOutput.setMinWidth(150);
    
    //vytvoril som stitok
    lbCelsius = new Label("°C");
    //stitku nastavujem vlastnosti pomocou css
    lbCelsius.setStyle("-fx-font-family: 'Segoe Print'; -fx-font-weight: bold; -fx-font-size: 14px;");
    
    //vytvoril som tlacidlo
    btConvert = new Button("°F to °C");
    //nastavil som vlastnosti pre tlacidlo pomocou css
    btConvert.setStyle("-fx-font-family: 'Segoe Print'; -fx-font-weight: bold; -fx-font-size: 14px;");
    //nastavenie akcie tlacidla, ktora sa vykona po stlaceni tlacidla
    btConvert.setOnAction(new BtClick());
    
    //vytvoril som si vstupny prud dat
    InputStream iconStream = getClass().getResourceAsStream("thermometer.jpg");
    //vytvoril som objekt (obrazok) pomocou vstupnych dat
    Image icon = new Image(iconStream);
    //nastavil som ikonu pre okno
    stage.getIcons().add(icon);
    
    //vytvoril som komponent rozlozenia GridPane
    gridPane = new GridPane();
    //pridavam komponenty do gridpane  
    gridPane.add(txtInput, 0, 0, 1, 1);   
    gridPane.add(lbFahrenheit, 1, 0, 1, 1);
    gridPane.add(lbOutput, 0, 1, 1, 1);
    gridPane.add(lbCelsius, 1, 1, 1, 1);
    gridPane.add(btConvert, 0, 2, 2, 1);
    
    //nastavil som medzeru medzi komponentami v gridpane
    gridPane.setVgap(10);
    gridPane.setHgap(10);
    
    //nastavil som vycentrovanie gridpane na stred
    gridPane.setAlignment(Pos.CENTER);            
    //nastavil som vycentrovanie na stred pre tlacidlo v gridpane
    gridPane.setHalignment(btConvert, HPos.CENTER);
    //nastavil som padding(medzeru) okolo celeho gridpaneu
    gridPane.setPadding(new Insets(20, 20, 20, 20));
    
    
    //vytvrosil som scenu a pridal som do nej gridpane
    scene = new Scene(gridPane);
    //vytvorenu scenu som pridal na podium
    stage.setScene(scene);
    //nastavil som nazov okna
    stage.setTitle("°F to °C");
    //zrusil som moznost zmenit velkost okna
    stage.setResizable(false);
    //zobrazenie okna
    stage.show();
  }
  
  //vnorena trieda ktora ma implementovane rozhranie pre pracu s udalostou
  class BtClick implements EventHandler{
    @Override
    public void handle(Event evt){
      //overujem ci zadany text je cislo alebo desatinne cislo
      if(Pattern.matches("[-+]?[0-9]*[.]?[0-9]*", txtInput.getText())){
        //do stitku pre vysledok vkladam hodnotu ktora sa mi vrati z metody fahrenheitToCelsius
        //metoda fahrenheittoCelsius sa nachadza v triede Convert
        //metoda fahrenheittoCelsius prebera ako parameter float a preto som pretypoval string na float
        //vysledok potrebujem mat zaokruhleny na 3 desatinne miesta a preto vyuzijem metodu format
        //metoda format mi z floutu spravi string ktory nasledne vlozim ako text do spominaneho stitku
        lbOutput.setText((String.format("%.3f" ,Convert.fahrenheitToCelsius(Float.parseFloat(txtInput.getText())))));
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
  } 
}

