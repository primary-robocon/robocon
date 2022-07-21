#include "Motor.h"       // <1>
#include "Steering.h"
#include "util.h"        // <3>

using namespace ev3api;  // <4>

class Tracer {  // <1>
public:
  Tracer();
  void run(int8_t brightness);       // <2>
  void init();
  void terminate();
  void line_change();

private:
  Motor leftWheel;
  Motor rightWheel;
  Steering steering;
  //const float Kp = 2.5;
  //const float Ki = 0.2;
  //const float Kd = 15;
  const float Kp = 6.25;
  const float Ki = 0.0125;
  const float Kd = 6.25;
  const float Cycle = 0.005;
  // センサの目標値
  //const float Target = 10;
  const float Target = 20;
  // 常に一定の補正をかけたい場合設定する
  const int Bias = 0;
  int diff = 0;
  float integral = 0;
  int diff_prev = 0;
  int ddt = 0;
  int pwm_l, pwm_r;
  int line = 0;
#ifndef MAKE_RASPIKE
  //const int8_t pwm = (Motor::PWM_MAX) / 3;
  const int8_t pwm = (Motor::PWM_MAX) / 1.5;
#else
  const int8_t pwm = 60;
#endif
  float calc_prop_value(int8_t brightness);
  void right_line_trace(int turn);
  void left_line_trace(int turn);
};
