//EDISON PICUASI
//DEBER WATCHDOG
#include <LiquidCrystal.h>//Anadir libreria lcd
#include <MsTimer2.h>//Anadir libreria timer2
#include<avr/wdt.h>//Anadir watchdog


LiquidCrystal lcd (13,12,11,10,9,8);//configurar pines lcd
int cad,cadr;//variable de cad y variable de rango
int cont=0;//variable conteo
void setup() {
Serial.begin(9600);//inicializar CX
lcd.begin(16,2);//inicializar lcd
MsTimer2::set(1000,contador);//configurar Timer2
MsTimer2::start();//inicializar Timer2
}
void loop() {
cadr=(analogRead(A0)*32)/1023;//lectura del conversor CAD
cad=cadr*1.25;//establecer rango de muestreo
Serial.print("CAD:");// impresion en CX
Serial.println(cad);// impresion valor cad en CX

lcd.clear();//limpiar lcd
lcd.setCursor(0,0);//posicionar cursor del lcd
lcd.print("CAD:");//impresion msg en lcd
lcd.setCursor(7,0);//posicionar cursor del lcd
lcd.print(cad);//impresion valor cad en lcd
lcd.setCursor(0,1);//posicionar cursor del lcd
lcd.print("Time:");//impresion msg en lcd
lcd.setCursor(7,1);//posicionar cursor del lcd
lcd.print(cont);//impresion valor del contador en lcd
delay(200);
 }

void contador(){
  //comparar valor del cad
if(cad==10||cad==20||cad==30||cad==40){
  cont++;//incrementar contador
  Serial.print("Timer:");//impresion msg en CX
  Serial.println(cont);   //impresion valor de conteo en CX
}else{
  cont=0;//reiniciar variable de conteo
  
  }
//comparar valor cad y valor de vonteo
 if(cad==10&&cont==10||cad==20&&cont==20||cad==30&&cont==30||cad==40&&cont==40){
    wdt_enable(WDTO_15MS);//iniciar watchdog en 15 ms
    cont=0;//reiniciar contador
    }

  }
