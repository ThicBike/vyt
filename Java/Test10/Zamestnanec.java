//je zamestnanec clovek??? ano je??? dedenie!

import java.io.InputStream;
import java.util.Scanner;

public class Zamestnanec extends Clovek{        //zamestnanec je dcerska trieda triedy clovek, dedenie //dedit mozme len z jednej triedy
  private float plat;
  private String oddelenie;
  
  public Zamestnanec(){
    //auto volanie konstruktora rodica - explicitny konstruktor bez parametrov
    //super("Jan", "Hrach");            //vola konstruktor z rodica ktory ma 2 parametre
    
    Scanner sc = new Scanner(System.in);
    System.out.print("Zadaj plat: ");
    plat = sc.nextFloat();
    sc.nextLine();   //vyprazdnenie bufferu
    System.out.print("Zadaj oddelenie: ");
    oddelenie = sc.nextLine();
  }
  
  public Zamestnanec(float plat, String oddelenie){
    this.plat = plat;
    this.oddelenie = oddelenie;
  }
  
  public float getPlat(){
    return plat;
  }
  
  public void setPlat(float plat){
    this.plat = plat;
  }
  
  public void setPlat(float plat, float odmena){
    this.plat = plat + odmena;
  }
  
  public String getOddelenie(){
    return oddelenie;
  }
  
  public void setOddelenie(String oddelenie){
    this.oddelenie = oddelenie;
  }
  
  public void info(){
    //System.out.println(getMeno() + " " + getPriezvisko() + " " + getVek() + " " + getPohlavie());
    System.out.println("Zamestanenc:");
    super.info(); 
    System.out.println("Plat: " + getPlat() + "\n" + "Oddelenie: " + getOddelenie());
  }
    
  public static void main(String arg[]){
    Zamestnanec hrasko = new Zamestnanec();
    //hrasko.setPlat(hrasko.getPlat(), 500);
    hrasko.setPlat(6000, 500);
    
    Zamestnanec brigadnik = new Zamestnanec(500, "brigadnik");
    //hrasko.info();
    //hrasko.setMeno("Adam");
    hrasko.info();
    brigadnik.info();
  }
}
