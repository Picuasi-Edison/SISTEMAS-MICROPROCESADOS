//PICUASI EDISON
// Deber2

int leds[] = {13,12,11,10,9,8}; //asignamos los pines para los leds
int sw1=7,sw2=6,sw3=5,sw4=4,sw5=3,boton=2;//asignamos los pines para las entradas digitales
int i=0;
int j=0;
int contador=0;
int on=0;
void setup()
{
  Serial.begin(9600);
  //inicializamos los pines
  pinMode(sw1,INPUT);
  pinMode(sw2,INPUT);
  pinMode(sw3,INPUT); 
  pinMode(sw4,INPUT);
  pinMode(sw5,INPUT);
  pinMode(boton,INPUT);
  //inicializamos los leds
  for (;i<6;i++){
  pinMode(leds[i], OUTPUT);
  }
}
 
void loop()
{
juegos();
}
void juegos()
{
  /*------- JUEGO 1 -------*/
  if (digitalRead(sw1)==HIGH)
  {
    //NUMEROS IMPARES
    for(;i<6;i=i+2)
    {
      digitalWrite(leds[i],HIGH);
      delay(200);
    }
    i=0;
    delay(400);

  }
  /*------- JUEGO 2 -------*/
  if (digitalRead(sw2)==HIGH)
  {
    //NUMEROS PARES
    for(i=1;i<6;i=i+2)
    {
      digitalWrite(leds[i],HIGH);
      delay(200);
    }
    i=0;
    delay(400);
  }
  /*------- JUEGO 3 -------*/
  if (digitalRead(sw3)==HIGH)
  {
    //APAGAMOS Y PRENDEMOS TODOS LOS LEDS
    for(;i<6;i++)
    {
      digitalWrite(leds[i],HIGH);
      delay(300);
      digitalWrite(leds[i],LOW);
      delay(300);
    }
      i=0;
  }
  /*------- JUEGO 4 -------*/
  if (digitalRead(sw4)==HIGH)
  {

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

  }
  /*------- JUEGO 5 -------*/
  if (digitalRead(sw5)==HIGH)
  {
    if(digitalRead(boton)==LOW)
    {
      delay(200);
      on=1-on;
        if(on==1)
        {
        contador++;
        Serial.println(contador);
        }
        if(contador==32)
        {
        j=0;
        }
          j=contador;
          for(i=0;i<=5;i++)
          {
          digitalWrite(leds[i],j%2);
          j=j/2;
          }
    }   
  }
}


