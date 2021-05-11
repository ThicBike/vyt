//je zamestnanec clovek??? ano je??? dedenie!

public class Zamestnanec extends Clovek{
  private int plat;
  private String oddelenie;
  
  public Zamestnanec(){
    //auto volanie konstruktora rodica - explicitny konstruktor bez parametrov
    super("Jan", "Hrach");            //vola konstruktor z rodica ktory ma 2 parametre
    plat = 1000;
    oddelenie = "vyvoj";
  }
  
  public void info(){
    //System.out.println(getMeno() + " " + getPriezvisko() + " " + getVek() + " " + getPohlavie());
    super.info(); 
    System.out.println(plat + " " + oddelenie);
  }
    
  public static void main(String arg[]){
    Zamestnanec hrasko = new Zamestnanec();
    //hrasko.info();
    //hrasko.setMeno("Adam");
    hrasko.info();
  }
}
