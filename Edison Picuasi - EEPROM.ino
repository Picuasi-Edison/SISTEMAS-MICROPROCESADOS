#include <LiquidCrystal.h>
#include <EEPROM.h>
LiquidCrystal lcd (13,12,11,10,9,8);//configurar pines LCD
int opcion=0;//variable de opciones interrupcion
int valor=0;//variable de almacenaje
int com_val=0;//variable comprobacion
String in_val;//variable hora CX

void setup() {
Serial.begin(9600);//inicializa Serial
lcd.begin(16,2);//inicializa LCD
valor=EEPROM.read(0);//leer dato en el EEPROM
attachInterrupt(digitalPinToInterrupt(2),bfuncion,FALLING);//configuracion interrupcion
//EEPROM.write(0,12);
Serial.println("INICIO:");//Imprime por CX mensaje de inicio
}

void loop() {
graficar();//Llamamos al metodo
Ingreso();//Llamamos al metodo
Comprobar();  //Llamamos al metodo
}


void bfuncion(){
opcion=1-opcion;//variable de estado
 switch(opcion){
    //caso 0 modificar hora de la alarma
    case 0:
    Serial.println("Ingresar Valor:");//imprime por mensaje por CX
    
    break;
    //caso 1 modificar minuto de la alarma
    case 1:
    Serial.println("Comprobar:");//imprime por mensaje por CX
    
    break;
  }
}
void Ingreso(){
 if(opcion==0){ 
 if(Serial.available()>0){
  in_val = Serial.readString();//lectura de datos por serial
  com_val=String(in_val).toInt();//conversion de dato a tipo INT
  EEPROM.write(1,com_val); //almacena valor
 }
}
}
void Comprobar(){
  if(opcion==1){
    //COMPRUEBA CELDA DE MEMORIA 1 y 2
  if(EEPROM.read(1)>EEPROM.read(0)){
   EEPROM.update(0,com_val);//actualiza el valor
   Serial.println("Cumple:");//Imprime mensaje CX
   Serial.println(EEPROM.read(0));//imprime por CX
  }
  }
  }
void graficar(){
//graficar caracteres del reloj en el LCD 
  lcd.clear();//limpiar LCD
  lcd.setCursor(0,0);//posicionar cursor
  lcd.print("Almacenado");//imprimir en LCD
  lcd.setCursor(12,0);//posicionar cursor
  lcd.print(EEPROM.read(0));//imprimir LCD
  delay(60);
}
