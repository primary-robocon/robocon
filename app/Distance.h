#ifndef _DISTANCE_H_
#define _DISTANCE_H_

#include "MySteering.h"

// 円周率
#define PI 3.14159265358

class Distance {  // <1>
public:
  explicit Distance(MySteering& steer);
  /* 距離を更新 */
  void update();
  /* 走行距離を取得 */
  float getDistance();
  /* 右タイヤの4ms間の距離を取得 */
  float getDistance4msRight();
  /* 左タイヤの4ms間の距離を取得 */
  float getDistance4msLeft();

private:
  MySteering& steering;
  // タイヤ直径
  const float TireDiameter;
  // 走行距離
  float distance;
  // 左タイヤの4ms間の距離
  float distance4msL;
  // 右タイヤの4ms間の距離
  float distance4msR;
  // 左右モータ回転角度の過去値
  float pre_angleL, pre_angleR;
};

#endif