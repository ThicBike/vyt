
import javafx.application.Application;
import javafx.stage.Stage;
import javafx.scene.Scene;
import javafx.scene.control.*;
import javafx.scene.*;
import javafx.scene.layout.*;
import java.util.regex.Pattern;
import javafx.event.*;
import javafx.geometry.*;
import java.io.InputStream;
import java.lang.*;
import javafx.scene.image.*;
import javafx.collections.*;

public class Obesenec extends Application{
  private Image imgObesenec;
  private Button btNovaHra, btInfo, btKoniec;
  private Pane cardsPane;
  private Group card1, card2;
  private VBox vbox;
  private Scene scene;
  
  public void start(Stage stage){
    
    MenuItem miHraj = new MenuItem("Hraj");
    MenuItem miInfo = new MenuItem("Info");
    MenuItem miKoniec = new MenuItem("Koniec");
    
    final Menu menu = new Menu("Menu");
    MenuBar menuBar = new MenuBar();
    menuBar.getMenus().add(menu);
    
    menu.getItems().addAll(miHraj, miInfo, miKoniec);
    
    miHraj.setOnAction(new EventHandler(){ 
      public void handle(Event evt){
        Info info = new Info();
        info.start(stage); 
    
      }
    });
    
    miInfo.setOnAction(new EventHandler(){ 
      public void handle(Event evt){
        Hra hra = new Hra();
        hra.start(stage); 
    
      }
    });
    
    miKoniec.setOnAction(new EventHandler(){ 
      public void handle(Event evt){
        stage.close();
      }
    });
    
    
    vbox = new VBox();
    imgObesenec = new Image("img/obesenec.png");
    ImageView img = new ImageView();
    img.setImage(imgObesenec);
    btNovaHra = new Button("Nová hra");
    btInfo = new Button("Info");
    btKoniec = new Button("Koniec");
    
    btInfo.setOnAction(new EventHandler(){ 
      public void handle(Event evt){
        Info info = new Info();
        info.start(stage); 
      }
    });
    
    btKoniec.setOnAction(new EventHandler(){ 
      public void handle(Event evt){
        stage.close();
    
      }
    });
    
    btNovaHra.setOnAction(new EventHandler(){ 
      public void handle(Event evt){
        Hra hra = new Hra();
        hra.start(stage); 
    
      }
    });
    
    
    cardsPane = new StackPane();
    card1 = new Group(new Label("Card 1"));
    card2 = new Group(new Label("Card 2"));
    
    
    
    vbox.getChildren().addAll(menuBar);
    vbox.getChildren().addAll(img);
    vbox.getChildren().addAll(cardsPane);
    vbox.getChildren().addAll(btNovaHra);
    vbox.getChildren().addAll(btInfo);
    vbox.getChildren().addAll(btKoniec);
    
                                     
    scene = new Scene(vbox);
    
    //vytvoril som si vstupny prud dat
    InputStream iconStream = getClass().getResourceAsStream("img/obesenec.png");
    //vytvoril som objekt (obrazok) pomocou vstupnych dat
    Image icon = new Image(iconStream);
    //nastavil som ikonu pre okno
    stage.getIcons().add(icon);
    
    stage.setTitle("Hra Obesenec");
    stage.setScene(scene);
    stage.show(); 
  }
  
  class ButtonClickInfo implements EventHandler{
    @Override
    public void handle(Event evt){
      
      /*Info info = new Info();
      info.start(super.stage);  
      
      
      cardsPane.getChildren().clear();
      cardsPane.getChildren().add(card1); */  
    }
  }
  
  class ButtonClickHra implements EventHandler{
    @Override
    public void handle(Event evt){
      cardsPane.getChildren().clear();
      cardsPane.getChildren().add(card2);
    }
  } 
  
  
}
