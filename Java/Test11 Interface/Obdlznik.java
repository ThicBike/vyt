public class Obdlznik implements Tvar2D{
  private float stranaA, stranaB;
  
  public float obsah(){
    return stranaA * stranaB;
  }

  public float obvod(){
    return  2 * (stranaA + stranaB);
  }

  public void kresliTvar(){
     System.out.println("Kreslim obdlznik");
  }
  
  public void zmazTvar(){
    System.out.println("Mazem obdlznik");
  }

  public void info(){
    System.out.println("Som obdlznik");
  }

}

