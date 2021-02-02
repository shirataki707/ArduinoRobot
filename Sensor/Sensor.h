/* Sensor.h : 
 *
 * created : 2020/12/17
 * 
*/

#ifndef Sensor_h
#define Sensor_h
#include "Arduino.h"

class Sensor {
  public:
    // インスタンス生成時にアナログピン番号を渡す
    Sensor(int analogPin); 
    // 対象までの距離を返す
    float sensing();
    
  private:
    int _pin; // ピン番号
    const float Vcc = 5.0; // 電圧
    float dist; // 距離

    // 赤外線センサの電圧を読み取る
    float readSensor(); 
    // 引数のアナログ値をAD変換し、距離に変換する
    float ADtoDistance(float analogValue);  
    // 取得データをシリアルモニタに出力する
    void printData();
};
#endif
