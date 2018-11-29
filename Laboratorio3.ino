int A=7,B=6,C=5,D=4;// pines de los leds
int on=0;
int i=0;
int dec=9;
int uni=8;
int unidades,decenas;
float cad;
float conversion;
String palabra;
int tam;
int valor;
void setup() {
Serial.begin(9600);
pinMode(A,OUTPUT);
pinMode(B,OUTPUT);
pinMode(C,OUTPUT);
pinMode(D,OUTPUT);
pinMode(uni,OUTPUT);
pinMode(dec,OUTPUT);
attachInterrupt(0,sistema,FALLING);
Serial.println("Ingrese el valor maximo");

}

void loop() {

if(Serial.available()>0){
    palabra=Serial.readString(); // asignamos el string ingresado a la variable
    }
  
  if(on==1){
    
    cad=analogRead(A0);
    conversion=(palabra.toFloat()*cad)/1023;
    valor=conversion*10; //convertimos el dato en un numero entero
    unidades=valor/10; //Valor de las unidades
    decenas=valor-(unidades*10); //Valor decimal
    digitalWrite(dec,HIGH); // activacion de pin del decimal
    digitalWrite(uni,LOW); // desactivacion de pin de unidades
    numeros(decenas); // llamo metodo para visualizar el decimal
    delay(50);
    digitalWrite(dec,LOW);// desactivacion de pin del decimal
    digitalWrite(uni,HIGH); // activacion de pin de unidades
    numeros(unidades); // llamo metodo para visualizar las unidades
    delay(50);
    Serial.println(conversion);// Impresion del valor del voltaje en CX
    delay(300);
      
    }
}

void sistema(){
on=1-on;
if(on==1){ //SISTEMA ON
   Serial.println("");
   Serial.println("SISTEMA ON"); //Impresion SISTEMA ON en CX
 }
 else{ //SISTEMA OFF
    Serial.println("SISTEMA OFF");  //Impresion SISTEMA OFF en CX
    on=0; // Inicializacion de variable
    digitalWrite(uni,LOW); // Pin de unidades apagado
    digitalWrite(dec,LOW); //Pin de decimales apagado
     
    } 
  
  
}
void numeros(int j){
  switch(j){
case 0:
  //digito 0
digitalWrite(A,LOW);
digitalWrite(B,LOW);
digitalWrite(C,LOW);
digitalWrite(D,LOW);
break;
case 1:
//digito 1
digitalWrite(A,HIGH);
digitalWrite(B,LOW);
digitalWrite(C,LOW);
digitalWrite(D,LOW);
break;
case 2:
//digito 2
digitalWrite(A,LOW);
digitalWrite(B,HIGH);
digitalWrite(C,LOW);
digitalWrite(D,LOW);
break;
case 3:
//digito 3
digitalWrite(A,HIGH);
digitalWrite(B,HIGH);
digitalWrite(C,LOW);
digitalWrite(D,LOW);
break;
case 4:
//digito 4
digitalWrite(A,LOW);
digitalWrite(B,LOW);
digitalWrite(C,HIGH);
digitalWrite(D,LOW);
break;
case 5:
//digito 5
digitalWrite(A,HIGH);
digitalWrite(B,LOW);
digitalWrite(C,HIGH);
digitalWrite(D,LOW);
break;
case 6:
//digito 6
digitalWrite(A,LOW);
digitalWrite(B,HIGH);
digitalWrite(C,HIGH);
digitalWrite(D,LOW);
break;
case 7:
//digito 7
digitalWrite(A,HIGH);
digitalWrite(B,HIGH);
digitalWrite(C,HIGH);
digitalWrite(D,LOW);
break;
case 8:
//digito 8
digitalWrite(A,LOW);
digitalWrite(B,LOW);
digitalWrite(C,LOW);
digitalWrite(D,HIGH);
break;
case 9:
//digito 9
digitalWrite(A,HIGH);
digitalWrite(B,LOW);
digitalWrite(C,LOW);
digitalWrite(D,HIGH);
break;
}
  
}
