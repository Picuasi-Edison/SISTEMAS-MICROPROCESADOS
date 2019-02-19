#include <MsTimer2.h>
#include<avr/wdt.h>//avr

int dip1=13;
int dip2=12;
int on=0;
int i=0;
int opc=0;
void setup() {
Serial.begin(9600);
pinMode(12,INPUT);
pinMode(13,INPUT);
attachInterrupt(0,estados,FALLING);
MsTimer2::set(1000,timer);
MsTimer2::start();
}

void loop() {

}

void estados(){
on=1-on;
if(on==1){
  opciones();
  i=0;
  } 

  }

void opciones(){
  
  if(digitalRead(dip1)==LOW&&digitalRead(dip2)==LOW){
    Serial.println("ESTADO 0");
    delay(200);
    opc=1;
    }
  if(digitalRead(dip1)==HIGH&&digitalRead(dip2)==LOW){
    
    Serial.println("ESTADO 1");
   
delay(200);
opc=2;
    }
    
   if(digitalRead(dip1)==LOW&&digitalRead(dip2)==HIGH){
    
    Serial.println("ESTADO 2");
 delay(200);
 opc=3;
    }
  
   if(digitalRead(dip1)==HIGH&&digitalRead(dip2)==HIGH){
    
    Serial.println("ESTADO 3");
delay(200);
opc=4;
    }
  }

void timer(){
 
Serial.println(i);
i++;
if(opc==1){
if(i==0){
  
  
  }
}

if(opc==2){
if(i==2){
  Serial.println("WD 2s");
 wdt_enable(WDTO_15MS);
}else{
  
    wdt_disable();
  MsTimer2::stop();
  //i=0;
  }
}

if(opc==3){
if(i==4){
  Serial.println("WD 4s");
  wdt_enable(WDTO_15MS);
  i=0;
  }
}

if(opc==4){
if(i==8){
  Serial.println("WD 8s");
  wdt_enable(WDTO_15MS);
   i=0;
  }
}

  }
