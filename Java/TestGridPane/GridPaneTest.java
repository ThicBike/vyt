import javafx.application.Application;
import javafx.stage.Stage;
import javafx.scene.Scene;
import javafx.scene.layout.GridPane;
import javafx.scene.control.Button;

public class GridPaneTest extends Application{
  private Scene scene;
  private GridPane gridPane;
  
  @Override
  public void start(Stage stage){
    //vytvorím správcu rozmiestnenia
    gridPane = new GridPane();
    //pridám tlačidlo, stĺpec: 0, riadok: 0, tlačidlo zaberá jednu bunku v mriežke
    gridPane.add(new Button("column: " + 0 + " row: " + 0), 0, 0, 1, 1);
    //pridám tlačidlo, stĺpec: 0, riadok: 1, tlačidlo zaberá jeden stĺpec a dva riadky
    gridPane.add(new Button("column: "+ 0 +" row: " + 1), 0, 1, 1, 2);
    //gridPane.add(new Button("column: "+ 0 +" row: " + 2), 0, 2, 1, 1);
    gridPane.add(new Button("column: "+ 1 +" row: " + 0), 1, 0, 1, 1);
    gridPane.add(new Button("column: "+ 1 +" row: " + 1), 1, 1, 1, 1);
    gridPane.add(new Button("column: "+ 1 +" row: " + 2), 1, 2, 1, 1);
    //na scénu pridám gridPane
    scene = new Scene(gridPane, 400, 200);
    stage.setScene(scene);
    stage.setTitle("GRIDPANE");
    
    stage.show();
  }
  
  public static void main(String[] args) {
    Application.launch(args);
  }
}
