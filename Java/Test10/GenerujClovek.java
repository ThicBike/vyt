import java.io.InputStream;
import java.util.Scanner;
import java.util.regex.Pattern;

//BYTECODE *.class -> JVM  -> prikaz -> java
//JIT -> *.exe 
class Clovek{   //trieda je programatorom zadefinovany zlozeny datovy typ(struktura) zapuzdruje dat polozky a metody        
                        //trieda viditelna v ramci adresara
                       //trieda charakterizuje pomocou datovych poloziek vlastnosti objektu
  //datove poloznky  - vlastnosti objektu  //vzdy private
  // start attributes
  //protected String meno;
  //String meno;   //Friendly - viditelna v ramci adresara(balicka)
  private String meno;              //string je obalovy datovy typ
  private String priezvisko;
  private int vek;
  private String pohlavie;
  //staticka datova polozka 
  //datova polozka je pristupna cez triedu aj objekt
  private static int pocetLudi;
  // end attributes
  
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
  //konstruktor vzdy public                                                                                                        
  //nema ziadnu navratovu hodnotu ani void
  //nazov konstruktora = nazov triedy
  
  
  public Clovek(){
    Scanner sc = new Scanner(System.in);
    
    do{
      System.out.print("Zadaj meno: ");
      meno = sc.nextLine();
      meno = meno.substring(0,1).toUpperCase() + meno.substring(1).toLowerCase();
      
      if(!Pattern.matches("[a-zA-Z]*", meno)) System.out.println("Zle meno!");
    } while(!Pattern.matches("[a-zA-Z]*", meno));
    
    do{
      System.out.print("Zadaj priezvisko: ");
      priezvisko = sc.nextLine();
      priezvisko = priezvisko.substring(0,1).toUpperCase() + priezvisko.substring(1).toLowerCase();
      if(!Pattern.matches("[a-zA-Z]*", priezvisko)) System.out.println("Zle priezvisko!");
    } while(!Pattern.matches("[a-zA-Z]*", priezvisko));
    
    
    System.out.print("Zadaj pohlavie: ");
    pohlavie = sc.nextLine(); 
                                                
    do{
      System.out.print("Zadaj vek: ");
      vek = sc.nextInt();
      if(!(vek >= 18)) System.out.println("Zamestnanec musi byt plnelety!");
    }while(!(vek >= 18));
    
    Clovek.pocetLudi++;
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
    Clovek.pocetLudi++;
  }      
  
  public Clovek(String meno, String priezvisko, String pohlavie, int vek){
    //explicitny konstruktor   pretazeny
    //volanie implicitneho konstruktora
    
    this(meno, priezvisko);   //volanie kontruktora z konstruktora     this na 1. mieste
    this.pohlavie = pohlavie;     // this odkaz na objekt
    this.vek = vek;  
  }      
  // start methods
  
  //nastavujeme hodotu datovej polozky
  public void setMeno(String meno){
    this.meno = meno;
  }
  
  //ziskame hodnotu datovej polozky
    
  //Meno
  public String getMeno(){
    return meno;
  }
  
  public void setPriezvisko(String priezvisko){
    this.priezvisko = priezvisko;
  }
  
  //Priezvisko
  public String getPriezvisko(){
    return priezvisko;
  }
  
  //Vek
  public void setVek(int vek){
    this.vek = vek;
  }
  
  public int getVek(){
    return vek;
  }
  
  //Pohlavie
  public void setPohlavie(String pohlavie){
    this.pohlavie = pohlavie;
  }
  
  public String getPohlavie(){
    return pohlavie;
  }
  
  public void info(){
    //System.out.println(meno + " " + priezvisko + " " + vek + " " + pohlavie);
    System.out.println("Meno: " + getMeno() + "\nPriezvisko: " + getPriezvisko() + "\nVek: " + getVek() + "\nPohlavie: " + getPohlavie());
    //System.out.println("Pocet Ludi: " + Clovek.pocetLudi);  
  }                                  
  // end methods
}

 public class GenerujClovek{
  public static void main(String ang[]){
    //Clovek adam = new Clovek();
    //System.out.println(adam.meno + " " + adam.priezvisko + " " + adam.vek + " " + adam.pohlavie);
    //adam.info();                                
    
    Clovek eva = new Clovek("Eva", "Prva");
    //System.out.println(eva.meno + " " + eva.priezvisko + " " + eva.vek + " " + eva.pohlavie);
    eva.info();
    
    
    Clovek abel = new Clovek("Abel", "Druhy", "Muz", 50);
    //System.out.println(abel.meno + " " + abel.priezvisko + " " + abel.vek + " " + abel.pohlavie);
    abel.info();
    //abel.setMeno("Kain");
    //abel.setVek(55);
    //System.out.println(abel.getMeno());
    //abel.info();
    
    Clovek rodriguez = new Clovek();
    rodriguez.info();
  }
  // end methods1
 }

