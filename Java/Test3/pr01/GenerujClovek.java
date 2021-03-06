55//BYTECODE *.class -> JVM  -> prikaz -> java
//JIT -> *.exe 
class Clovek{   //trieda je programatorom zadefinovany zlozeny datovy typ(struktura)                  //trieda viditelna v ramci adresara
                       //trieda charakterizuje pomocou datovych poloziek vlastnosti objektu
  //datove poloznky    //vzdy private
  public String meno;              //string je obalovy datovy typ
  public String priezvisko;
  public int vek;
  public String pohlavie;
  
  /*
    public static void main(String arg[]){
    //trieda objekt = operator imp.konstruktor            //objekt je premenna typu trieda
    Clovek adam = new Clovek();                       //Clovek() implicitny  //kontruktor-inicializuje datove polozky
                                                      //triedu na null , ine na nahodne
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
  */
  
  
  //explicitny konstruktor
  // konstruktor vzdy public
  //nema ziadnu navratovu hodnotu ani void
  //nazov konstruktora = nazov triedy
  
  
  public Clovek(){
    //implcitny konstruktor
    meno = "Adam";
    priezvisko = "Prvy";
    pohlavie = "Muz";
    vek = 150;
    
  }
  
  public Clovek(String meno, String priezvisko){
    //explicitny konstruktor
    //volanie implicitneho konstruktora
    /*System.out.println(this.meno);
    System.out.println(this.priezvisko);
    System.out.println(pohlavie);
    System.out.println(vek);*/
    this.meno = meno;
    this.priezvisko = priezvisko; 
    
  }      
  
  public Clovek(String meno, String priezvisko, String pohlavie, int vek){
    //explicitny konstruktor   pretazeny
    //volanie implicitneho konstruktora
    
    this(meno, priezvisko);   //volanie kontruktora z konstruktora     this na 1. mieste
    this.pohlavie = pohlavie;     // this odkaz na objekt
    this.vek = vek;  
  }      
  
  public void info(){
    System.out.println(meno + " " + priezvisko + " " + vek + " " + pohlavie);
  }                                  
}

 public class GenerujClovek{
  public static void main(String ang[]){
    Clovek adam = new Clovek();
    //System.out.println(adam.meno + " " + adam.priezvisko + " " + adam.vek + " " + adam.pohlavie);
    adam.info();
    
    Clovek eva = new Clovek("Eva", "Prva");
    //System.out.println(eva.meno + " " + eva.priezvisko + " " + eva.vek + " " + eva.pohlavie);
    eva.info();
    
    
    Clovek abel = new Clovek("Abel", "Druhy", "Muz", 50);
    //System.out.println(abel.meno + " " + abel.priezvisko + " " + abel.vek + " " + abel.pohlavie);
    abel.info();
    
  }
 }






