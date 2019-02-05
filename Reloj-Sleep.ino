#include <Sleep_n0m1.h>
#include <LiquidCrystal.h>
#include <EEPROM.h>
#include <MsTimer2.h>
LiquidCrystal lcd (13,12,10,9,8,7);//configurar pines LCD
int horero=0, minutero=0, segundero=0;//variables conteo Reloj
int horeroA=0, minuteroA=0;//variables de conteo alarma
String horeroNA;//variable hora CX
String minuteroNA;//variable minuto CX
int opcion=0;//variable de seleccion
int buzzer=22;//pin buzzer
void setup() {
Serial.begin(9600);//inicializa Serial
lcd.begin(16,2);//inicializa LCD
MsTimer2::set(1000,contador);//configuracion timer
MsTimer2::start();//inicializa timer
pinMode(buzzer,OUTPUT);//configuracion pin buzzer
attachInterrupt(digitalPinToInterrupt(19),bfuncion,FALLING);//configuracion interrupcion
attachInterrupt(digitalPinToInterrupt(20),hora,FALLING);//configuracion interrupcion
attachInterrupt(digitalPinToInterrupt(21),minuto,FALLING);//configuracion interrupcion
 horero=EEPROM.read(0);//leer dato en el EEPROM
 minutero=EEPROM.read(1);//leer dato en el EEPROM
 horeroA=EEPROM.read(2);//leer dato en el EEPROM
 minuteroA=EEPROM.read(3);//leer dato en el EEPROM
 
}

void loop() {
reloj();//llama el metodo
Alarma();//llama el metodo

}

void bfuncion(){
opcion=1-opcion;//variable de estado
 switch(opcion){
    //caso 0 modificar hora de la alarma
    case 0:
    Serial.println("Modificar Hora");//imprime por mensaje por CX
    break;
    //caso 1 modificar minuto de la alarma
    case 1:
    Serial.println("Modificar Minuto");//imprime por mensaje por CX
    break;
  }
}

void reloj(){
//graficar caracteres del reloj en el LCD 
  lcd.clear();//limpiar LCD
  lcd.setCursor(0,0);//posicionar cursor
  lcd.print("Hora");//imprimir en LCD
  lcd.setCursor(8,0);//posicionar cursor
  lcd.print(":");//imprimir LCD
  lcd.setCursor(11,0);//posicionar cursor
  lcd.print(":");//imprimir en LCD
  
//graficar caracteres de la alarma en el LCD 
 
  lcd.setCursor(0,1);//posicionar cursor
  lcd.print("Alarm");//imprimir en LCD
  lcd.setCursor(8,1);//posicionar cursor
  lcd.print(":");//imprimir LCD
  lcd.setCursor(11,1);//posicionar cursor
  lcd.print(":");//imprimir en LCD

//HORA RELOJ
  if(horero<24){
    lcd.setCursor(6,0);//posicionar cursor
      if(horero<10)//condicion si el valor es menor a 10
        lcd.print("0");////imprimir en LCD
        lcd.print(horero);//imprimir en LCD
        EEPROM.write(0,horero);//escribir dato en celda de memoria
        delay(40);
  }else{
    horero=0;//reiniciar variable
  }
//MINUTOS RELOJ
  if(minutero<60){
    lcd.setCursor(9,0);//posicionar cursor
      if(minutero<10)//condicion si el valor es menor a 10
        lcd.print("0");//imprimir en LCD
        lcd.print(minutero);//imprimir en LCD
        EEPROM.write(1,minutero);//escribir dato en celda de memoria
        delay(40);
  }else{
    horero++;//incremento de variable
    minutero=0;//reiniciar variable
  }

//HORA ALARMA
  if(horeroA<24){
    lcd.setCursor(6,1);//posicionar cursor
      if(horeroA<10)//condicion si el valor es menor a 10
        lcd.print("0");////imprimir en LCD
        lcd.print(horeroA);//imprimir en LCD
        EEPROM.write(2,horeroA);//escribir dato en celda de memoria
        delay(40);
  }else{
    horeroA=0;//reiniciar variable
  }
//MINUTOS ALARMA
  if(minuteroA<60){
    lcd.setCursor(9,1);//posicionar cursor
      if(minuteroA<10)//condicion si el valor es menor a 10
        lcd.print("0");//imprimir en LCD
        lcd.print(minuteroA);//imprimir en LCD
        EEPROM.write(3,minuteroA);//escribir dato en celda de memoria
        delay(40);
  }else{
    horeroA++;//incremento de variable
    minuteroA=0;//reiniciar variable
  }
  if(segundero<60){
    lcd.setCursor(12,0);//posicionar cursor
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
}


void minuto(){
  if(minutero<60){
    minutero++;//incrementar variable
    EEPROM.update(1,minutero);//actualizar celda de memoria
    delay(40);
  }else{
    minutero=0;//reiniciar variable
  } 
}


void minutoA(){
 if(Serial.available()>0){
  minuteroNA = Serial.readString();//lectura de datos por serial
  minuteroA=String(minuteroNA).toInt();//conversion de dato a tipo INT
 EEPROM.update(3,minuteroA);//actualiza la celdad de memoria del minuto de la alarma
//delay(40);
}
}

void hora(){
  if(horero<24){
    horero++;//incrementar variable
    EEPROM.update(0,horero);//actualizar celda de memoria
    delay(40);
  }else{
    horero=0;//reiniciar variable
  }

}
void horaA(){
  if(Serial.available()>0){
  horeroNA = Serial.readString();//lectura de datos por serial
  horeroA=String(horeroNA).toInt();//conversion de dato a tipo INT
 EEPROM.update(2,horeroA);//actualiza la celdad de memoria de la hora de la alarma
//delay(40);
}
}

void Alarma(){
  //verificar si la interrupcion bfuncion es igual a cero(ingreso hora)
  if(opcion==0){
    horaA();//llamamos al metodo hora de la alarma
    }
  //verificar si la interrupcion bfuncion es igual a uno (ingreso minuto)
 if(opcion==1){
    minutoA();//llamamos al metodo minuto de la alarma
    }
  

  }

 void  pwrSaveMode () { 
  //reloj();
  }
  

