
#include "Arduino.h"
#include "DFRobotDFPlayerMini.h"
int contador=0;
#define Boton_Derecha 5
#define Boton_Izquierda 3
#define Boton_Central 4
#if (defined(ARDUINO_AVR_UNO) || defined(ESP8266))   // Using a soft serial port
#include <SoftwareSerial.h>
SoftwareSerial softSerial(/*rx =*/10, /*tx =*/11);
#define FPSerial softSerial
#else
#define FPSerial Serial1
#endif
DFRobotDFPlayerMini myDFPlayer;
void printDetail(uint8_t type, int value);

void setup()
{

  FPSerial.begin(9600);
  Serial.begin(115200);
  pinMode (Boton_Derecha, INPUT_PULLUP);
   pinMode (Boton_Izquierda, INPUT_PULLUP);
  pinMode (Boton_Central, INPUT_PULLUP);
  Serial.println();
  Serial.println(F("DFRobot DFPlayer Mini Demo"));
  Serial.println(F("Initializing DFPlayer ... (May take 3~5 seconds)"));
  
  if (!myDFPlayer.begin(FPSerial, /*isACK = */true, /*doReset = */true)) {  //Use serial to communicate with mp3.
    Serial.println(F("Unable to begin:"));
    Serial.println(F("1.Please recheck the connection!"));
    Serial.println(F("2.Please insert the SD card!"));
    while(true){
      delay(0); // Code to compatible with ESP8266 watch dog.
    }
  }
  Serial.println(F("DFPlayer Mini online."));
  
  myDFPlayer.volume(10);  //Set volume value. From 0 to 30
  myDFPlayer.play(1);  //Play the first mp3
}

void loop()
{
  bool pausa_Central = digitalRead(Boton_Central);
  bool pausaval = digitalRead(Boton_Izquierda);
  bool Cambio_de_cancion=digitalRead (Boton_Derecha);
  delay (100);
  if (Cambio_de_cancion==0){
    contador=Mas(contador);
    contador=Cambio (contador);
    myDFPlayer.play(contador);
  }
  if (pausa_Central == 0){
    myDFPlayer.stop();
    contador = contador-contador;
    }
  if (digitalRead(Boton_Izquierda) != pausaval){
     if (pausaval == true){
       myDFPlayer.pause();
     } else {
     myDFPlayer.start();
     }
 }
  static unsigned long timer = millis();
  
 
}

int Mas(int Numero){
  if (Numero==8){
    Numero=0;
  }
  return Numero;
}

int Cambio (int Numero2){
  if(Numero2!=0){
  Numero2=Numero2+1;}else{
    Numero2=1;
    }
  return Numero2;
} 
