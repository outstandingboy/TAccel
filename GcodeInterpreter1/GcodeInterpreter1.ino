//串口G代码接收器
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("这是koalamodule的数控系统，请输入G代码");
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()){
    delay(5);
    static char ch;
    static char G_num,M_num;
    static unsigned int S_num,F_num;
    static float X_pos;
    static bool Gset,Mset;
    while(Serial.available()){
      ch = Serial.read();//G00 X1000 Y200; M03 S12000
      switch(ch){
        case 'G':G_num = Serial.parseInt();Gset=1;Mset=0;break;
        case 'M':M_num = Serial.parseInt();Mset=1;Gset=0;break;
        case 'S':S_num = Serial.parseInt();break;
        case 'X':X_pos = Serial.parseFloat();break;
        case 'F':F_num = Serial.parseInt();break;
        case ' ': case '\n':case '\t': case 0:break; 
        default:Serial.println("Invalid Command");break;
      }
    }//完成读取
    if(Gset){
      switch(G_num){
        case 0:Serial.print("快速运动至X=");Serial.println(X_pos);break;
        case 1:Serial.print("直线运动至X=");Serial.print(X_pos);Serial.print("进给速度为F=");Serial.println(F_num);break;
        case 28:Serial.println("回零");Gset=0;break;
        case 92:Serial.print("设定坐标原点为X=");Gset=0;Serial.println(X_pos);break;
        default:Serial.println("不支持的G代码");
      }
    }
    if(Mset){
      switch(M_num){
        case 3:Serial.print("主轴正转,转速为");Serial.println(S_num);break;
        case 30:Serial.println("主轴停止");break;
        default:Serial.println("不支持的M代码");
      }
    }


  }
}
