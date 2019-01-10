#include <LiquidCrystal.h>
#include <MsTimer2.h>
LiquidCrystal lcd (13,12,11,10,9,8);//configurar pines LCD
int horero=0, minutero=0, segundero=0;  //variables de conteo
void setup() {
  Serial.begin(9600);//inicializa CX
  lcd.begin(16,2);//inicializa LCD
  MsTimer2::set(1000,contador);//configura Timer2
  MsTimer2::start();//inicializa Timer2
  attachInterrupt(0,hora,FALLING);//interupcion hora
  attachInterrupt(1,minuto,FALLING);//interrupcion minuto
}

void loop() {
  lcd.clear();//limpiar LCD
  lcd.setCursor(6,0);//posicionar cursor
  lcd.print("Hora");//imprimir en LCD
  lcd.setCursor(6,1);//posicionar cursor
  lcd.print(":");//imprimir LCD
  lcd.setCursor(9,1);//posicionar cursor
  lcd.print(":");//imprimir en LCD
  
  if(horero<24){
    lcd.setCursor(4,1);//posicionar cursor
      if(horero<10)//condicion si el valor es menor a 10
        lcd.print("0");////imprimir en LCD
        lcd.print(horero);//imprimir en LCD
  }else{
    horero=0;//reiniciar variable
  }
  
  if(minutero<60){
    lcd.setCursor(7,1);//posicionar cursor
      if(minutero<10)//condicion si el valor es menor a 10
        lcd.print("0");//imprimir en LCD
        lcd.print(minutero);//imprimir en LCD
  }else{
    horero++;//incremento de variable
    minutero=0;//reiniciar variable
  }
  
  if(segundero<60){
    lcd.setCursor(10,1);//posicionar cursor
      if(segundero<10)//condicion si el valor es menor a 10
        lcd.print("0");//imprimir en LCD
        lcd.print(segundero);//imprimir en LCD
  }else{
    minutero++;//incrementar variable
    segundero=0;//reiniciar variable
  }
  delay(50);
}

void contador(){
  segundero++;//incrementar variable
  Serial.println(segundero);//imprimir en CX
}

void hora(){
  if(horero<24){
    horero++;//incrementar variable
  }else{
    horero=0;//reiniciar variable
  }
}

void minuto(){
  if(minutero<60){
    minutero++;//incrementar variable
  }else{
    minutero=0;//reiniciar variable
  }
}
