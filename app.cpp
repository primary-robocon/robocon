#include "app.h" // <1>
#include "Tracer.h" // <2>
#include "Clock.h"  // <3>
#include "TouchSensor.h"
using namespace ev3api;

Tracer tracer;  // <4>
void tracer_task(intptr_t exinf) { // <1>
  tracer.run(); // <2>
  ext_tsk();
}

void main_task(intptr_t unused) { // <1>
  tracer.init(); // <3>
  start_wait();
  sta_cyc(TRACER_CYC); // <4>
  
  //stp_cyc(TRACER_CYC); // <3>
  //tracer.terminate(); // <4>
  //ext_tsk(); // <5>
}

void start_wait() {
  Clock clock;
  TouchSensor touch_sensor(PORT_1);
  const uint32_t duration = 10*1000;
  while (!touch_sensor.isPressed()) {
    clock.sleep(duration);
  }
}
