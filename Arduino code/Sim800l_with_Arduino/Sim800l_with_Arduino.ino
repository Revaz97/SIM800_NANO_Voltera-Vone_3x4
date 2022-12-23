#include <OneWire.h>
#include <DallasTemperature.h>

#include <SoftwareSerial.h>
#include <avr/wdt.h>

#define Relay1 6
#define Relay2 7
#define Mains_sence 5
#define ONE_WIRE_BUS 12

DallasTemperature sensors(&oneWire);

SoftwareSerial sim(2, 3);
String number = "+995577651913";

int b = 0;
int i;


void setup() 
{ 
  Serial.begin(9600);
  wdt_enable(WDTO_2S);

  pinMode (Mains_sence, INPUT)
  pinMode (Relay1, OUTPUT)
  pinMode (Relay2, OUTPUT)  

  sim.begin();
  sensors.begin();
}

void loop() 
{
  if (Mains_sence == 1)
  {
    SendSMS
  }
  delay(10);
  wdt_reset(); 
}


void callNumber() 
{
  sim.print (F("ATD"));
  sim.print (number);
  sim.print (F(";\r\n"));
}

void SendStatusSMS() 
{
  sim.print ("AT+CMGF=1");
  sim.print ("AT+CMGS=\"+995577651913\"");
  sim.print (status);
}



void Relay1_restart()
{
  digitalWrite(Relay1, LOW)
  delay (5000);
  digitalWrite(Relay1, HIGH)
}

void Relay2_restart()
{
  digitalWrite(Relay2, LOW)
  delay (5000);
  digitalWrite(Relay2, HIGH)
}



void GetTemp()
{
  Serial.print("Requesting temperatures...");
 sensors.requestTemperatures();
 Serial.println("DONE");
  float tempC = sensors.getTempCByIndex(0);
  if (tempC != DEVICE_DISCONNECTED_C)
  {
    Serial.print("Temperature for the device 1 is: ");
    Serial.println(tempC);
  }
  else
  {
    Serial.println("Error: Could not read temperature data");
  }
}
