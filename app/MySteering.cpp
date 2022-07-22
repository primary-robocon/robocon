#include "MySteering.h" // <1>

MySteering::MySteering():
  leftWheel(PORT_C),
  rightWheel(PORT_B),
  steering(leftWheel, rightWheel){ 
  }

void MySteering::setPower(int power, int turnRatio) {
  steering.setPower(power, turnRatio);
}

int32_t MySteering::getLeftCount() {
  int32_t l_count = leftWheel.getCount();
  return l_count;
}

int32_t MySteering::getRightCount() {
  int32_t r_count = rightWheel.getCount();
  return r_count;
}

void MySteering::stop() {
  leftWheel.stop();
  rightWheel.stop();
}