/*
 * hardware.h
 *
 * Created: 2022-09-21 ���� 1:18:43
 *  Author: hyu-nani
 */ 


#define trigPin 5 //SR-04 Trig pin
#define echoPin 6 //SR-04 Echo pin

#define stepPin 3 //step motor step pin
#define dirPin 2 //step motor direct pin
#define enPin 4 //Enable motor driver

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
	pinMode(enPin, OUTPUT);

	//step moter
	pinMode(stepPin, OUTPUT);
	pinMode(dirPin, OUTPUT);

	//LED bar
	for(int i=0; i<8; i+=1)
	pinMode(LED[i], OUTPUT);
	
	//rain sensor
	pinMode(rainSense, INPUT);

	//digitalWrite(enPin, HIGH);
}

/**
 * brief : move step motor 
 * note  :
 * param : angle, direction( clockwise = true / countclockwise = false), speed(0~100)
 * return: 
 */
void moveStep(float angle, bool direction, int speed)
{
	digitalWrite(enPin, LOW);
	int stepCount = angle / 1.8;
	
	// driver max speed [ rpm = 1200 ] 속도제어 문제 발생
	float stepDelay = sqrt(100 / speed);
	stepDelay = (stepDelay > 10) ? 10 : stepDelay;
	stepDelay = (stepDelay < 1) ? 1 : stepDelay;
	Serial.println(stepDelay);
	//setting direction
	if(direction)
	digitalWrite(dirPin, HIGH);
	else
	digitalWrite(dirPin, LOW);
	delay(1);
	for(int i=0; i< stepCount*2 ; i+=1)
	{
		digitalWrite(stepPin, HIGH);
		delay(0.01);
		digitalWrite(stepPin, LOW);
		delay(stepDelay);
	}
	delay(1);
	//Serial.println("done");
	digitalWrite(enPin, LOW);
}