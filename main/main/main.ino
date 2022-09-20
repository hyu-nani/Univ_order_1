/*
 * main.ino
 *
 * Created: 9/21/2022 1:11:35 AM
 * Author: hyu-nani
 */ 

#include "hardware.h"
// 초음파 센서의 거리값이 distance Criterion 이상인가
int distanceCriterion = 10;
long nowTime = millis();
long preTime = nowTime;


#include "loop.h"// 메인 순환구조 분할
float sensingSR04()
{
	float duration, distance;
	digitalWrite(trigPin, LOW);
	digitalWrite(echoPin, LOW);
	delayMicroseconds(2);
	//초음파 발생
	digitalWrite(trigPin, HIGH);
	delayMicroseconds(10);
	digitalWrite(trigPin, LOW);
	//echo 핀이 high를 유지한 시간을 저장
	duration = pulseln(echoPin, HIGH);
	//계산 단위(mm)
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
