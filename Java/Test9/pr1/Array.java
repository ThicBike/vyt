public class Array{
  private static int cisla[]; //deklaracia pola
  //int[] cisla; //deklaracia ale nepaci sa nam
  
  //private static int cisla[] = {4, 3, 2, 0, 9};

  
  
  
  public static void main(String arg[]){
    cisla = new int[5];//alokacia pamate pre 5 prvkov
    //chyba - cisla = new cisla[5];
    
    System.out.println("velkost pola: " + cisla.length);
    
  }

  
}

