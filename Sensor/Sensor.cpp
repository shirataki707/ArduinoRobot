/* Sensor.cpp
 * 
 * created : 2020/12/17
 * 
 * white : analogPin A0~A5
 * orange : GND
 * black : 5V
 * 
*/ 

#include "Arduino.h"
#include "Sensor.h"

// コンストラクタでピン番号を格納する
Sensor::Sensor(int pin) {
  _pin = pin;
}

float Sensor::sensing() {
  delay(100);
  // 距離の測定
  dist = ADtoDistance(readSensor());
  // データの表示
  printData();

  return dist;
}

// 赤外線距離測定モジュールから100回分のアナログ値を読み取り平均を返す
float Sensor::readSensor() {
  int value = 0;
  float res = 0;
  for (int i = 0; i < 100; i++) {
    value = analogRead(_pin); // アナログ値を取得
    res += value;
  }
  return res / 100;
}

// 引数のアナログ値をAD変換したあと距離に変換する
float Sensor::ADtoDistance(float analogValue) {
  float res = 0;
  // AD変換
  res = Vcc * analogValue / 1023;
  // 距離変換
  res = 26.549 * pow(res, -1.2091); 

  return res;
}

// シリアルモニタに表示する
void Sensor::printData() {
  if(_pin == A0) Serial.print("Right");
  else Serial.print("Left");
  Serial.print("Dist = ");
  Serial.print(dist);
  Serial.println(" cm");
}
