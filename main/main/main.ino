/*
 * main.ino
 *
 * Created: 9/21/2022 1:11:35 AM
 * Author: hyu-nani
 */ 

#include "hardware.h"
// ������ ������ �Ÿ����� distance Criterion �̻��ΰ�
int distanceCriterion = 10;
long nowTime = millis();
long preTime = nowTime;


#include "loop.h"// ���� ��ȯ���� ����
float sensingSR04()
{
	float duration, distance;
	digitalWrite(trigPin, LOW);
	digitalWrite(echoPin, LOW);
	delayMicroseconds(2);
	//������ �߻�
	digitalWrite(trigPin, HIGH);
	delayMicroseconds(10);
	digitalWrite(trigPin, LOW);
	//echo ���� high�� ������ �ð��� ����
	duration = pulseln(echoPin, HIGH);
	//��� ����(mm)
	distance = ((float)(340 * duration) / 1000) / 2;
	return distance;	
}

void setup()
{
	Serial.begin(9600);
	hardWareInit();
}

void loop()
{
	 mainLoop();
}
