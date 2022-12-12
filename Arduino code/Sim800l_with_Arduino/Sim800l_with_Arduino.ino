#include <OneWire.h>
#include <DallasTemperature.h>
#include <SoftwareSerial.h>
#include <avr/wdt.h>

#define ONE_WIRE_BUS 13
DallasTemperature sensors(&oneWire);


SoftwareSerial sim(10, 11);
String number = "+995577651913";


int b = 0;
int i;


void setup() 
{ 
  Serial.begin(9600);
  wdt_enable(WDTO_2S);
  pinMode(5, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  sim.begin();
  sensors.begin();

  
  }


void loop() 
{

 Serial.print("Requesting temperatures...");
 sensors.requestTemperatures();
 Serial.println("DONE");
  float tempC = sensors.getTempCByIndex(0);
  if (tempC != DEVICE_DISCONNECTED_C)
  {
    Serial.print("Temperature for the device 1 (index 0) is: ");
    Serial.println(tempC);
  }
  else
  {
    Serial.println("Error: Could not read temperature data");
  }
}

    
 Serial.println(digitalRead(5));
  

    if (digitalRead(5) == HIGH)
   {
    digitalWrite(LED_BUILTIN, HIGH);
    b = 0; 
    }

    
/*if (digitalRead(5) == LOW && b < 5)
 {
  digitalWrite(LED_BUILTIN, LOW);
  wdt_disable();
   for(i = 0; i<5; i++)
    {      
      Serial.print("b = ");
      Serial.println(b);
      b++;
      Serial.print("Calling ");
      Serial.println(number);      
      callNumber();
      delay(5000);
    }
     */
  }
    delay(100);
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
