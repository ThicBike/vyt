import java.util.Scanner;

public class GenerujTvar{
  private Valec valec;
  private Kruh kruh;
  private Obdlznik obdlznik;
  
  public GenerujTvar(){
    System.out.println("\nZadaj hodnoty pre valec: ");
    valec = new Valec();
    
    System.out.println("\nZadaj hodnoty pre kruh: ");
    kruh = new Kruh();
    
    System.out.println("\nZadaj hodnoty pre obdlznik: ");
    obdlznik = new Obdlznik();
  }
  
  public GenerujTvar(int tvar){
    switch (tvar) {
      case  1: 
        valec = new Valec();
        valec.info();
        break;
      case  2: 
        kruh = new Kruh();
        kruh.info();
        break;
      case 3:
        obdlznik = new Obdlznik();
        obdlznik.info();
        break;   
    } // end of switch 
  }

  public static void menu(){
    System.out.println("\nVyber si tvar");
    System.out.println("Valec (1)");
    System.out.println("Kruh (2)");
    System.out.println("Obdlznik (3)");
    System.out.println("Vsetky tri (4)\n");
  }
 
  public static void main(String arg[]){
    Scanner input = new Scanner(System.in);
    int volba;     
    boolean koniec;
    
    do{ 
      menu();
      do{
        System.out.print("Tvoja volba: ");
        volba = input.nextInt();
      
        if(volba != 1 && volba != 2 && volba != 3 && volba != 4){
          System.out.println("Zla volba!");
        }
      }while(volba != 1 && volba != 2 && volba != 3 && volba != 4);
    
      if(volba == 4){
        GenerujTvar tvar = new GenerujTvar();
        
        tvar.valec.info();
        tvar.kruh.info();
        tvar.obdlznik.info();
      }else {
        GenerujTvar tvar = new GenerujTvar(volba);
      } // end of if-else
      
      do {
        System.out.println("\nChces pokracovat ? True/False");
        koniec = input.nextBoolean();
        if(koniec != true && koniec != false) System.out.println("Zla volba!");
      } while (koniec != true && koniec != false); // end of do-while
    }while(koniec);
      System.out.println("Dovidenia!");
  }
}

