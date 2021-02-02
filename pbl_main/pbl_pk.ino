/* PK競技用関数
 *  
 *  pkStandby()
 *  defendLeft()
 *  defendRight()
 */

// pk競技用のセットアップ
void pkStandby() {
  
  const int PK_READY_MOTORDEGREE[4][3] = {{90, 10, 90}, 
                                         {90, 170, 95}, 
                                         {90, 160, 5}, 
                                         {90, 20, 175}};
                                       
  for(int i = 0; i < 4; i++) {
    for(int j = 0; j < 3; j++) {
      sv[i][j].write(PK_READY_MOTORDEGREE[i][j]);
      delay(100);
    }
  }                                  
}

// 左側の防御プログラム
void defendLeft() {
  // 左後ろ脚を下におろす
  sv[3][1].write(90);
  // 10秒待機する
  delay(10000);
  // 脚をもとの位置に戻す
  sv[3][1].write(20);
}

// 右側の防御プログラム
void defendRight() {
  // 右後ろ脚を下におろす
  sv[2][1].write(90);
  // 10秒待機する
  delay(10000); 
  // 脚をもとの位置に戻す 
  sv[2][1].write(160);
}
