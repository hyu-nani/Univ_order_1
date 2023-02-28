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
float moveAngle = 270;//[Angle]
float moveSpeed = 30;//[%]

// interrupt time setting
long nowTime = millis();
long preTime = nowTime;

kp = 10.
kd = 0.
ki = 0.

dt = 0.
dt_sleep = 0.01
tolerance = 0.1

start_time = time.time()
error_prev = 0.
time_prev = 0.

try:
    while True:
        motorDeg = encoderPos * ratio

        error = targetDeg - motorDeg
        de = error - error_prev
        di += error*dt
        dt = time.time() - time_prev
        control = (kp*error) + (kd*de/dt) + (ki*error*dt)
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 
        error_prev = error