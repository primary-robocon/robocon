#include "app.h" // <1>
#include "Tracer.h" // <2>
#include "Clock.h"  // <3>
#include "TouchSensor.h"
#include "ColorSensor.h"
#include "GyroSensor.h"
#include "MySteering.h"
using namespace ev3api;

Clock clock;
MySteering steering;
Tracer tracer(steering);  // <4>
ColorSensor colorSensor(PORT_3);
TouchSensor touch_sensor(PORT_1);

int8_t change_count = 0;
int8_t is_change = 0;

void tracer_task(intptr_t exinf) { // <1>
  int8_t brightness = colorSensor.getBrightness();
  if (brightness <= 10 && change_count < 2) {
    if (clock.now() >= 6 * 1000 * 1000) {
      clock.reset();
      is_change = 1;
      change_count += 1;
    }
  }
  if (is_change) {
    act_tsk(LINE_CHANGE);
  }
  tracer.run(brightness); // <2>
  ext_tsk();
}

void main_task(intptr_t unused) { // <1>
  wait_start();
  tracer.init(); // <3>
  sta_cyc(TRACER_CYC); // <4>
  clock.reset();
  //stp_cyc(TRACER_CYC); // <3>
  //tracer.terminate(); // <4>
  //ext_tsk(); // <5>
}

void wait_start() {
  const uint32_t duration = 10*1000;
  while (!touch_sensor.isPressed()) {
    clock.sleep(duration);
  }
}

void tracer_line_change(intptr_t exinf) {
  is_change = 0;
  clock.sleep(1 * 1000 * 1000);
  tracer.line_change();
  ext_tsk();
}