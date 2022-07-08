#include "Tracer.h" // <1>

Tracer::Tracer():
  leftWheel(PORT_C), rightWheel(PORT_B), steering(leftWheel, rightWheel), colorSensor(PORT_3){ // <2>
  }

void Tracer::init() {
  init_f("Tracer");
}

void Tracer::terminate() {
  msg_f("Stopped.", 1);
  leftWheel.stop();  // <1>
  rightWheel.stop();
}

void Tracer::right_line_trace(int turn) {
  steering.setPower(pwm, -turn);
}

void Tracer::left_line_trace(int turn) {
  steering.setPower(pwm, turn);
}

float Tracer::calc_prop_value() {
  // 偏差を計算
  diff = colorSensor.getBrightness() - Target;
  // 偏差の累積地を更新
  integral += diff * Cycle;
  // 前回偏差との差を計算
  ddt = diff - diff_prev;
  // 前回偏差を更新
  diff_prev = diff;
  // 計算した操作量を返却
  // P制御
  // return Kp * diff + Bias;
  // PI制御
  // return Kp * diff + Ki * integral + Bias;
  // PID制御
  return Kp * diff + Ki * integral + Kd * ddt + Bias;
}

void Tracer::run() {
  msg_f("running...", 1);
  float turn = calc_prop_value();
  right_line_trace(turn);
}
