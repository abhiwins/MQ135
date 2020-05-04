int sensorValue;
#include<math.h>
float Rl = 22;
float Rs = 0;

void setup()
{
    Serial.begin(9600);
    pinMode(7,OUTPUT);
}

float sensorCaliberate()
{
    int i;
    for(i=0;i<15;i++)
    {
        Rs +=ResisCal(sensorValue);
        delay(400);
    }

    Rs = Rs/15;
    return Rs;
    
}
  
float ResisCal(float sensorVal)
{
    return (Rl*(1023-sensorVal))/sensorVal;

}

void loop()
{
    float Ro = 146.49;//318.5947;//262.40;//30.4228;
    sensorValue = analogRead(0);
    float CO2Curve[3]  ={1,0.36242,-0.3529};//{10,2.30372,-0.007 }; 
    Rs=sensorCaliberate();
    //Serial.print("Rs Value:->>  ");
    //Serial.println(Rs);
    float Y2 = Rs/Ro;
    //Serial.print("Y2 Value:->>  ");
    //Serial.println(Y2);
    digitalWrite(7, Y2);
    double X2 = (pow(10,((((log10(Y2))- CO2Curve[1])/CO2Curve[2])+CO2Curve[0])));//((((Y2)- CO2Curve[1])/CO2Curve[2])+CO2Curve[0]);
    Serial.print("Co2 Value in PPM:->>  ");
    Serial.println(X2);  

}
