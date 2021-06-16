
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

public class Info extends Application{
  private Label lbAutor, lbVerzia, lbNazovHry, txtPravidla;
  private Button btBack;
  private VBox vbox;
  private Scene scene;
  
  public void start(Stage stage){
    lbNazovHry = new Label("Hra Obesenec/*center*/");
    lbAutor = new Label("Autor: Tibor Pelegrin");
    lbVerzia = new Label("Verzia: 1.1");
    txtPravidla = new Label("Zvoæ si tÈmu alebo napÌö h·danÈ slovo, zaËni hru a h·daj pÌsmenk· ktorÈ s˙ v slove!");
    btBack = new Button("Vr·tiù sa");
    btBack.setOnAction(new EventHandler(){ 
      public void handle(Event evt){
        Obesenec obesenec = new Obesenec();
        obesenec.start(stage); 
    
      }
    });
    
    vbox = new VBox();
    
    vbox.getChildren().addAll(lbNazovHry);
    vbox.getChildren().addAll(lbAutor);
    vbox.getChildren().addAll(lbVerzia);
    vbox.getChildren().addAll(txtPravidla);
    vbox.getChildren().addAll(btBack);
    
    scene = new Scene(vbox);
    
    
    //vytvoril som si vstupny prud dat
    InputStream iconStream = getClass().getResourceAsStream("img/obesenec.png");
    //vytvoril som objekt (obrazok) pomocou vstupnych dat
    Image icon = new Image(iconStream);
    //nastavil som ikonu pre okno
    stage.getIcons().add(icon);
    
    stage.setTitle("Info Obesenec");
    stage.setScene(scene);
    stage.show();
  }
  
}
