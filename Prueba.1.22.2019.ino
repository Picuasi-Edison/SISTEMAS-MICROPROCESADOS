#include <MsTimer2.h>
#include <EEPROM.h>
///botones
int boton1=1;
int boton2=2;
int boton3=3;
int on=0;
int cont=0;
int i=0;
int j=0;
int pulsacion;
int variable=1;
char pass [5]={EEPROM.read(4),EEPROM.read(5),EEPROM.read(6),EEPROM.read(7),EEPROM.read(8)};
char passre[5];
char estado;

void setup() {
Serial.begin(9600);//inicializar CX
MsTimer2::set(1000,contador);//configurar Timer2
MsTimer2::start();//inicializar Timer2
pinMode(3,INPUT);//1
pinMode(4,INPUT);//2
pinMode(5,INPUT);//3
attachInterrupt(0,master,FALLING);

////////////////////////
/*
    EEPROM.update(4,1);
    EEPROM.update(5,3);
    EEPROM.update(6,3);
    EEPROM.update(7,2);
    EEPROM.update(8,1);
 */   
/////////////////
/*
    Serial.println(EEPROM.read(4));
    Serial.println(EEPROM.read(5));
    Serial.println(EEPROM.read(6));
    Serial.println(EEPROM.read(7));
    Serial.println(EEPROM.read(8));
*/

////////////////////////
/*
    EEPROM.update(4,1);
    EEPROM.update(5,3);
    EEPROM.update(6,3);
    EEPROM.update(7,2);
    EEPROM.update(8,1);
 */   
/////////////////
   
   
  
    
}

void loop() {


if(on==1){
 if(EEPROM.read(4)==EEPROM.read(10)&&
      EEPROM.read(5)==EEPROM.read(11)&&
      EEPROM.read(6)==EEPROM.read(12)&&
      EEPROM.read(7)==EEPROM.read(13)&&
      EEPROM.read(8)==EEPROM.read(14)){


  
  Serial.println("Se puede encender carro"); 
}
  }
  
}

void master(){
on=1-on;
pulsacion++;

if(on==1){
  Serial.println("Activado");//impresion msg en CX
}else{
  Serial.println("Desactivado");//impresion msg en CX
  }

}

void contador(){

  if(digitalRead(3)==HIGH){
  boton1=1;
  i++;
  }
 if(digitalRead(4)==HIGH){
  boton2=2;
  i++;
  
  } 
  
  if(digitalRead(5)==HIGH){
  boton3=3;
  i++;
  }

  comprobar();
  }

void comprobar(){
  
  if(digitalRead(3)||digitalRead(4)||digitalRead(5)==HIGH){
    j++;
  }

  for(;j<5;j++){

    passre[j]=boton1||boton2||boton3;
    EEPROM.update(10,passre[0]);
    EEPROM.update(11,passre[1]);
    EEPROM.update(12,passre[2]);
    EEPROM.update(13,passre[3]);
    EEPROM.update(14,passre[4]);
    Serial.println(EEPROM.read(10));
    Serial.println(EEPROM.read(11));
    Serial.println(EEPROM.read(12));
    Serial.println(EEPROM.read(13));
    Serial.println(EEPROM.read(14));
    Serial.println(passre[j]);


    checkPassword();
    }
    
    
    }
  

void checkPassword(){

  if (EEPROM.read(4)==EEPROM.read(10)&&
      EEPROM.read(5)==EEPROM.read(11)&&
      EEPROM.read(6)==EEPROM.read(12)&&
      EEPROM.read(7)==EEPROM.read(13)&&
      EEPROM.read(8)==EEPROM.read(14)){

if(pulsacion<3){
        
    Serial.println("Se puede encender carro");    
    }
      }
}

