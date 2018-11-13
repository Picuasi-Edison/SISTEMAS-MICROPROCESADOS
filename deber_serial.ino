//DEBER SERIAL 2
//Picuasi Edison

//declaramos variables
int tam,i=0;// tam almacena el numero de caracteres, i variable de incremento
String palabra; //almacena el dato 
int voc=0;  //variable de incremento para las vocales

void setup() {
Serial.begin(9600); //inicializamos comunicacion serial
Serial.println("Ingrese la palabra: ");
}

void loop(){
//lectura de datos
if(Serial.available()>0){
palabra=Serial.readString(); // asignamos el string ingresado a la variable
tam=palabra.length(); //determinamos el tamaño de la palabra

//comprobacion de caracteres
  for(;i<palabra.length();i++){
      //comparamos caracter por caracter si es o no una vocal
      if(palabra.charAt(i)=='a'||palabra.charAt(i)=='e'||palabra.charAt(i)=='i'||palabra.charAt(i)=='o'||palabra.charAt(i)=='u'||palabra.charAt(i)=='A'||palabra.charAt(i)=='E'||palabra.charAt(i)=='I'||palabra.charAt(i)=='O'||palabra.charAt(i)=='U'){
      voc++; // variable de incremento para vocales
      }
    }
//impresion de resultados
    Serial.println(""); 
    Serial.print("vocales: ");
    Serial.println(voc);  // imprimimos el dato almacenado
    i=0;voc=0;  //reiniciamos las variables
  }
}

