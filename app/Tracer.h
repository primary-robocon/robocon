#ifndef _TRACER_H_
#define _TRACER_H_

#include "MySteering.h"
#include "util.h"        // <3>

using namespace ev3api;  // <4>

class Tracer {  // <1>
public:
  Tracer(MySteering& steer);
  void run(int8_t brightness);       // <2>
  void init();
  void terminate();
  void line_change();

private:
  MySteering& steering;
  const float Kp;
  const float Ki;
  const float Kd;
  const float Cycle;
  // センサの目標値
  const float Target;
  // 常に一定の補正をかけたい場合設定する
  const int Bias;

  int diff;
  float integral;
  int diff_prev;
  int ddt;
  int line;
#ifndef MAKE_RASPIKE
  const int8_t pwm = (Motor::PWM_MAX) / 1.5;
#else
  const int8_t pwm = 60;
#endif
  float calc_prop_value(int8_t brightness);
  void right_line_trace(int turn);
  void left_line_trace(int turn);
};

#endif