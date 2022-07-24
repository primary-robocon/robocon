#ifndef _MYSENSOR_H_
#define _MYSENSOR_H_

#include "TouchSensor.h"
#include "ColorSensor.h"
#include "GyroSensor.h"
#include "SonarSensor.h"

using namespace ev3api;

// HSV Raw値を格納する構造体
typedef struct {
    uint16_t h; 
    uint16_t s; 
    uint16_t v; 
} hsv_raw_t;

class MySensor {  // <1>
public:
  explicit MySensor();
// タッチセンサ用関数

  bool isPressed();
// ジャイロセンサ用関数

  int16_t getAngle();
  void gyroReset();

// カラーセンサ用関数
  
  uint8_t getAmbient();	
  int8_t getBrightness();
  void getRGBColor(rgb_raw_t& rgb);
  //hsv h 色相 s 彩度 v 明度
  //未実装
  void getHSVColor(hsv_raw_t& hsv);

private:
  TouchSensor touchSensor;
  GyroSensor gyroSensor;
  ColorSensor colorSensor;
  SonarSensor sonarSensor;

};

#endif