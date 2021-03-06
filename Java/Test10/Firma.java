import java.util.ArrayList;
import java.util.Scanner;
import java.util.regex.Pattern;

public class Firma{
  private String nazov;
  private float obrat;
  private ArrayList zamestnanci;
  
  public Firma(){
    Scanner sc = new Scanner(System.in);
    
    System.out.print("Zadaj nazov firmy: ");
    nazov = sc.nextLine();
    nazov = nazov.substring(0,1).toUpperCase() + nazov.substring(1).toLowerCase();
    
    System.out.print("Zadaj obrat firmy: " );
    obrat = sc.nextFloat();
      
    zamestnanci = new ArrayList();
  } 
  
  public Firma(String nazov, float obrat){
    setNazov(nazov);
    setObrat(obrat);
  }
  
  public String getNazov(){
    return nazov;
  }
  
  public void setNazov(String nazov){
    this.nazov = nazov;
  }
  
  public float getObrat(){
    return obrat;
  }
  
  public void setObrat(float obrat){
    this.obrat = obrat;
  }
  
  public void nacitanieZamestnanca(){
    Scanner sc = new Scanner(System.in);
    String volba;
    
    do {
      System.out.println("\nZadaj udaje o zamestnancovi: ");
      zamestnanci.add(new Zamestnanec());
      
      do {
        System.out.println("\nChces zadat dalsieho zamestnanca ? ano/nie");
        volba = sc.nextLine(); 
      } while (!volba.equals("ano") && !volba.equals("nie")); 
    } while (!volba.equals("nie"));
  }
  
  public void vymazanieZamestnancov(){
    if(!zamestnanci.isEmpty()){
      zamestnanci.clear();
    
      if(zamestnanci.isEmpty()) System.out.println("\nVsetci zamestnanci boli uspesne prepusteni :D"); 
    }else {
       System.out.println("Neexistuju zamestnanci!");
     } // end of if-else
  }
    
  public void vyberVymazania(){
    Scanner sc = new Scanner(System.in);
    String volba;
    
    System.out.println("/n(i) - vymazanie podla indexu");
    System.out.println("(m) - vymazanie podla mena a priezviska");
    
    do{
      System.out.print("Tvoja volba: ");
      volba = sc.nextLine();
      if(!volba.equals("i") && !volba.equals("m")) System.out.println("Zla volba!");
    }while(!volba.equals("i") && !volba.equals("m"));
    
    if(volba.equals("i")) vymazanieZamestnanca();
    else if(volba.equals("m")){
      String meno;
      String priezvisko;
        
      do {
        System.out.print("/nZadaj meno zamestnanca: ");  
        meno = sc.nextLine();
        meno = meno.substring(0,1).toUpperCase() + meno.substring(1).toLowerCase();
         
        if(!Pattern.matches("[a-zA-Z]*", meno)) System.out.println("Zle meno!");
      } while(!Pattern.matches("[a-zA-Z]*", meno));
      
      do {
        System.out.print("Zadaj priezvisko zamestnanca: ");  
        priezvisko = sc.nextLine();
        priezvisko = priezvisko.substring(0,1).toUpperCase() + priezvisko.substring(1).toLowerCase();
         
        if(!Pattern.matches("[a-zA-Z]*", priezvisko)) System.out.println("Zle meno!");
      } while(!Pattern.matches("[a-zA-Z]*", priezvisko));  
      
      vymazanieZamestnanca(meno, priezvisko);
    }
  }
      
  public void vymazanieZamestnanca(){
    Scanner sc = new Scanner(System.in);
    int index;
    
    if(!zamestnanci.isEmpty()){
      do {
        System.out.print("\nZadaj index zamestnanca ktoreho chces prepustit (0 - " + (zamestnanci.size() - 1) + "): ");
        index = sc.nextInt();
      
        if(index >= zamestnanci.size() || index < 0) System.out.println("Neexistujuci index!");
      } while (index >= zamestnanci.size() || index < 0);    
      
      zamestnanci.remove(index);
      System.out.println("/nZamestnanec bol uspesne prepusteny :D");
    }else {
       System.out.println("Neexistuju zamestnanci!");
    } // end of if-else
  }
  
