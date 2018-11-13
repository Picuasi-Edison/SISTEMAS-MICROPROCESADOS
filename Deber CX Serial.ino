//DEBER CX SERIAL
// EDISON PICUASI

int tam,i=0,j=0,ntam;
char cedula[11],vector1,vector2;
String ncedula;
int voc=0;

void setup() {
Serial.begin(9600); //inicializamos comunicacion serial
Serial.println("OPCION:");
Serial.println("1. Ingresar cedula: ");

//Ingreso de cedula
for(;j<11;j){
  if(Serial.available()>0){
   cedula[j]=Serial.read();
   j++;
   Serial.println(cedula[j]);
   

    }
  
  }
}

void loop(){
//leectura de datos en serial
  if(Serial.available()>0){
  ncedula=Serial.readString(); //asignamos los datos de serial a la variable
  ntam=ncedula.length();//determinamos el tamano de la palabra
  char vector1[ntam]; //creamos a un vector
  ncedula.toCharArray(vector1,ntam);//asignamos los caracteres de la palabra al vector
//Coomprobamos caracter por caracter  
  for(;i<ncedula.length();i++){
if(ncedula.charAt(i)==cedula[0]&&ncedula.charAt(i)==cedula[1]&&ncedula.charAt(i)==cedula[2]&&ncedula.charAt(i)==cedula[3]&&ncedula.charAt(i)==cedula[4]&&ncedula.charAt(i)==cedula[5]&&ncedula.charAt(i)==cedula[6]&&ncedula.charAt(i)==cedula[7]&&ncedula.charAt(i)==cedula[8]&&ncedula.charAt(i)==cedula[9]&&ncedula.charAt(i)==cedula[10]&&ncedula.charAt(i)==cedula[11]){        
        Serial.println("CORRECTO"); //impresion de resultado
      }else
           
        Serial.println("INCORRECTO");  //impresion de resultado
    }
  
 //Serial.println(ncedula);
  
}}
