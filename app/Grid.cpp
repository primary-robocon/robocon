#include "Grid.h"

Grid::Grid():
  GridSize(100.0)
  { 
    grid_distance = 0.0;
    grid_direction = 0.0;
  }

/* 座標aから座標bまでの移動距離を設定する関数 */
void Grid::setDistance(int aX, int aY, int bX, int bY) {
  grid_distance = sqrt( pow((float)(bX-aX),2) + pow((float)(bY-aY),2) ) *  GridSize;
}

/* 座標aから座標bまでの移動距離を取得する関数 */
float Grid::getDistance() {
  return grid_distance;
}

/* 目標座標の方位を設定する関数 */
void Grid::setDirection(int aX, int aY, int bX, int bY) {
  float targetDir = 0.0;// 目標方位

  //　座標aから座標bへの方位（ラジアン）を取得
  targetDir = atan2((float)(bY-aY), (float)(bX-aX));
  //ラジアンから度に変換
  targetDir = targetDir * 180.0 / PI;

  grid_direction = targetDir;
}

/* 目標座標の方位を取得する関数 */
float Grid::getDirection() {
  return grid_direction;
}