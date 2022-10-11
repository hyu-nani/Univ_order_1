/*
 * hardware.h
 *
 * Created: 2022-09-21 ���� 1:18:43
 *  Author: hyu-nani
 */ 


#define trigPin 5 //SR-04 Trig pin
#define echoPin 6 //SR-04 Echo pin

#define stepPin 10 //step motor step pin
#define dirPin 11 //step motor direct pin

#define rainSense A0 //rainning sensor

//LED bar pin
int LED[8] = {39, 41, 43, 45, 47, 49, 51, 53};

/**
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
	pinMode(stepPin, OUTPUT);
	pinMode(dirPin, OUTPUT);

	//LED bar
	for(int i=0; i<8; i+=1)
	pinMode(LED[i], OUTPUT);
	
	//rain sensor
	pinMode(rainSense, INPUT);
}

/**
 * brief : move step motor 
 * note  :
 * param : angle, direction( clockwise = true / countclockwise = false), speed(0~100)
 * return: 
 */
void moveStep(float angle, bool direction, int speed)
{
	int stepCount = angle / 1.8;
	speed = (speed > 100) ? 100 : speed;
	speed = (speed < 0) ? 0 : speed;
	if(speed > 100)
	speed = 100;
	// driver max speed [ rpm = 1200 ]
	float stepDelay =  2.5 / (speed*100);

	//setting direction
	if(direction)
	digitalWrite(dirPin, HIGH);
	else
	digitalWrite(dirPin, LOW);
	for(int i=0; i< stepCount; i++)
	{
		digitalWrite(stepPin, HIGH);
		delay(stepDelay);
		digitalWrite(stepPin, LOW);
		delay(stepDelay);
	}
}