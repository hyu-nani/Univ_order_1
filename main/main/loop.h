/*
 * loop.h
 *
 * Created: 2022-09-21 ���� 1:27:06
 *  Author: hyu-nani
 */ 

void mainLoop()
{
	float trashDistance = sensingSR04();
    float difference = (maximumDistance-minimumDistance);
    float test = 100 - ((trashDistance-minimumDistance)/difference*100);
    Serial.println(test);
    showLED(test);
    /*
    if(trigerPercentage > trashDistance*100/(maximumDistance-minimumDistance))
    {
        showLED(100);
        delay(100);
        showLED(0);
        delay(100);
    }
    else
    {
        float test =  trashDistance*100/(maximumDistance-minimumDistance)
        showLED(test);
    }
    
    int rainSensorValue = analogRead(rainSense);
    
    if(rainPercentage <= rainSensorValue*100/1023)
    {
        moveStep(moveAngle, true, 50);
    }
    else
    {
        moveStep(moveAngle, false, 50);
    }
    */
}   


