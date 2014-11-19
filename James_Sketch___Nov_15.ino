/*
  Program Name: LaserHarp One Note
  Purpose:
    - Detect Light and play a tone under
      the condition that not enough 
      light is present
  Circuit:
    - A0 is hooked up to a voltage devider with a photoresistor
      and a 100k resistor
    - A piezo is hooked up to pin 11 (PWM~)
  Written By: James Spaleta on 15/11/2014 (DD/MM/YYYY)
*/

//Sensor Pin
int sensor0 = A0; //The sensor pin A0
                  //Will be used to
                  //Dectect light
//Speaker Pin
int speaker0 = 11;//Speaker is on pin
                  //11 as it must be 
                  //On a PWM~ pin to use
                  //The tone function
//Light Threashold
const int lightThreashold = 50;  //Will play audio when there
                                  //Is a lower reading than
                                  //This from the light sensor
void setup()
{
  pinMode(sensor0, INPUT);
  pinMode(speaker0, OUTPUT);
  Serial.begin(9600); //Begin serial communication
                      //At 9600 baud for use in 
                      //Calibration of the sensor
}

void loop()
{
  int lightLevel = analogRead(sensor0); //low number means more light
  Serial.println(lightLevel);
  if(lightLevel > lightThreashold)
  {
    tone(speaker0, 261);
  }
  else
  noTone(speaker0);
}
