//For CO2
float  Rl  =  22;
int sensorValue;
float s;
#define         RL_VALUE                     (22)     //define the load resistance on the board, in kilo ohms
#define         RO_CLEAN_AIR_FACTOR          (3.597)  //(Sensor resistance in clean air)/RO,
                                                     //which is derived from the chart in datasheet
void setup()
{
  Serial.begin(9600);      // sets the serial port to 9600
}



float sensorCaliberate()
  {
    int i;
    float Rs =0;
    
    for(i=0;i<17;i++)
    {
      Rs +=ResisCal(sensorValue);
      delay(100);
    }

    Rs = Rs/17;
    Rs = (Rs/3.597);
    return Rs;
    
  }
  
float ResisCal(float sensorVal)
  {
    return (Rl*(1023-sensorVal))/sensorVal;
  }
  
void loop()
{
  sensorValue = analogRead(0);
  float           LPGCurve[3]  = {1,0.835,-0.096}; //(x1=10,y1=6.844)(X2=653.824,Y2=4.57097)
               //logX2=2.815,y2=0.659

  float Ro= sensorCaliberate();
  Serial.println(Ro);
  //delay(500);

  
  
  
  
         // read analog input pin 0
  //s=(float)sensorValue /(1024/5.0);
  //Serial.println(sensorValue,DEC);  // prints the value read
                          // wait 100ms for next reading
}

