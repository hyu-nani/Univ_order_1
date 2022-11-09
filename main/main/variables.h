// Is it above the distance criterion?
float maximumDistance = 150;//[mm]
float minimumDistance = 70;//[mm]

float maximumRainsense = 1020;
float minimumRainsense = 233;

//trash
float trigerPercentage = 70;//[%]

//rain sensor 
float rainPercentage = 60;//[%]

// move step motor angle 
float moveAngle = 270;

// interrupt time setting
long nowTime = millis();
long preTime = nowTime;