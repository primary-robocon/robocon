#include "Tracer.h" // <1>

Tracer::Tracer(MySteering& steer):
  steering(steer),
  Kp(6.25),
  Ki(0.0125),
  Kd(6.25),
  // 処理周期
  Cycle(0.004),
  // センサの目標値
  Target(20),
  // 常に一定の補正をかけたい場合設定する
  Bias(0)
  { 
    diff = 0;
    integral = 0;
    diff_prev = 0;
    ddt = 0;
    line = 0;
  }

void Tracer::init() {
  init_f("Tracer");
}

void Tracer::terminate() {
  msg_f("Stopped.", 1);
  steering.stop();
}

void Tracer::right_line_trace(int turn) {
  steering.setPower(pwm, -turn);
}

void Tracer::left_line_trace(int turn) {
  steering.setPower(pwm, turn);
}

void Tracer::line_change() {
  line = (line + 1) % 2;
}

float Tracer::calc_prop_value(int8_t brightness) {
  // 偏差を計算
  diff = brightness - Target;
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

void Tracer::run(int8_t brightness) {
  msg_f("running...", 1);
  float turn = calc_prop_value(brightness);
  if (line == 0) {
    right_line_trace(turn);
  } else {
    left_line_trace(turn);
  }
}
