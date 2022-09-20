/*
 * hardware.h
 *
 * Created: 2022-09-21 오전 1:18:43
 *  Author: hyu-nani
 */ 


#ifndef HARDWARE_H_
#define HARDWARE_H_


#endif /* HARDWARE_H_ */

#define trigPin 4 //초음파 센서의 Trig pin
#define echoPin 5 //초음파 센서의 Echo pin

#define stepMotorA 10 //스탭모터

//LED bar 핀
int LED[8] = {22, 23, 24, 25, 26, 27, 28, 29};

void hardWareInit()
{
	//초음파 센서 SR-04
	pinMode(trigPin, OUTPUT);
	pinMode(echoPin, INPUT);
	//스텝모터
	
	//LED bar
	for(int i=0; i<8; i+=1)
	pinMode(LED[i], OUTPUT);
}

