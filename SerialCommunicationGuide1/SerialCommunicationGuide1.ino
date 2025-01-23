void setup() {
  // put your setup code here, to run once:
  //打开串口
  Serial.begin(115200);
  //打印欢迎词
  Serial.println("这是koalamodule的教学课程-串口通信");
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()){
    delay(5);
    while(Serial.available()){
      char ch = Serial.read();
      if(ch>='a'&&ch<='z')ch = ch - 'a'+'A';
      Serial.print(ch);
    }    
  }
}
