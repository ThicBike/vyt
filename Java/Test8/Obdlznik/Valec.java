import java.util.Scanner;

public class Valec{      
  
  //vkladanie, skladanie, kompozicie
  private static final float PI = 3.14F;
  private Kruh podstava;
  private Obdlznik plast;
  
  //konstruktory
  public Valec(){
    Scanner sc = new Scanner(System.in);
    
    System.out.print("Zadaj polomer: ");
    podstava = new Kruh(sc.nextFloat());
    
    System.out.print("Zadaj vysku valca: ");
    plast = new Obdlznik(podstava.obvod(), sc.nextFloat());
  }
  
  public Valec(float polomer, float vyska){
    podstava = new Kruh(polomer);
    plast = new Obdlznik(podstava.obvod(), vyska);
  }
  
  //getters setters
  public float getPolomer(){
    return podstava.getPolomer();
  }
    
  public void setPolomer(float polomer){
    podstava.setPolomer(polomer);
    plast.setStranaA(podstava.obvod());
  }
  
  public float getVyska(){
    return plast.getStranaB();
  }

  public void setVyska(float vyska){
    plast.setStranaB(vyska);
  }
  
  public Obdlznik getPlast(){
    return plast;
  }
  
  public void setPlast(float stranaA, float stranaB){
    plast.setStranaA(stranaA);
    plast.setStranaB(stranaB);
    podstava.setPolomer(stranaA / 2 / PI);
  }
  
  public Kruh getPodstava(){
    return podstava;
  }
  
  public void setPodstava(float polomer){
    podstava.setPolomer(polomer);
    plast.setStranaA(podstava.obvod());
  }

  //metody
  public float objem(){
    return podstava.obsah() * plast.getStranaB();
  }
  
  public float povrch(){
    return 2 * podstava.obsah() + plast.obsah();
  }
  
  //info
  public void info(){
    System.out.println("\nValec: ");
    System.out.println("Polomer podstavy: " + getPolomer());
    System.out.println("Vyska valca: " + getVyska());
    System.out.println("Obsah podstav: " + podstava.obsah());
    System.out.println("Obsah plasta: " + plast.obsah());
    System.out.println("Objem valca: " + objem());
    System.out.println("Povrch valca: " + povrch());
  }
  
  //main
  public static void main(String arg[]){
    Valec valec1 = new Valec();
    valec1.info();
    
    Valec valec2 = new Valec(4.78F, 7.24F);
    valec2.info();
  }
}

