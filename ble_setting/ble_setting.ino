#include <SoftwareSerial.h>
 
SoftwareSerial btSerial(7, 8);
 
char data_bt = 0; //블루투스 데이터변수
char data_s = 0; //시리얼 데이터 변수
boolean check_bt = false;
 
void setup() {
  Serial.begin(9600);
  btSerial.begin(9600);
  btSerial.println("Hello, world?");
}
 
void loop() {
  btSerial.listen();
  if (btSerial.isListening()) {
    if (Serial.available()) { //아두이노에서 읽어오기
      data_s = Serial.read();
      btSerial.write(data_s); //블루투스 어플로 전송
    }
    if (btSerial.available()) {
      data_bt = btSerial.read();
      Serial.write(data_bt); //아두이노로 전송
      Serial.println();
    }
  }
}
