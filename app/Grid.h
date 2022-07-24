#ifndef _GRID_H_
#define _GRID_H_

#include "math.h"
#include "Distance.h"

class Grid {  // <1>
public:
  explicit Grid();
  // 座標aから座標bまでの移動距離を設定する関数
  void setDistance(int aX, int aY, int bX, int bY);
  // 座標aから座標bまでの移動距離を取得する関数
  float getDistance();
  // 目標座標の方位を設定する関数
  void setDirection(int aX, int aY, int bX, int bY);
  // 目標座標の方位を取得する関数
  float getDirection();

private:
  //座標のマス幅（100mm）
  const float GridSize;
  //現在座標から目標座標までの距離
  float grid_distance;
  //現在座標から目標座標の方位
  float grid_direction;
};

#endif