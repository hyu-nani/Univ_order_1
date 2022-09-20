/*
 * hardware.h
 *
 * Created: 2022-09-21 ¿ÀÀü 1:18:43
 *  Author: hyu-nani
 */ 


#ifndef HARDWARE_H_
#define HARDWARE_H_


#endif /* HARDWARE_H_ */

#define trigPin 4 //SR-04 Trig pin
#define echoPin 5 //SR-04 Echo pin

#define stepMotorA 10 //step moter

#define rainSense 11 //rainning sensor

//LED bar pin
int LED[8] = {22, 23, 24, 25, 26, 27, 28, 29};

/*
brief : initial setting on board connection
note  : 
param :	
return:
*/
void hardWareInit()
{
	//SR-04
	pinMode(trigPin, OUTPUT);
	pinMode(echoPin, INPUT);
	//step moter
	
	//LED bar
	for(int i=0; i<8; i+=1)
	pinMode(LED[i], OUTPUT);
	
	//rain sensor
	pinMode(rainSense, INPUT);
}

