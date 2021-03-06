/*
Convert
Tibor Pelegrin;
3.A
*/

//trieda Convert
public class Convert{
  //staticka metoda na premenu stupnov fahrenheita na stupne celsius 
  //metoda prebera ako parameter stupne fahrenheita
  public static float fahrenheitToCelsius(float fahrenheit){
    return (fahrenheit - 32F) / 1.8F; 
  }
  
  //staticka metoda na premenu stupnov celsiua na stupne fahrenheita 
  //metoda prebera ako parameter stupne celsia
  public static float cesiusToFahrenheit(float celsius){
    return celsius * 1.8f + 32f; 
  }
  
  //staticka metoda na premenu kilometrov na mile 
  //metoda prebera ako parameter kilometre
  public static float kilometersToMiles(float km){
    return km * 0.62137f;
  }
  
  //staticka metoda na premenu mil na kilometre 
  //metoda prebera ako parameter mile
  public static float milesToKilometers(float miles){
    return miles * 1.609344f;
  }

}


