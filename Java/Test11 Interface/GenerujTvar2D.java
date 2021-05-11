public class GenerujTvar2D{
  public static Tvar2D generujTvar2D(){
    switch ((int)(Math.random() * 3)){
      default:
      case  0: return new Kruh();
      case  1: return new Obdlznik();
      case  2: return new Trojuholnik();   
    }
  }
  public static void main(String args[]){
    Tvar2D tvar[] = new Tvar2D[7];
    
    for (int i = 0; i < tvar.length; i++){
      tvar[i] = GenerujTvar2D.generujTvar2D();
    }
    
    for (int i = 0; i < tvar.length; i++){
      tvar[i].info();
      tvar[i].zmazTvar();
    }

  }

  
}

