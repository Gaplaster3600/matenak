#include "AlphaBot.h"

int LSensorPin = 7;
int RSensorPin = 8;

int LSensor;              //Left Infrared Proximity Sensor signal value
int RSensor;              //Right Infrared Proximity Sensor signal value

AlphaBot robotmozog = AlphaBot();

void ProximityConfig()        //A pinek módjának beállítása
{
  pinMode(RSensorPin, INPUT);   //Define the input pin of Right Infrared Proximity Sensor
  pinMode(LSensorPin, INPUT);   //Define the input pin of Left Infrared Proximity Sensor
}

void setup()
{
  ProximityConfig();
  robotmozog.SetSpeed(100);
}

void loop()
{

  {
  
    RSensor = digitalRead(RSensorPin);            //LOW means signal, HIGH means no signal 
    LSensor = digitalRead(LSensorPin);            //LOW means signal, HIGH means no signal 
    
    if (LSensor == HIGH && RSensor == HIGH) {       //If no obstacle in front, run forward
      robotmozog.Forward();
      }
    else if (LSensor == HIGH && RSensor == LOW) {   //If the right sensor has a signal, turn left
      robotmozog.Backward(750);
      robotmozog.Left(1000);
      robotmozog.Forward(750);
      robotmozog.Right(1000);
      robotmozog.Forward();
      }
    else if (RSensor == HIGH && LSensor == LOW) {   //If the left sensor has a signal, turn right 
      robotmozog.Backward(750);
      robotmozog.Right(1000);
      robotmozog.Forward(750);
      robotmozog.Left(1000);
      robotmozog.Forward();
      }
    else                                          //Otherwise, Backward for 5ms and then turn left for 5ms
   {
      robotmozog.Backward();
      delay(5);
      robotmozog.LeftCircle();
      delay(5);
      robotmozog.Forward();
    }
  }  
}
