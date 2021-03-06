//BYTECODE *.class -> JVM  -> prikaz -> java
//JIT -> *.exe 
public class Clovek{   //trieda je programatorom zadefinovany datovy typ(struktura)
                       //trieda charakterizuje pomocou datovych poloziek vlastnosti objektu
  //datove poloznky    //vzdy private
  private String meno;              //string je obalovy datovy typ
  private String priezvisko;
  private int vek;
  private String pohlavie;
  
  public static void main(String arg[]){
    //trieda objekt = operator imp.konstruktor            //objekt je premenna typu trieda
    Clovek adam = new Clovek();                       //Clovek() implicitny  //kontruktor-inicializuje datove polozky
    
    System.out.println(adam.meno + " " + adam.priezvisko + " " + adam.vek + " " + adam.pohlavie);
    adam.meno = "Adam";
    adam.priezvisko = "Prvy";
    adam.vek = 100;
    adam.pohlavie = "Muz";
    System.out.println(adam.meno + " " + adam.priezvisko + " " + adam.vek + " " + adam.pohlavie);
    Clovek eva = new Clovek();
    System.out.println(eva.meno + " " + eva.priezvisko + " " + eva.vek + " " + eva.pohlavie);
    eva.meno = "Eva";
    eva.priezvisko = "Prva";
    eva.vek = 100;
    eva.pohlavie = "Zena";
    System.out.println(eva.meno + " " + eva.priezvisko + " " + eva.vek + " " + eva.pohlavie);
  }
}
