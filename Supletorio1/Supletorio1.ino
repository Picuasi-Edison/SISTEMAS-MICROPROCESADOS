#include <MsTimer2.h>
#include<avr/wdt.h>//avr

#include <avr/power.h>
#include <avr/sleep.h>
int funcionamiento=0;// variable de interrupcion cero
String dato;  // variable de RX serial
int conversion; // dato conversor de rx serial
int cad; // dato que recibe CAD

int led=11;
int i;
void setup() {
 Serial.begin(9600);
 pinMode(11,OUTPUT);
 attachInterrupt(0,sistema,FALLING);
  MsTimer2::set(1000,timer);
     MsTimer2::start();
}

void loop() {
    if(Serial.available()>0){
      dato=Serial.readString();
      conversion=dato.toInt();
      }
    
cad=analogRead(0);
cad=map(cad,0,1023,0,conversion);
delay(400);
Serial.println(cad);


}

void timer(){

  Serial.println(i);
  if(cad>10){
  i++;
  digitalWrite(11,HIGH);
  if(i==5){
    power_adc_disable();
  
  }
  }
}

void sistema(){
  
  digitalWrite(11,LOW);
  i=0;
   power_adc_enable();
  
  
  }
