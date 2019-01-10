#include <LiquidCrystal.h>
#include <EEPROM.h>
#include <MsTimer2.h>
LiquidCrystal lcd (12,10,9,8,7,6);//configurar pines LCD
int horero=0, minutero=0, segundero=0;//variables conteo Reloj
int horeroA=0, minuteroA=0;//variables de conteo alarma
int opcion=0;//variable de seleccion
int mod=0;//variable de seleccion
int buzzer=22;//pin buzzer
void setup() {
Serial.begin(9600);//inicializa Serial
lcd.begin(16,2);//inicializa LCD
MsTimer2::set(1000,contador);//configuracion timer
MsTimer2::start();//inicializa timer
pinMode(buzzer,OUTPUT);//configuracion pin buzzer
attachInterrupt(digitalPinToInterrupt(19),bfuncion,FALLING);//configuracion interrupcion
attachInterrupt(digitalPinToInterrupt(20),modificar,FALLING);//configuracion interrupcion
attachInterrupt(digitalPinToInterrupt(21),aumentar,FALLING);//configuracion interrupcion
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
opcion=1-opcion;
 switch(opcion){
    case 0:
    Serial.println("Modificar Hora");
    break;
    case 1:
    Serial.println("Crear Alarma");
    break;
  }
}

void modificar(){
mod=1-mod;
 switch(mod){
    case 0:
    Serial.println("Hora");
    break;
    case 1:
    Serial.println("Minuto");
    break;
  }
}

void aumentar(){
//Modificar hora del reloj
  if(opcion==0&&mod==0){
    hora();//llama el metodo
    }
//Modificar minutos del reloj
  if(opcion==0&&mod==1){
    minuto();//llama el metodo
    }
//Modificar hora de la alarma
    if(opcion==1&&mod==0){
    horaA();//llama el metodo
    }
//Modificar hora de la alarma
  if(opcion==1&&mod==1){
    minutoA();//llama el metodo
    }
  }
void reloj(){

  lcd.clear();//limpiar LCD
  lcd.setCursor(0,0);//posicionar cursor
  lcd.print("Hora");//imprimir en LCD
  lcd.setCursor(8,0);//posicionar cursor
  lcd.print(":");//imprimir LCD
  lcd.setCursor(11,0);//posicionar cursor
  lcd.print(":");//imprimir en LCD

  
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
        EEPROM.write(1,horero);//escribir dato en celda de memoria
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
        EEPROM.write(0,minutero);//escribir dato en celda de memoria
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
        EEPROM.write(3,horeroA);//escribir dato en celda de memoria
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
        EEPROM.write(2,minuteroA);//escribir dato en celda de memoria
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
    EEPROM.update(0,minutero);//actualizar celda de memoria
    delay(40);
  }else{
    minutero=0;//reiniciar variable
  } 
}


void minutoA(){
  if(minuteroA<60){
    minuteroA++;//incrementar variable
    EEPROM.update(2,minuteroA);//actualizar celda de memoria
    delay(40);
  }else{
    minuteroA=0;//reiniciar variable
  }
  
}

void hora(){
  if(horero<24){
    horero++;//incrementar variable
    EEPROM.update(1,horero);//actualizar celda de memoria
    delay(40);
  }else{
    horero=0;//reiniciar variable
  }

}
void horaA(){
  if(horeroA<24){
    horeroA++;//incrementar variable
    
    EEPROM.write(3,horeroA);//actualizar celda de memoria
    delay(40);
  }else{
    horeroA=0;//reiniciar variable
  }

}

void Alarma(){
  if(EEPROM.read(0)==EEPROM.read(2)&&EEPROM.read(1)==EEPROM.read(3)){
    tono();//llamamos al metodo
    Serial.println("DESPIERTA");//Impresion por serial
    }
  }

  void tono(){  
  digitalWrite(buzzer,HIGH);//encender buzzer
  delay(100);
  
  }
