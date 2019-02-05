
#include <MsTimer2.h>


#include <avr/power.h>
#include <avr/sleep.h>
#include <avr/wdt.h>
int on=0;
int i=0;
int conteo=0;
void setup() {
Serial.begin(9600);
set_sleep_mode(SLEEP_MODE_PWR_DOWN);
sleep_enable();
attachInterrupt(0,despertar,HIGH);
MsTimer2::set(1000,contador);//configurar Timer2
MsTimer2::start();//inicializar 

Serial.println(conteo);
}

void loop() {

}

void despertar(){
 on=1-on;
     i++;
Serial.println(i);  
Serial.println(on);  
 /* if(on==1){
 
    if(i==25){
    Serial.println("ENABLE");
    //sleep_mode();
    power_all_enable();
    }
    }else{
      power_all_disable();
      sleep_disable();
      Serial.println("DISABLE");
      }
  */
  
  }
  void contador (){
  
  conteo++;
  }

