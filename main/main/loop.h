/*
 * loop.h
 *
 * Created: 2022-09-21 ���� 1:27:06
 *  Author: hyu-nani
 */ 

bool active = false;

void mainLoop()
{
    float rainSensorValue = 100 - (analogRead(rainSense)-minimumRainsense)/(maximumRainsense-minimumRainsense)*100;
    float trashPercentage = 100 - (sensingSR04()-minimumDistance)/(maximumDistance-minimumDistance)*100;
    
    Serial.print("쓰레기 값:");
    Serial.print(trashPercentage);
    Serial.print("%\t\t/ 비 센서:");
    Serial.print(rainSensorValue);
    Serial.println("%");

    showLED(trashPercentage);
    if(rainSensorValue >= rainPercentage && active == false)
    {
        Serial.println("active motor");
        moveStep(moveAngle, true, moveSpeed);
        active = true;
    }
    else if( rainSensorValue < rainPercentage-40 && active == true)
    {
        Serial.println("reverse motor");
        moveStep(moveAngle, false, moveSpeed);
        active = false;
    }
}   


