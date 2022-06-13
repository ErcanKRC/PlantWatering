
#define BLYNK_TEMPLATE_ID "TMPLPRtRdPSl"
#define BLYNK_DEVICE_NAME "Smart table"
#define BLYNK_PRINT Serial
#define BLYNK_AUTH_TOKEN "o2PXXZIDPZLNGCK5HhSL02auSlXtNxio"

#define Sensor A0
#define Relay 12

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>


char ssid[] = "***";
char pass[] = "***";

//char ssid[] = "***";
//char pass[] = "***";

int sensorValue;
int outputValue;
int butondurumu = 0;
int soilmoisture;

void setup()
{
  Serial.begin(9600);
  Blynk.begin("***", ssid, pass);
  pinMode(Sensor, INPUT);
  pinMode(Relay, OUTPUT);
}


void loop()
{
  sensorValue = analogRead(Sensor);
  outputValue = map(sensorValue, 0, 1023, 0, 100);
  soilmoisture=100-outputValue;
  Serial.print(outputValue);
  Serial.print("-");
  Serial.print(sensorValue);
  Serial.print("-");
  Serial.println(soilmoisture);
  delay(1000);

  Blynk.virtualWrite(V0,soilmoisture);
  
  
  Blynk.run();
}
BLYNK_WRITE(V1) // Executes when the value of virtual pin 0 changes
{
  if(param.asInt() == 1)
  {
    // execute this code if the switch widget is now ON
    digitalWrite(13,HIGH);  // Set digital pin 2 HIGH
  }
  else
  {
    // execute this code if the switch widget is now OFF
    digitalWrite(13,LOW);  // Set digital pin 2 LOW    
  }
}
