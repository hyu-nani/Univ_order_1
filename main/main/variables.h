// Is it above the distance criterion?
int maximumDistance = 300;//[mm]
int minimumDistance = 70;//[mm]

int trigerPercentage = 20;//[%]

//rain sensor 
int rainPercentage = 20;//[%]

// move step motor angle 
float moveAngle = 180;

// interrupt time setting
long nowTime = millis();
long preTime = nowTime;