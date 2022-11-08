/*
 * main.ino
 *
 * Created: 9/21/2022 1:11:35 AM
 * Author: hyu-nani
 */
#include "math.h" 
#include "variables.h" // all variables 
#include "hardware.h" // set the hardware

/**
* brief : check distance
* note  :	SR04 ultrasonic sensor
* param :	
* return: distance
*/
float sensingSR04()
{
	float duration=0, distance=0;
	digitalWrite(trigPin, LOW);
	delayMicroseconds(10);
	//generate ultrasonic 
	digitalWrite(trigPin, HIGH);
	delayMicroseconds(10);
	digitalWrite(trigPin, LOW);
	//save the time when this change the high of echo pin 
	duration = pulseIn(echoPin, HIGH);
	//calculate (mm)
	distance = (float)((340 * duration) / 1000) / 2;

	distance = (distance > maximumDistance)? maximumDistance : distance;
	distance = (distance < minimumDistance)? minimumDistance : distance;

	return distance;	
}

/**
* brief : turn up LED bar
* note  :	0% ~ 100%
* param :	percentage
* return:
*/
void showLED(int percentage)
{	
	//check range over
	percentage = (percentage < 0) ? 0 : percentage;
	percentage = (percentage > 100) ? 100 : percentage;
	//turn off all led
	for(int i=0; i < 8 ; i++)
	{
		digitalWrite(LED[i], LOW);
	}
	//turn on led
	float num = map(percentage,0,99,0,8);
	for(int i=0; i<num;i++)
	{
		digitalWrite(LED[i], HIGH);
	}
	delay(10);
}

#include "loop.h"

//base on arduino 
void setup()
{
	//serial start
	Serial.begin(115200);
	//board initial setting
	hardWareInit();
}

void loop()
{
	//loop.h
	mainLoop();
}
