int A=5;  // pin de salida para display
int B=4;  // pin de salida para display
int C=3;  // pin de salida para display
int D=2;  // pin de salida para display
int i=0;  // variable de conteo
int cen=9;  // pin de activacion centenas
int dec=8;  // pin de activacion decenas
int uni=7;  //pin de activacion unidades
int centenas; // variable de almacenamiento de centenas
int decenas; // variable de almacenamiento de decenas
int unidades; // variable de almacenamiento de unidades
void setup(){
 pinMode(A,OUTPUT); // configuracion de pin
 pinMode(B,OUTPUT); // configuracion de pin
 pinMode(C,OUTPUT); // configuracion de pin
 pinMode(D,OUTPUT); // configuracion de pin
pinMode(cen,OUTPUT); // configuracion de pin
pinMode(dec,OUTPUT); // configuracion de pin
pinMode(uni,OUTPUT); // configuracion de pin

}

void loop(){
if(i<200)// aumento de variable
{
     i++; //valor de aumento
     centenas=i/100;  //valor centenas
     decenas=(i-(centenas*100))/10;  //valor de decenas
     unidades= i-(centenas*100+decenas*10); //valor unidades
}
else{
    i=0; // reset conteo
    centenas=0;  //reset centenas
    decenas=0;  // reset decenas
    unidades=0; // reset unidades
}
digitalWrite(cen,HIGH); //activacion de pin de centenas
 digitalWrite(dec,LOW); //desactivacion de pin de decenas
 digitalWrite(uni,LOW); //desactivacion de pin de unidades
 contador(centenas);
 delay(100);  // espero
 digitalWrite(cen,LOW); //desactivacion de pin de centenas
 digitalWrite(dec,HIGH);  //activacion de pin de decenas
 digitalWrite(uni,LOW);  //desactivacion de pin de unidades
 contador(decenas);    // llamo metodo de visualizacion
 delay(100);  // espero
 digitalWrite(cen,LOW); //desactivacion de pin de centenas
digitalWrite(dec,LOW);  // desactivacion de pin de decenas
 digitalWrite(uni,HIGH);  // activacion de pin de unidades
 contador(unidades);  // llamo metodo de visualizacion
 delay(100); // espero
}


void contador (int j){
switch(j){
  //0
  case 0:
digitalWrite(A,LOW);
digitalWrite(B,LOW);
digitalWrite(C,LOW);
digitalWrite(D,LOW);
break;
//1
 case 1:
digitalWrite(A,HIGH);
digitalWrite(B,LOW);
digitalWrite(C,LOW);
digitalWrite(D,LOW);
break;
//2
case 2:
digitalWrite(A,LOW);
digitalWrite(B,HIGH);
digitalWrite(C,LOW);
digitalWrite(D,LOW);
break;
//3
case 3:
digitalWrite(A,HIGH);
digitalWrite(B,HIGH);
digitalWrite(C,LOW);
digitalWrite(D,LOW);
break;
//4
case 4:
digitalWrite(A,LOW);
digitalWrite(B,LOW);
digitalWrite(C,HIGH);
digitalWrite(D,LOW);
break;
//5
case 5:
digitalWrite(A,HIGH);
digitalWrite(B,LOW);
digitalWrite(C,HIGH);
digitalWrite(D,LOW);
break;
//6
case 6:
digitalWrite(A,LOW);
digitalWrite(B,HIGH);
digitalWrite(C,HIGH);
digitalWrite(D,LOW);
break;
//7
case 7:
digitalWrite(A,HIGH);
digitalWrite(B,HIGH);
digitalWrite(C,HIGH);
digitalWrite(D,LOW);
break;
//8
case 8:
digitalWrite(A,LOW);
digitalWrite(B,LOW);
digitalWrite(C,LOW);
digitalWrite(D,HIGH);
break;
//9
case 9:
digitalWrite(A,HIGH);
digitalWrite(B,LOW);
digitalWrite(C,LOW);
digitalWrite(D,HIGH);
break;
}
}
