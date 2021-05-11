//public class TriedaPotomok extends TriedaRodic implements InterfaceA, InterfaceB, ... InterfaceX

public class Kruh implements Tvar2D{
  private float polomer;
  
  public float obvod(){
    return 2 * Tvar2D.PI * polomer;
  }

  public float obsah(){
    return Tvar2D.PI * (float)Math.pow(polomer, 2);
  }

  public void kresliTvar(){
    
  }

  public void zmazTvar(){
    
  }

  
  public void info(){
    System.out.println("Som kruh");
  }
  

  
}

