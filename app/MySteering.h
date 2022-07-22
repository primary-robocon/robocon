#ifndef _MYSTEERING_H_
#define _MYSTEERING_H_

#include "Motor.h"       // <1>
#include "Steering.h"

using namespace ev3api;  // <4>

class MySteering {  // <1>
public:
  explicit MySteering();
  void setPower(int power, int turnRatio);
  void stop();
  int32_t getLeftCount();
  int32_t getRightCount();

private:
  Motor leftWheel;
  Motor rightWheel;
  Steering steering;
};

#endif