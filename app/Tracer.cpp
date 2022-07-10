#include "Tracer.h" // <1>

Tracer::Tracer():
  leftWheel(PORT_C),
  rightWheel(PORT_B),
  steering(leftWheel, rightWheel),
  colorSensor(PORT_3){ // <2>
  }

void Tracer::init() {
  init_f("Tracer");
  timer.reset();
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

void Tracer::line_change() {
  if (timer.now() >= 1 * 1000 * 1000) {
    timer.reset();
    line = (line + 1) % 2;
    is_under_change = false;
    change_count += 1;
  }
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

void Tracer::run() {
  msg_f("running...", 1);
  int8_t brightness = colorSensor.getBrightness();
  if (is_under_change) {
    line_change();
  } else if (brightness <= 10 && change_count < 2) {
    if (timer.now() >= 6 * 1000 * 1000) {
      timer.reset();
      is_under_change = true;
    }
  }
  float turn = calc_prop_value(brightness);
  if (line == 0) {
    right_line_trace(turn);
  } else {
    left_line_trace(turn);
  }
}
