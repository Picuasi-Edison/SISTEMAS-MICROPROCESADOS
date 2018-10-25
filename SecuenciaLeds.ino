//Edison Picuasi
//DEBER 1
//SISTEMAS MICROPROCESADOS

int i=0;// variable de recorrido del vector
int leds[6]={8,9,10,11,12,13}; // defino el vector para los leds
void setup() {
for(;i<6;i++)//configuracion de modo de los pines correspondiente a los leds
{ 
pinMode(leds[i],OUTPUT);
}
i=0;//variable de reseteo de conteo

}

void loop() {
/*=================================================*/
//NUMEROS IMPARES

for(;i<6;i=i+2)
{
  digitalWrite(leds[i],HIGH);
  delay(200);
}
i=0;
delay(400);

/*=================================================*/
//NUMEROS PARES

for(i=1;i<6;i=i+2)
{
  digitalWrite(leds[i],HIGH);
  delay(200);
}
i=0;
delay(400);

/*=================================================*/
//Apagamos todos los leds pa observar mejor la secuencia
for(;i<6;i++) 
{ 
 digitalWrite(leds[i],LOW);
}
i=0;
delay(400);
/*=================================================*/

//LEDS ALEATORIOS
for(;i<=6;i++)
{
digitalWrite(leds[random(6)],HIGH);
  delay(200);  
}
i=0;
for(;i<=6;i++)
{
digitalWrite(leds[random(6)],LOW);
  delay(200);  
}
i=0;

/*=================================================*/
//Apagamos todos los leds para observar mejor la secuencia
for(;i<6;i++) 
{ 
 digitalWrite(leds[i],LOW);
}
i=0;
delay(400);
/*=================================================*/
}
