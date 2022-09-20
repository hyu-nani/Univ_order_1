/*
 * main.ino
 *
 * Created: 9/21/2022 1:11:35 AM
 * Author: hyu-nani
 */ 

#include "hardware.h"
// Is it above the distance criterion?
int maximumDistance = 200;//[mm]
int minimumDistance = 10;//[mm]


//interrupt time setting
long nowTime = millis();
long preTime = nowTime;


/*
brief : check distance
note  :	SR04
param :	
return: distance
*/
float sensingSR04()
{
	float duration, distance;
	digitalWrite(trigPin, LOW);
	digitalWrite(echoPin, LOW);
	delayMicroseconds(2);
	//generate ultra wave sound
	digitalWrite(trigPin, HIGH);
	delayMicroseconds(10);
	digitalWrite(trigPin, LOW);
	//save the time when this change the high of echo pin 
	duration = pulseln(echoPin, HIGH);
	//calculate (mm)
	distance = ((float)(340 * duration) / 1000) / 2;
	return distance;	
}

/*
brief : turn up LED bar
note  :	0% ~ 100%
param :	percentage
return:
*/
void showLED(int percentage)
{	
	//check range over
	percentage = (percentage < 0) ? 0 : percentage;
	percentage = (percentage > 100) ? 100 : percentage;
	//turn off all led
	for(int i=0; i<8 ; i++)
	digitalWrite(LED[i], LOW);
	//turn on led
	for(int i=0; i<100*8/percentage;i++)
	digitalWrite(LED[i], HIGH);
	delay(10);
}

/*
brief : rotating the motor in the specified direction
note  :	
param :	move angle , direction
return: 
*/
void moveStepMotor(float angle, bool direct)
{
	if(direct)//clockwise
	{
		
	}
	else//counterclockwise
	{
		
	}
}

//base on arduino 
void setup()
{
	//serial start
	Serial.begin(9600);
	//board initial setting
	hardWareInit();
}
#include "loop.h"// separate loop
void loop()
{
	//loop.h
	mainLoop();
}
