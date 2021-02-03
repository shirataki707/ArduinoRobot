/* 後期PBL プログラム
 * 
 * created : 2020/12/15
 * 
 * contents : pbl_main.ino    メインプログラム
 *            pbl_walk.ino    歩行プログラム
 *            pbl_pk.ino      PK競技用の関数
 *            
 */

#include <Servo.h>
#include <Sensor.h>

Servo sv[4][3];
Sensor sensorRight(A0), sensorLeft(A1);
const float THRESHOLD = 60.0; // 距離の閾値
// ピン番号
const int MOTORPIN[4][3] = {{2, 3, 4}, 
                            {5, 6, 7},
                            {8, 9, 10},
                            {11, 12, 13}};
                
/* モータの位置とピン番号
 * 右前足上からsv[0][0]~sv[0][2]
 * 左前足上からsv[1][0]~sv[1][2]
 * 右後足上からsv[2][0]~sv[2][2]
 * 左後足上からsv[3][0]~sv[3][2]
*/

void setup() {
  // ピン接続
  for(int i = 0; i < 4; i++) {
    for(int j = 0; j < 3; j++) {
      sv[i][j].attach(MOTORPIN[i][j]);
    }
  }

  // 活動内容によって選択する
  // changeBreakMode(); // 脚を折りたたむ : 収納時用
  // pkStandby(); // モータ角度の初期化 : PK競技用
  // walkStandby(); // モータ角度の初期化 : 歩行用
  
  delay(5000); // 5秒待機
  
  Serial.begin(9600); // シリアル通信の開始
}

void loop() {
  // 活動内容によってコメントを外す
  // 歩行
  // walk();
 
  /*
  // PK競技
  if(sensorLeft.sensing() < THRESHOLD) {
    defendLeft(); 
  }
  // 右前方のセンシング
  else if(sensorRight.sensing() < THRESHOLD) {
    defendRight(); 
  }
  // else の場合は静止
  */
}


// 持ち運ぶ際に足を折りたたんで収納する
void changeBreakMode() {
  const int BREAK_MOTORDEGREE[4][3] = {{90, 10, 90},
                                      {90, 170, 95}, 
                                      {90, 160, 90}, 
                                      {90, 20, 90}};
  for(int i = 0; i < 4; i++) {
    for(int j = 0; j < 3; j++) {
      sv[i][j].write(BREAK_MOTORDEGREE[i][j]);
    }
  }
  delay(10000);
}

 
