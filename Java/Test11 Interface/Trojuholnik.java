public class Trojuholnik implements Tvar2D{
  private float stranaA, stranaB, stranaC;
  
  public float obsah(){
    float o = obvod() / 2;
    return (float)Math.sqrt(o * (o - stranaA) * (o - stranaB) * (o - stranaC));
  }

  public float obvod(){
    return  stranaA + stranaB + stranaC;
  }

  public void kresliTvar(){
     System.out.println("Kreslim trojuholnik");
  }
  
  public void zmazTvar(){
    System.out.println("Mazem trojuholnik");
  }

  public void info(){
    System.out.println("Som trojuholnik");
  }

}

