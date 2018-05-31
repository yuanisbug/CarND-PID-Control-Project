#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
  dt = 1;

  // Set parameters first
  PID::Kp = Kp;
  PID::Ki = Ki;
  PID::Kd = Kd;

  // Initialize errors
  p_error = 0; // proportional
  i_error = 0; // integral
  d_error = 0; // differential
}

void PID::UpdateError(double cte) {
  i_error += cte * dt; // integral accumulation
  d_error = (cte - p_error) / dt; // (current - last) / dt
  p_error = cte; // update current
}

double PID::TotalError() {
  return Kp * p_error + Kd * d_error + Ki * i_error;
}

double PID::SteerAngle() {
  double total_error = TotalError();
  double angle = - total_error;
  if (angle < -1) {
    return -1;
  } else if (angle > 1) {
    return 1;
  } else {
    return angle;
  }
}

