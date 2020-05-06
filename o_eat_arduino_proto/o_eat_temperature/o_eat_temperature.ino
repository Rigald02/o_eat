#include <Firmata.h>
#include <LiquidCrystal.h>

//LiquidCrystal lcd(1);   //désigne le port qui détecte la température

  //pinMode(A0, INPUT);
  //thermo-résistance branché sur la pin A0
  int thermo = A0;

// delay between sensor reads
  int readDelay = 5000;

void setup()
{
    //initializing serial communication with the Omega2 for sending sensor data
    Serial.begin(9600);
}

void loop()
{
    // getting the voltage reading from the temperature sensor
    int reading = analogRead(thermo);  

    //if (analogRead(thermo) == HIGH  )
    //{
    float voltage = (float)reading * 5.0;   // convert the analog reading (0 to 1023) to voltage (0 - 5V)
    voltage /= 1024.0;
    float temperatureC = (voltage - 0.5) * 100;   // convert voltage to degree Celsius including the 500mV offset adjustment
    float temperatureF = (temperatureC * 9.0 / 5.0) + 32.0;   // convert from Celsius to Fahrenheit

    if (voltage <= 0.10)    //inférieur à 40 degré celsius
    {
      Serial.println("NULL");   //volt débranché (3.3 ou 5V)
    }
    if (voltage >= 1.50)    //supérieur à 100 degré celsius
    {
      Serial.println("NULL");   //ground, analog ou les trois débranché (le voltage passe au dela de 2v). Si branché sur 5v, le voltage sera automatique de 5v overall
    }
    else
    {
      Serial.print(voltage); Serial.print(" volts - ");
      Serial.print(temperatureC); Serial.print(" degrees C - ");
      Serial.print(temperatureF); Serial.println(" degrees F");
    }
    //0 a 0.50 : negatif
    //0.51 a 1.00: entre 0 et 50°
    //entre 1.00 et 1.50: 50° a 100°
    //etc
    
    // delay between readings since the change is gradual
    delay(readDelay);
    /*}
    else
    {
      Serial.println("NULL");
      delay(readDelay);
    }*/

    /*
     * Note: pour parvenir a percevoir si le senseur est connecté, le nombre de volt reçu devient 0. pour le cable fournissant l'énergie.
     *  Si le cable de ground est débranché, le voltage monte a + de 4V (400° environ).
     *  Si le dernier cable st débrenché, le voltage monte a + de 1V
     * Il faut donc trouver un moyen d'envoyer un medssage NULL si le voltage est de 0 volt.
     */
}
