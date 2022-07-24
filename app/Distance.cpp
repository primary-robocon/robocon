#include "Distance.h" // <1>

Distance::Distance(MySteering& steer):
  steering(steer),
  // タイヤ直径（100mm）
  TireDiameter(100.0)
  {
    distance = 0.0;
    distance4msL = 0.0;
    distance4msR = 0.0;
    //モータ角度の過去値に現在値を代入
    pre_angleL = steering.getLeftCount();
    pre_angleR = steering.getRightCount();
  }

/* 距離更新（4ms間の移動距離を毎回加算している） */
void Distance::update(){
  //左モータ回転角度の現在値
  float cur_angleL = steering.getLeftCount();
  //右モータ回転角度の現在値
  float cur_angleR = steering.getRightCount();
  //4msの距離
  float distance4ms = 0.0;

  // 4ms間の走行距離 = ((円周率 * タイヤの直径) / 360) * (モータ角度過去値　- モータ角度現在値)
  distance4msL = ((PI * TireDiameter) / 360) * (cur_angleL - pre_angleL);  // 4ms間の左モータ距離
  distance4msR = ((PI * TireDiameter) / 360) * (cur_angleR - pre_angleR);  // 4ms間の右モータ距離
  distance4ms = (distance4msL + distance4msR) / 2; //左右タイヤの走行距離を足して割る
  distance += distance4ms;

  //モータの回転角度の過去値を更新
  pre_angleL = cur_angleL;
  pre_angleR = cur_angleR;
}

/* 走行距離を取得 */
float Distance::getDistance(){
  return distance;
}

/* 右タイヤの4ms間の距離を取得 */
float Distance::getDistance4msRight(){
  return distance4msR;
}

/* 左タイヤの4ms間の距離を取得 */
float Distance::getDistance4msLeft(){
  return distance4msL;
}