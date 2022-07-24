#include "MySensor.h"

MySensor::MySensor():
  touchSensor(PORT_1),
  gyroSensor(PORT_2),
  colorSensor(PORT_3),
  sonarSensor(PORT_4){ 
  }

bool MySensor::isPressed() {
  return touchSensor.isPressed();
}

int16_t MySensor::getAngle() {
  return gyroSensor.getAngle();
}

void MySensor::gyroReset() {
  gyroSensor.reset();
}

uint8_t MySensor::getAmbient() {
  return colorSensor.getAmbient();
}

int8_t MySensor::getBrightness() {
  return colorSensor.getBrightness();
}

void MySensor::getRGBColor(rgb_raw_t& rgb) {
  colorSensor.getRawColor(rgb);
}

void MySensor::getHSVColor(hsv_raw_t& hsv) {
  rgb_raw_t rgb;
  getRGBColor(rgb);
  uint16_t min;
  // 赤が最大値だったら
  if (rgb.r > rgb.g && rgb.r > rgb.b) {
    // gとbのどちらか小さい方をminへ代入
    min = (rgb.g > rgb.b)? rgb.b: rgb.g;
    hsv.h = ((60 * ((rgb.g-rgb.b) / (rgb.r-min))) + 360) % 360;
  // 緑が最大値だったら
  } else if (rgb.g > rgb.r && rgb.g > rgb.b) {
    // gとbのどちらか小さい方をminへ代入
    min = (rgb.r > rgb.b)? rgb.b: rgb.r;
    hsv.h = ((60 * ((rgb.b-rgb.r) / (rgb.g-min)) + 120) + 360) % 360;
  // 青が最大値だったら
  } else if (rgb.b > rgb.r && rgb.b > rgb.g) {
    // rとgのどちらか小さい方をminへ代入
    min = (rgb.r > rgb.g)? rgb.g: rgb.r;
    hsv.h = ((60 * ((rgb.r-rgb.g) / (rgb.b-min)) + 240) + 360) % 360;
  }
}