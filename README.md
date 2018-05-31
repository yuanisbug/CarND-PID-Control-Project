# CarND-Controls-PID
Self-Driving Car Engineer Nanodegree Program

---

## Explanation

Components of PID controller: **Proportional**, **Integral** and **Derivative**.

**Proportional**: It specifies the car will move in proportion to the cross track error (CTE). CTE gives the distance of the car from the center of the lane. If the car is to the left, it will try to move right to come to the center and vice versa. Considering only this term or keeping this term too high in PID controller will probably overshoot the car and make frequent oscillations.

**Integral**: It specifies that the car will also move in proportional to the sum of all the CTEs because it is necessary to consider previous CTEs to check whether the car is constantly driving away from the center or not. Manufacturing faults like steering not aligned properly can cause the car to constantly drive away from center. Hence this component tends to move the car towards the center.

**Derivative**: Here the derivative specifies the change in CTE as the car moves from time to time. In this project we are considering change in time as constant i.e. 1 sec and hence we need to consider only the difference between the previous and current CTE. This term is necessary when the car started steering from left/right towards the center, steering will be less as the change in CTE becomes lesser and lesser and the car will not overshoot leading to a smoother steering. Too high value leads to more time to converge to the center . Too small value for the coefficient will lead the car to overshoot.

The PID controller was first tuned manually. I started with a P controller and tuned P so the car could keep the trajectory, obviously with lots of oscillations. I then introduced D, increasing it up to the point where oscilaltions subsidized and the car was able to drive around without major issues. Last, I started adding increasing the I coefficient, up to a point were curves were taken correctly. Eventually, I choose I to have a fixed component and one proportional to the car speed as I noticed this produced a better overall behaviour than using a fixed I.

I also implemented a runtime version of twiddle to further optimize the parameters (to be used when the car was already able to stay on the track). I noticed that 1000 data points (about 1 lap) were necessary to have a meaningful error estimation (i.e. covering both straights and curves) and iterated about 50 times. I did not use twiddle, however, to fine tune the parameters but rather to identify in which direction to go. The final tuning was done manually.

I have set the parameters to Kp = 0.18, Ki = 0.0001 and Kd = 10.0. Thus the car is moving approperate according to the requirements.
