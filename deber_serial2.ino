int tam,i=0,ntam;
char opcion,vector1,vector2;
String cedula,ncedula;
int voc=0;
int boton=2;

void setup() {
Serial.begin(9600);
pinMode(boton,INPUT);
Serial.println("OPCION:");
Serial.println("1. Ingresar cedula: ");
Serial.println("2. Validar cedula: ");
}

void loop(){
  if(Serial.available()>0){
  opcion=Serial.read();
  }//recibe datos

switch (opcion){
  case 'A':
  //Serial.println("1. Ingresar cedula: ");
  if(Serial.available()>0){
  cedula=Serial.readString();
  tam=cedula.length();
  char vector1[tam];
  cedula.toCharArray(vector1,tam);
  Serial.println(vector1[tam]);
  }
  break;
  case 'B':
  //Serial.println("2. Validar cedula: ");
  if(Serial.available()>0){
  ncedula=Serial.readString();
  ntam=ncedula.length();
  char vector2[ntam];
  ncedula.toCharArray(vector2,ntam);
  Serial.println(vector2[ntam]);
  
  for(;i<ncedula.length();i++){
      
      }
    }
  
  break;
  
}
  }
