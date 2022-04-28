#include "AlphaBot.h"

int LSensorPin = 7;
int RSensorPin = 8;

int LSensor;              //Bal távolságérzékelő értéke
int RSensor;              //Jobb távolságérzékelő értéke

AlphaBot robotmozog = AlphaBot();

void ProximityConfig()        //A pinek módjának beállítása
{
  pinMode(RSensorPin, INPUT);   //A bemenet és pin beállítása a jobb szenzornál 
  pinMode(LSensorPin, INPUT);   //A bemenet és pin beállítása a bal szenzornál 
}

void setup()
{
  ProximityConfig();
  robotmozog.SetSpeed(150);
}

void loop()
{

  {
  
    RSensor = digitalRead(RSensorPin);            //LOW = van jel; HIGH = nincs jel 
    LSensor = digitalRead(LSensorPin);            //LOW = van jel; HIGH = nincs jel 
    
    if (LSensor == HIGH && RSensor == HIGH) {       //Ha nincs előtte akadály, menjen előre
      robotmozog.Forward();
      }
    else if (LSensor == HIGH && RSensor == LOW) {   //Ha a jobb érzékelő kap jelet, forduljon balra
      robotmozog.Backward(200);
      robotmozog.Left(675);
      robotmozog.Forward(550);
      robotmozog.Right(450);
      robotmozog.Forward(1250);
      robotmozog.Right(450);
      robotmozog.Forward(550);
      robotmozog.Left(675);
      robotmozog.Forward();
      }
    else if (RSensor == HIGH && LSensor == LOW) {   //Ha a bal érzékelő kap jelet, forduljon jobbra 
      robotmozog.Backward(200);
      robotmozog.Right(675);
      robotmozog.Forward(550);
      robotmozog.Left(675);
      robotmozog.Forward(1250);
      robotmozog.Left(675);
      robotmozog.Forward(550);
      robotmozog.Right(675);
      robotmozog.Forward();
      
      }
    else                                          //Ellenkező esetben keressen másik utat
   {
      robotmozog.Backward();
      delay(5);
      robotmozog.LeftCircle();
      delay(5);
      robotmozog.Forward();
    }
  }  
}
