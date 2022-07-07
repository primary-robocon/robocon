#include "Motor.h"       // <1>
#include "ColorSensor.h" // <2>
#include "util.h"        // <3>

using namespace ev3api;  // <4>

class Tracer {  // <1>
public:
  Tracer();
  void run();       // <2>
  void init();
  void terminate();

private:
  Motor leftWheel;
  Motor rightWheel;
  ColorSensor colorSensor; // <3>
  //const int8_t mThreshold = 20;  // <4>
  const float Kp = 5;
  const float Ki = 0.01;
  const float Kd = 5;
  const float Cycle = 0.005;
  // センサの目標値
  const int Target = 20;
  // 常に一定の補正をかけたい場合設定する
  const int Bias = 0;
  int diff = 0;
  float integral = 0;
  int diff_prev = 0;
  int ddt = 0;
  int pwm_l, pwm_r;
#ifndef MAKE_RASPIKE
  const int8_t pwm = (Motor::PWM_MAX) / 2;
#else
  const int8_t pwm = 60;
#endif
  void motor_set_power();
  float calc_prop_value();
  void right_line_trace(int turn);
  void left_line_trace(int turn);
};