  public void vymazanieZamestnanca(String meno, String priezvisko){
    Zamestnanec clovek;
    
    if(!zamestnanci.isEmpty()){
      for (int i = 0; i < zamestnanci.size(); i++){
        clovek = (Zamestnanec)zamestnanci.get(i);
        if(clovek.getMeno().equals(meno) && clovek.getPriezvisko().equals(priezvisko)){
          zamestnanci.remove(i);
          System.out.println("Zamestnanec bol uspesne prepusteny :D");
        }else{
          System.out.println("Nenasiel sa zamestnanec!");
        }
      }
    }else{
      System.out.println("Neexistuju zamestnanci!");  
    }
  }
  
  public void menu(){
    System.out.println("\nVyber: ");
    System.out.println("Pridat zamestnanca (p)");
    System.out.println("Vypis zamestnancov (v)");
    System.out.println("Info o firme (i)");
    System.out.println("Vyhodit vsetkych zamestnancov (x)");
    System.out.println("Vyhodit jedneho zamestnanca (y)");
    System.out.println("Ukoncit program (k)");
  }
  
  public String vyber(){
    Scanner sc = new Scanner(System.in);    
    String volba;
    
    do {
      System.out.print("Tvoja volba: ");
      volba = sc.nextLine();
      if(je(volba)){
        System.out.println("Zla volba!");
      }
    } while (je(volba));
    
    return volba;
  }
  
  public boolean je(String volba){
    if(!volba.equals("p") && !volba.equals("v") && !volba.equals("x") && !volba.equals("y") && !volba.equals("k") && !volba.equals("i")){
      return true;
    }else{
      return false;
    }
  }

  public boolean vyber(String volba){
    switch (volba) {
      case  "p": 
        nacitanieZamestnanca();
        return false;
        
      case  "v": 
        infoZamestnanec();
        return false;
        
      case  "x": 
        vymazanieZamestnancov();
        return false;
        
      case  "y": 
        vyberVymazania();
        return false;
       
      case  "i": 
        infoFirma();
        return false;
           
      case  "k": 
        return koniec();    
    } 
    
    return false;
  }
  
  public boolean koniec(){
    Scanner sc = new Scanner(System.in);
    String volba;
    
    do{
      System.out.println("\nNaozaj chces ukoncit program? ano/nie");
      volba = sc.nextLine();
      if(!volba.equals("nie") && !volba.equals("ano")) System.out.println("Zla volba!");
    }while(!volba.equals("nie") && !volba.equals("ano"));
    
    if(volba.equals("nie")) return false;
    if(volba.equals("ano")) return true;
    return false;
  }
  
  public void infoFirma(){
    System.out.println("\nInfo o firme: ");
    System.out.println("Nazov firmy: " + getNazov());
    System.out.println("Obrat firmy: " + getObrat());
    System.out.println("Pocet zamestnancov: " + zamestnanci.size());
  }
    
  public void infoZamestnanec(){
    if(!zamestnanci.isEmpty()){
      for(int i = 0; i < this.zamestnanci.size(); i++){
        Zamestnanec zamestnanec = (Zamestnanec)this.zamestnanci.get(i); 
        System.out.println("\nZamestnanec c." + (i + 1) + ":");
        System.out.println("Meno: " + zamestnanec.getMeno());
        System.out.println("Priezvisko: " + zamestnanec.getPriezvisko());
        System.out.println("Oddelenie: " + zamestnanec.getOddelenie());
        System.out.println("Plat: " + zamestnanec.getPlat());
      }
    }else{
       System.out.println("\nFirma nema zamestnancov!");
    }
  }
  
  public static void main(String args[]){
    Firma firmaA = new Firma();
    String volba;
    String moznost;  
    
    do {
      firmaA.menu();
      volba = firmaA.vyber();
      
    } while (!firmaA.vyber(volba));
    
    System.out.println("\n### Dovidenia! ###");
  }
}

