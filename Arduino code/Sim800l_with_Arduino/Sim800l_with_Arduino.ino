#include <SoftwareSerial.h>
#include <avr/wdt.h>
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
  
  
  }


void loop() 
{
  sim.begin(9600);
  Serial.println(digitalRead(5));
  

    if (digitalRead(5) == HIGH)
   {
    digitalWrite(LED_BUILTIN, HIGH);
    b = 0; 
    }

    
if (digitalRead(5) == LOW && b < 5)
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
      delay(75000);
    }
     
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
