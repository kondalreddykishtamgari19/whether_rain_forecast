/*Project:ClimaPredict: Real-Time Weather(rain predict) Forecasting using Machine Learning
Hardware:Buzzer--27,Temperature & humidity_sensor_DHT11--14,LDR(POT)--34
AIM:Rain prediction is more than 50 buzzer will on or else off*/
/*libraries Initialization*/
#include "regression.h" //Regression model
#include"DHT.h" //Temperture Sensor
//Pin Definations
#define DHTTYPE DHT11 //Type of Temperature & Humidity sensor 
#define dht_dpin 14 //DHT11--data pin
#define pot 34//LDR(Potentiometer)--analog 
#define buzzer 27//buzzer
#define threshold 20
// Initialize the Linear Regression classifier
Eloquent::ML::Port::LinearRegression classifier;
// Create an instance of the DHT sensor
DHT dht(dht_dpin,DHTTYPE);
// Array to store sensor readings (humidity, temperature, and potentiometer value)
float par[3];

void setup() 
{
  Serial.begin(9600);//serial communication at 115200 baud rate
  dht.begin();// Initialize the DHT sensor
  pinMode(dht_dpin,INPUT);//Set the DHT pin as input
  pinMode(pot,INPUT);// Set the potentiometer pin as input
  pinMode(buzzer,OUTPUT);// Set the buzzer pin as output
}

void loop()
{
    // Read the humidity and temperature from the DHT sensor
    par[0]=dht.readHumidity();
    par[1]=dht.readTemperature();
    // Read the analog value from the potentiometer
    par[2]=analogRead(pot);
    // Print the sensor values to the Serial Monitor
    Serial.print(par[0]);
    Serial.print("\t");
    Serial.print(par[1]);
    Serial.print("\t");
    Serial.println(par[2]);
    // Predict the rain using the regression model based on the sensor readings
    int rain = classifier.predict(par);

    // Print the rain prediction on Serial Monitor
    Serial.print("Rain predict(%):");
    Serial.println(rain);
    //Activate the buzzer if rain rain predict is more than threshold
    if(rain>threshold)
      {
        digitalWrite(buzzer,HIGH);// Turn on the buzzer
        Serial.println("Buzzer on");
      }
    else
      {
        digitalWrite(buzzer,LOW);// Turn on the buzzer
        Serial.println("Buzzer off");

      }
    delay(2000);
    digitalWrite(buzzer,LOW);

}
