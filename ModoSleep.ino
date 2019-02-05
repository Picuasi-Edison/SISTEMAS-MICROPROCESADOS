#include <avr/power.h>
#include <avr/sleep.h>
#include <avr/wdt.h>
int on=0;

void setup() {
Serial.begin(9600);
set_sleep_mode(SLEEP_MODE_PWR_DOWN);
sleep_enable();
attachInterrupt(0,despertar,LOW);
wdt_enable(WDTO_8S);
}

void loop() {
Serial.println("LEVANTAR");
delay(1000);
sleep_mode();
sleep_disable();
delay(1000);
Serial.println("DESPIERTO");




//Serial.println(analogRead(0));
//delay(200);
}

void despertar(){
  
  on=1-on;

  if(on==1){
    Serial.println("ENABLE");
    power_all_enable();

    }else{
      power_all_disable();
      Serial.println("DISABLE");
      }
  
  
  }
