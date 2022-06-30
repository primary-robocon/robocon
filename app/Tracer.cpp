#include "Tracer.h" // <1>

Tracer::Tracer():
  leftWheel(PORT_C), rightWheel(PORT_B), colorSensor(PORT_3) { // <2>
  }

void Tracer::init() {
  init_f("Tracer");
}

void Tracer::terminate() {
  msg_f("Stopped.", 1);
  leftWheel.stop();  // <1>
  rightWheel.stop();
}

void Tracer::motor_set_power(int turn, char way) {
  int pwm_l;
  int pwm_r;
  if(way == 'r') {
    pwm_l = pwm - turn;
    pwm_r = pwm + turn;
  } else {
    pwm_l = pwm + turn;
    pwm_r = pwm - turn;
  }

  leftWheel.setPWM(pwm_l);
  rightWheel.setPWM(pwm_r);
}

float Tracer::calc_prop_value() {
  const float Kp = 2;
  const float Ki = 0.833;
  const float Kd = 0.4;
  const float time = 0.005;
  // センサの目標値
  const int target = 25;

  // 常に一定の補正をかけたい場合設定する
  const int bias = 0;

  // 偏差を計算
  diff = colorSensor.getBrightness() - target;

  // 偏差の累積地を更新
  integral += diff * time;

  // 前回偏差との差を計算
  ddt = diff - diff_prev;

  // 前回偏差を更新
  diff_prev = diff;

  // 計算した操作量を返却
  // P制御
  // return Kp * diff + bias;
  // PI制御
  // return Kp * diff + Ki * integral + bias;
  // PID制御
  return Kp * diff + Ki * integral + Kd * ddt + bias;
}

void Tracer::run() {
  msg_f("running...", 1);
  float turn = calc_prop_value();
  motor_set_power(turn, 'l');
}
