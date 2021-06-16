
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

public class Hra extends Application{
  private Image imgObesenec;
  private Label lbSlovoVypis, lbVolbaTemy, lbPouzitePismena;
  private Button btHrat;
  private ComboBox comboBox;
  private String slovo;
  private GridPane grid; 
  private VBox vbox;
  private Menu menu;
  private Scene scene;
  
  public void start(Stage stage){
    lbVolbaTemy = new Label("Zvoæ si tÈmu");
    lbSlovoVypis = new Label("-------");
    btHrat = new Button("Hraù");
    lbPouzitePismena = new Label("PouûitÈ pÌsmenk·: ");
    btHrat.setOnAction(new BtClick());
    imgObesenec = new Image("img/obesenec.png");
    ImageView img = new ImageView();
    img.setImage(imgObesenec);
    
    MenuItem miHraj = new MenuItem("Hraj");
    MenuItem miInfo = new MenuItem("Info");
    MenuItem miKoniec = new MenuItem("Koniec");
    
    menu = new Menu("Menu");
    MenuBar menuBar = new MenuBar();
    menuBar.getMenus().add(menu);
    
    
    menu.getItems().addAll(miHraj, miInfo, miKoniec);
    
    miHraj.setOnAction(new EventHandler(){ 
      public void handle(Event evt){
        Hra hra = new Hra();
        hra.start(stage);
      }
    });
    
    miInfo.setOnAction(new EventHandler(){ 
      public void handle(Event evt){
         
        Info info = new Info();
        info.start(stage); 
      }
    });
    
    miKoniec.setOnAction(new EventHandler(){ 
      public void handle(Event evt){
        stage.close();
      }
    });
    
    comboBox = new ComboBox();
    comboBox.getItems().add("Men·");
    comboBox.getItems().add("ät·ty");
    comboBox.getItems().add("Mest·");
    comboBox.getItems().add("VlastnÈ slovo ");
    comboBox.getSelectionModel().selectFirst();
    
    vbox = new VBox();
    grid = new GridPane();
    
    grid.add(menuBar, 0, 0, 2, 1);
    grid.add(lbVolbaTemy, 0, 1, 1, 1);
    grid.add(comboBox, 0, 2, 2, 1);
    grid.add(btHrat, 0, 3, 1, 1);
    grid.add(img, 1, 1, 1, 4);
    grid.add(lbSlovoVypis, 0, 6, 2, 1);
    grid.setHalignment(lbSlovoVypis, HPos.CENTER);
    lbSlovoVypis.setVisible(false);
    
    scene = new Scene(grid);
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
    
  class BtClick implements EventHandler{
    public void handle(Event event){
      lbSlovoVypis.setVisible(true);
      lbSlovoVypis.setText(lbSlovoVypis.getText() + "a");
    }
  }

  
}
