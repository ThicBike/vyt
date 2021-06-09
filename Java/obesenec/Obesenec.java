
import javafx.application.Application;
import javafx.stage.Stage;
import javafx.scene.Scene;
import javafx.scene.control.*;
import javafx.scene.layout.*;
import java.util.regex.Pattern;
import javafx.event.*;
import javafx.geometry.*;
import java.io.InputStream;
import java.lang.*;
import javafx.scene.image.*;
import javafx.collections.*;

public class Obesenec extends Application{
  
  public void start(Stage stage){
    new Uvod();
  }
    
  public class Uvod extends Stage{
    private Image imgObesenec;
    private Button btNovaHra, btInfo, btKoniec;
    private VBox vbox;
    private Scene scene;
    public Uvod(){
      vbox = new VBox();
    imgObesenec = new Image("obesenec.png");
    ImageView img = new ImageView();
    img.setImage(imgObesenec);
    //img.setFitWidth(100);
    btNovaHra = new Button("Nová hra");
    btInfo = new Button("Info");
    btKoniec = new Button("Koniec");
    
    vbox.getChildren().addAll(img);
    vbox.getChildren().addAll(btNovaHra);
    vbox.getChildren().addAll(btInfo);
    vbox.getChildren().addAll(btKoniec);
    
    scene = new Scene(vbox);
    
    
    //vytvoril som si vstupny prud dat
    InputStream iconStream = getClass().getResourceAsStream("obesenec.png");
    //vytvoril som objekt (obrazok) pomocou vstupnych dat
    Image icon = new Image(iconStream);
    //nastavil som ikonu pre okno
    this.getIcons().add(icon);
    
    this.setTitle("Hra Obesenec");
    this.setScene(scene);
    this.show();
    }

    
  }
}
