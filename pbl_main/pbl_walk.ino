/* 歩行用関数
 *  
 *  
 *  左______前_______右
 *  　| C         B|
 *  　|            |
 *  　|            |
 *  　|            |
 * 　_|_D_________A|_
 *  
 *  プログラムは前半部と後半部に分かれる
 *  前半部と後半部は左右対称な動作を行う
 *  それぞれのパートではstep1~step3に分かれる
 *  step1 : 片方の前足の処理
 *  step2 : 4本全ての足の同時処理
 *  step3 : 片方の後ろ足の処理
 *  
 */

void stairsStandby() {
  // MOTORDEGREE モータの初期角度
  const int MOTORDEGREE[4][3] = {{70, 90, 110}, 
                                 {110, 90, 70},
                                 {110, 90, 70},
                                 {70, 90, 110}};
  for(int i = 0; i < 4; i++) {
    for(int j = 0; j < 3; j++) {
      sv[i][j].write(MOTORDEGREE[i][j]);
      delay(100);
    }
  }
}

void walk() {
  // first half
  // step1
  // B
  sv[0][1].write(MOTORDEGREE[0][1]-30); // z軸方向に上げる 
  delay(100); 
  sv[0][0].write(MOTORDEGREE[0][0]-55); // 前方に回転 
  delay(100);
  sv[0][2].write(MOTORDEGREE[0][2]+30); // 爪を前に出す 
  delay(100);
  sv[0][1].write(MOTORDEGREE[0][1]); // z軸を元に戻す 
  delay(100);

  // step2
  sv[1][1].write(MOTORDEGREE[1][1]+30); // C : z軸方向に上げる
  sv[0][1].write(MOTORDEGREE[0][1]-30); // B : z軸方向に上げる
  sv[2][1].write(MOTORDEGREE[2][1]+30); // A : z軸方向に上げる
  sv[3][2].write(MOTORDEGREE[3][2]+60); // D : 爪を後方に出す
  delay(50);
  sv[1][0].write(MOTORDEGREE[1][0]-50); // C : 後方に回転
  sv[0][2].write(MOTORDEGREE[0][2]); // B : 爪を前に出す
  sv[2][0].write(MOTORDEGREE[2][0]+55); // A : 後方に回転
  sv[3][1].write(MOTORDEGREE[3][1] + 30); // D : z軸方向に下げる
  delay(100);
  sv[1][1].write(MOTORDEGREE[1][1]); // C : z軸を元に戻す
  sv[0][1].write(MOTORDEGREE[0][1]); // B : z軸を元に戻す
  sv[2][1].write(MOTORDEGREE[2][1]); // A : z軸を元に戻す
  delay(100);

  // step3
  // D
  sv[3][2].write(MOTORDEGREE[3][2]); // 爪を元に出す
  delay(100);
  sv[3][1].write(MOTORDEGREE[3][1]-50); // z軸方向に上げる
  delay(100);
  sv[3][0].write(MOTORDEGREE[3][0]+45); // 内側に回転する
  delay(100);
  sv[3][1].write(MOTORDEGREE[3][1]); // D : z軸を元に戻す
  delay(100);
  
  // second half
  // 前半部の動作終了時のモータ角度
  const int MOTORDEGREE2[4][3] = {{55, 50, 70}, {60, 120, 110}, {125, 130, 110}, {115, 60, 70}};
  
  // step1
  // C
  sv[1][1].write(MOTORDEGREE2[1][1]+30); // z軸方向に上げる 
  delay(100);
  sv[1][0].write(MOTORDEGREE2[1][0]+50); // 前方に回転 
  delay(100);
  sv[1][2].write(MOTORDEGREE2[1][2]-30); // 爪を前に出す
  delay(100);
  sv[1][1].write(MOTORDEGREE2[1][1]); // z軸を元に戻す
  delay(100);

  // step2
  sv[0][1].write(MOTORDEGREE2[0][1]-30); // B : z軸方向に上げる
  sv[1][1].write(MOTORDEGREE2[1][1]+30); // C : z軸方向に上げる
  sv[3][1].write(MOTORDEGREE2[3][1]-30); // D : z軸方向に上げる
  sv[2][2].write(MOTORDEGREE2[2][2]-60); // A : 爪を後方に出す
  delay(50);
  sv[0][0].write(MOTORDEGREE2[0][0]+55); // B : 後方に回転
  sv[1][2].write(MOTORDEGREE2[1][2]); // C : 爪を前に出す
  sv[3][0].write(MOTORDEGREE2[3][0]-45); // D : 後方に回転
  sv[2][1].write(MOTORDEGREE2[2][1]-30); // A : z軸方向に下げる
  delay(100);
  sv[0][1].write(MOTORDEGREE2[0][1]); // B : z軸を元に戻す
  sv[1][1].write(MOTORDEGREE2[1][1]); // C : z軸を元に戻す
  sv[3][1].write(MOTORDEGREE2[3][1]); // D : z軸を元に戻す
  delay(100);

  // step3
  // A
  sv[2][2].write(MOTORDEGREE2[2][2]); // 爪を元に出す
  delay(100);
  sv[2][1].write(MOTORDEGREE2[2][1]+50); // z軸方向に上げる
  delay(100);
  sv[2][0].write(MOTORDEGREE2[2][0]-55); // 内側に回転する
  delay(100);
  sv[2][1].write(MOTORDEGREE2[2][1]); // D : z軸を元に戻す
  delay(100);
}
