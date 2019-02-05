/*
MODOS SLEEP
Libreruas: <avr/power.h>
             <avr/sleep.h>

*Modos sleep
*set_sleep_mode(mode);
*                     mode: SLEEP_MODE_IDLE--->dormir la memoria del program
*                           SLEEP_MODE_ADC--->Dormir adc
*                           SLEEP_MODE_PWR_SAVE--->dormir memorias
*                           SLEEP_MODE_STANDBY--->modo de ahorro
*                           SLEEP_MODE_PWR_DOWN-->dormir al IC

CONFIGURACIONES

sleep_enable();--->habilita la entrada de modos sleep
sleep_disable();--->deshabilita el modo sleep
power_xx_enable/disable();
                        power_adc_disable/enable();
                        power_spi_disable/enable();
                        power_txi_disable/enable();
                        power_timer0_disable/enable();
                        power_all_disable/enable();

sleep_enable();
sleep_disable();           


en esta pagina esta todo lo referente a power sleep


           
*/
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
