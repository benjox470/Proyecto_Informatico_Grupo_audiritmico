#define length(v,t) (sizeof(v)/sizeof(t))
#include <Adafruit_NeoPixel.h>

#define NEOPIX  9
#define cantNeo 60
int ceroaudio[] = {0, 24, 40, 52, 56, 46, 32, 12};
Adafruit_NeoPixel pixel = Adafruit_NeoPixel( cantNeo , NEOPIX ,NEO_GRB + NEO_KHZ800 );
int ceroa100[]={21,18,14};
int ciena200[]={21,18,14,3,6,10}; 
int trescientosa400[]={24,29,35};
int cuatrocientosa500[]={24,27,29,32,35,37};
// por si acaso - El 500 a 600,200 a 300, 800 a 900 y 900 a 1024  no necesitan hacer un vector
int seisa700 []= {51,40,41};
int sietea800[]={51,40,41,47,46,45};
void setup()
{
  pinMode(NEOPIX, OUTPUT);
  pixel.begin();
  pixel.fill (pixel.Color(0,0,255), 0,60);
  pixel.show();

}

void loop()
{
  int Lectira=random(0,1024);
  delay (100);
  //Benjamin
  if (Lectira>=0 and Lectira<=300){
    if (Lectira==0){
      sinaudio();
    }else if(Lectira>0 and Lectira<=100){
      ceroacienaudio();
    }else if(Lectira>100 and Lectira<=200){
      cienadosientos();
    }else if(Lectira>200 and Lectira<=300){
      dosatres();
    } 
  }
  //Agus
  if (Lectira>=300 and Lectira<600){
    if(Lectira>300 and Lectira<=400){
      trescientosacuatrocientos();
    }else if(Lectira>400 and Lectira<=500){
      setecientosaochosientos();
    }else if(Lectira>400 and Lectira<=500){
      quinientosaseiscientos();
    }
  }
  //Lerman
  if (Lectira>=600 and Lectira<900){
    if(Lectira>600 and Lectira<=700){
      seisientosasetecientos();
    }else if(Lectira>700 and Lectira<=800){
      cuatrocientosaquinientos();
    }else if(Lectira>800 and Lectira<=900){
      ochosientosa900();
    }
  }
  //Samir
  if (Lectira>=900 and Lectira<=1023){
    novecientos1024();
  }
}

void sinaudio (){
  pixel.fill (pixel.Color(0,0,255), 0,60);
  pixel.show();
  for (int i=0;i<length (ceroaudio, int);i=i+1){
    pixel.setPixelColor (ceroaudio[i] ,pixel.Color (0,255,0));
    
  }
 pixel.show ();

}
void ceroacienaudio (){
  pixel.fill (pixel.Color(0,0,255), 0,60);
  pixel.show();
  for (int i=0;i<length (ceroa100, int);i=i+1){
    pixel.setPixelColor (ceroa100[i] ,pixel.Color (0,255,0));
    
  }
 pixel.show ();

}
void cienadosientos (){
  pixel.fill (pixel.Color(0,0,255), 0,60);
  pixel.show();
  for (int i=0;i<length (ciena200, int);i=i+1){
    pixel.setPixelColor (ciena200[i] ,pixel.Color (0,255,0));
    
  }
 pixel.show ();

}
void dosatres (){
  pixel.fill (pixel.Color(0,0,255), 0,60);
  pixel.show ();
  pixel.fill (pixel.Color(0,255,0), 0,23);
  pixel.show ();

}

void trescientosacuatrocientos(){
  pixel.fill (pixel.Color(0,0,255), 0,60);
  pixel.show();
  for (int i=0;i<length(trescientosa400, int);i=i+1){
    pixel.setPixelColor(trescientosa400[i],pixel.Color(150,255,0));
    
  }
 pixel.show ();

}


void cuatrocientosaquinientos(){
  pixel.fill (pixel.Color(0,0,255), 0,60);
  pixel.show();
  
  for (int i=0;i<length(cuatrocientosa500, int);i=i+1){
    pixel.setPixelColor(cuatrocientosa500[i],pixel.Color(150,255,0));
    
  }
 pixel.show ();

}


void quinientosaseiscientos(){
  pixel.fill (pixel.Color(0,0,255), 0,60);
  pixel.show ();
  pixel.fill (pixel.Color(150,255,0), 24,39);
  pixel.show ();

}

void seisientosasetecientos(){
  pixel.fill (pixel.Color(0,0,255), 0,60);
  pixel.show();
  
  for (int i=0;i<length(seisa700, int);i=i+1){
    pixel.setPixelColor(seisa700[i],pixel.Color(150,175,0));
    
  }
 pixel.show ();

}

void setecientosaochosientos(){
  pixel.fill (pixel.Color(0,0,255), 0,60);
  pixel.show();
  
  for (int i=0;i<length(sietea800, int);i=i+1){
    pixel.setPixelColor(sietea800[i],pixel.Color(150,175,0));
    
  }
 pixel.show ();

}




void ochosientosa900(){
  pixel.fill (pixel.Color(0,0,255), 0,60);
  pixel.show ();
  pixel.fill (pixel.Color(150,175,0), 40,51);
  pixel.show ();

}

void novecientos1024 (){
  pixel.fill (pixel.Color(0,255,0), 0,23);
  pixel.show ();
  pixel.fill (pixel.Color(255,255,0), 24,39);
  pixel.show ();
  pixel.fill (pixel.Color(0,69,100), 40,51);
  pixel.show ();
  pixel.fill (pixel.Color(255,0,0), 52,60);
  pixel.show ();
}
