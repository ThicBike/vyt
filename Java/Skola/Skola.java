public class Skola{
  private int pocetZiakov;
  private String riaditel;
  
  public Skola(){
    //imolicitny 
     pocetZiakov = 280;
     riaditel = "Stefan"; 
  }
  
  public Skola(int pocet, String meno){
    this.pocetZiakov = pocet;
    this.riaditel = meno;
  }
  
  public static void main(String arg[]){
    Skola spseke = new Skola();
    Skola spse = new Skola(800, "Juraj");
  }
}

