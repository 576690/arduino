#include <PS2X_lib.h>

#define PS2_DAT        A3
#define PS2_CMD        A2
#define PS2_ATT        A4
#define PS2_CLK        A1
#define sp    255     //定义小车速度



PS2X PS2_Control;             //定义一个PS2手柄名称
int error = 0;                //是否有错误
byte type = 0;                //定义PS2手柄工作模式
byte vibrate = 0;             //是否震动
int L1_IN1 = 2;int L1_IN2 = 4;int L1_ENA = 3;//左前轮
int R1_IN1 = 7;int R1_IN2 = 8;int R1_ENA = 5;//右前轮
int L2_IN1 = 10;int L2_IN2 = 11;int L2_ENA = 6;//左后轮
int R2_IN1 = 12;int R2_IN2 = A0;int R2_ENA = 9;//右后轮



//****初始化电机***********************************************************//


//****定义运动函数***********************************************************//
void Stop()
{                           //停止
  digitalWrite(L1_IN1,LOW);
  digitalWrite(L1_IN2,LOW);  
  digitalWrite(R1_IN1,LOW);
  digitalWrite(R1_IN2,LOW);
  digitalWrite(L2_IN1,LOW);
  digitalWrite(L2_IN2,LOW);
  digitalWrite(R2_IN1,LOW);
  digitalWrite(R2_IN2,LOW);
}

void Go_Forward(){                    //向前移动
  digitalWrite(L1_IN1,LOW);
  digitalWrite(L1_IN2,HIGH);
  analogWrite(L1_ENA,sp);
  digitalWrite(R1_IN1,HIGH);
  digitalWrite(R1_IN2,LOW);
  analogWrite(R1_ENA,sp);
  digitalWrite(L2_IN1,HIGH);
  digitalWrite(L2_IN2,LOW);
  analogWrite(L2_ENA,sp);
  digitalWrite(R2_IN1,HIGH);
  digitalWrite(R2_IN2,LOW);
  analogWrite(R2_ENA,sp);
}

void Go_Forward1(){                    //向前慢移动
  digitalWrite(L1_IN1,LOW);
  digitalWrite(L1_IN2,HIGH);
  analogWrite(L1_ENA,sp-100);
  digitalWrite(R1_IN1,HIGH);
  digitalWrite(R1_IN2,LOW);
  analogWrite(R1_ENA,sp-100);
  digitalWrite(L2_IN1,HIGH);
  digitalWrite(L2_IN2,LOW);
  analogWrite(L2_ENA,sp-100);
  digitalWrite(R2_IN1,HIGH);
  digitalWrite(R2_IN2,LOW);
  analogWrite(R2_ENA,sp-100);
}

void Go_Back() {                        //向后移动
  digitalWrite(L1_IN1,HIGH);
  digitalWrite(L1_IN2,LOW);
  analogWrite(L1_ENA,sp);
  digitalWrite(R1_IN1,LOW);
  digitalWrite(R1_IN2,HIGH);
  analogWrite(R1_ENA,sp);
  digitalWrite(L2_IN1,LOW);
  digitalWrite(L2_IN2,HIGH);
  analogWrite(L2_ENA,sp);
  digitalWrite(R2_IN1,LOW);
  digitalWrite(R2_IN2,HIGH);
  analogWrite(R2_ENA,sp);
}

void Go_Back1() {                        //向后慢移动
  digitalWrite(L1_IN1,HIGH);
  digitalWrite(L1_IN2,LOW);
  analogWrite(L1_ENA,sp-100);
  digitalWrite(R1_IN1,LOW);
  digitalWrite(R1_IN2,HIGH);
  analogWrite(R1_ENA,sp-100);
  digitalWrite(L2_IN1,LOW);
  digitalWrite(L2_IN2,HIGH);
  analogWrite(L2_ENA,sp-100);
  digitalWrite(R2_IN1,LOW);
  digitalWrite(R2_IN2,HIGH);
  analogWrite(R2_ENA,sp-100);
}

void Go_Left() {                        
////左侧移动  
//  L1_backward(150);
//  R1_forward(150);
//  L2_forward(150);
//  R2_backward(150);
  digitalWrite(L1_IN1,HIGH);
  digitalWrite(L1_IN2,LOW);
  analogWrite(L1_ENA,sp);
  digitalWrite(R2_IN1,LOW);
  digitalWrite(R2_IN2,HIGH);
  analogWrite(R2_ENA,sp);
  digitalWrite(R1_IN1,HIGH);
  digitalWrite(R1_IN2,LOW);
  analogWrite(R1_ENA,sp);
  digitalWrite(L2_IN1,HIGH);
  digitalWrite(L2_IN2,LOW);
  analogWrite(L2_ENA,sp);
}
void Go_Left1() {                        
////左侧移动  
//  L1_backward(150);
//  R1_forward(150);
//  L2_forward(150);
//  R2_backward(150);
  digitalWrite(L1_IN1,HIGH);
  digitalWrite(L1_IN2,LOW);
  analogWrite(L1_ENA,sp-100);
  digitalWrite(R2_IN1,LOW);
  digitalWrite(R2_IN2,HIGH);
  analogWrite(R2_ENA,sp-100);
  digitalWrite(R1_IN1,HIGH);
  digitalWrite(R1_IN2,LOW);
  analogWrite(R1_ENA,sp-100);
  digitalWrite(L2_IN1,HIGH);
  digitalWrite(L2_IN2,LOW);
  analogWrite(L2_ENA,sp-100);
}

void Go_Right() {                      
//右侧移动
//  L1_forward(150);
//  R1_backward(150);
//  L2_backward(150);
//  R2_forward(150);
  digitalWrite(L1_IN1,LOW);
  digitalWrite(L1_IN2,HIGH);
  analogWrite(L1_ENA,sp);
  digitalWrite(R2_IN1,HIGH);
  digitalWrite(R2_IN2,LOW);
  analogWrite(R2_ENA,sp);
  digitalWrite(R1_IN1,LOW);
  digitalWrite(R1_IN2,HIGH);
  analogWrite(R1_ENA,sp);
  digitalWrite(L2_IN1,LOW);
  digitalWrite(L2_IN2,HIGH);
  analogWrite(L2_ENA,sp);

}

void Forward_Left() {                 
//左前移动
//  R1_forward(150);
//  L2_forward(150);
  digitalWrite(R1_IN1,HIGH);
  digitalWrite(R1_IN2,LOW);
  analogWrite(R1_ENA,sp);
  digitalWrite(L2_IN1,HIGH);
  digitalWrite(L2_IN2,LOW);
  analogWrite(L2_ENA,sp);
}

void Forward_Right() {                
//右前移动
//  L1_forward(150);
//  R2_forward(150);
  digitalWrite(L1_IN1,LOW);
  digitalWrite(L1_IN2,HIGH);
  analogWrite(L1_ENA,sp);
  digitalWrite(R2_IN1,HIGH);
  digitalWrite(R2_IN2,LOW);
  analogWrite(R2_ENA,sp);
}

void Back_Left() {                     
//左后移动
//  L1_backward(150);
//  R2_backward(150);
  digitalWrite(L1_IN1,HIGH);
  digitalWrite(L1_IN2,LOW);
  analogWrite(L1_ENA,sp);
  digitalWrite(R2_IN1,LOW);
  digitalWrite(R2_IN2,HIGH);
  analogWrite(R2_ENA,sp);
}

void Back_Right() {                    
//右后移动
//  R1_backward(150);
//  L2_backward(150);
  digitalWrite(R1_IN1,LOW);
  digitalWrite(R1_IN2,HIGH);
  analogWrite(R1_ENA,sp);
  digitalWrite(L2_IN1,LOW);
  digitalWrite(L2_IN2,HIGH);
  analogWrite(L2_ENA,sp);
}

void Go_Right1() {                      
//右侧移动
//  L1_forward(150);
//  R1_backward(150);
//  L2_backward(150);
//  R2_forward(150);
  digitalWrite(L1_IN1,LOW);
  digitalWrite(L1_IN2,HIGH);
  analogWrite(L1_ENA,sp-100-100);
  digitalWrite(R2_IN1,HIGH);
  digitalWrite(R2_IN2,LOW);
  analogWrite(R2_ENA,sp-100);
  digitalWrite(R1_IN1,LOW);
  digitalWrite(R1_IN2,HIGH);
  analogWrite(R1_ENA,sp-100);
  digitalWrite(L2_IN1,LOW);
  digitalWrite(L2_IN2,HIGH);
  analogWrite(L2_ENA,sp-100);

}

void Forward_Left1() {                 
//左前移动
//  R1_forward(150);
//  L2_forward(150);
  digitalWrite(R1_IN1,HIGH);
  digitalWrite(R1_IN2,LOW);
  analogWrite(R1_ENA,sp-100);
  digitalWrite(L2_IN1,HIGH);
  digitalWrite(L2_IN2,LOW);
  analogWrite(L2_ENA,sp-100);
}

void Forward_Right1() {                
//右前移动
//  L1_forward(150);
//  R2_forward(150);
  digitalWrite(L1_IN1,LOW);
  digitalWrite(L1_IN2,HIGH);
  analogWrite(L1_ENA,sp-100);
  digitalWrite(R2_IN1,HIGH);
  digitalWrite(R2_IN2,LOW);
  analogWrite(R2_ENA,sp-100);
}

void Back_Left1() {                     
//左后移动
//  L1_backward(150);
//  R2_backward(150);
  digitalWrite(L1_IN1,HIGH);
  digitalWrite(L1_IN2,LOW);
  analogWrite(L1_ENA,sp-100);
  digitalWrite(R2_IN1,LOW);
  digitalWrite(R2_IN2,HIGH);
  analogWrite(R2_ENA,sp-100);
}

void Back_Right1() {                    
//右后移动
//  R1_backward(150);
//  L2_backward(150);
  digitalWrite(R1_IN1,LOW);
  digitalWrite(R1_IN2,HIGH);
  analogWrite(R1_ENA,sp-100);
  digitalWrite(L2_IN1,LOW);
  digitalWrite(L2_IN2,HIGH);
  analogWrite(L2_ENA,sp-100);
}

void FClock() {                       
 //顺时针旋转
//  L1_forward(200);
//  R1_backward(200);
//  L2_forward(200);
//  R2_backward(200);
  digitalWrite(L1_IN1,LOW);
  digitalWrite(L1_IN2,HIGH);
  analogWrite(L1_ENA,88);
  digitalWrite(L2_IN1,HIGH);
  digitalWrite(L2_IN2,LOW);
  analogWrite(L2_ENA,88);
  digitalWrite(R1_IN1,LOW);
  digitalWrite(R1_IN2,HIGH);
  analogWrite(R1_ENA,88);
  digitalWrite(R2_IN1,LOW);
  digitalWrite(R2_IN2,HIGH);
  analogWrite(R2_ENA,88);
}

void FClock1() {                       
 //顺时针旋转
//  L1_forward(200);
//  R1_backward(200);
//  L2_forward(200);
//  R2_backward(200);
  digitalWrite(L1_IN1,LOW);
  digitalWrite(L1_IN2,HIGH);
  analogWrite(L1_ENA,sp);
  digitalWrite(L2_IN1,HIGH);
  digitalWrite(L2_IN2,LOW);
  analogWrite(L2_ENA,sp);
  digitalWrite(R1_IN1,LOW);
  digitalWrite(R1_IN2,HIGH);
  analogWrite(R1_ENA,sp);
  digitalWrite(R2_IN1,LOW);
  digitalWrite(R2_IN2,HIGH);
  analogWrite(R2_ENA,sp);
}

void BClock() {                        
//逆时针旋转
//  L1_backward(200);
//  R1_forward(200);
//  L2_backward(200);
//  R2_forward(200);
  digitalWrite(L1_IN1,HIGH);
  digitalWrite(L1_IN2,LOW);
  analogWrite(L1_ENA,88);
  digitalWrite(L2_IN1,LOW);
  digitalWrite(L2_IN2,HIGH);
  analogWrite(L2_ENA,88);
  digitalWrite(R1_IN1,HIGH);
  digitalWrite(R1_IN2,LOW);
  analogWrite(R1_ENA,88);
  digitalWrite(R2_IN1,HIGH);
  digitalWrite(R2_IN2,LOW);
  analogWrite(R2_ENA,88);
}

void BClock1() {                        
//逆时针旋转
//  L1_backward(200);
//  R1_forward(200);
//  L2_backward(200);
//  R2_forward(200);
  digitalWrite(L1_IN1,HIGH);
  digitalWrite(L1_IN2,LOW);
  analogWrite(L1_ENA,sp);
  digitalWrite(L2_IN1,LOW);
  digitalWrite(L2_IN2,HIGH);
  analogWrite(L2_ENA,sp);
  digitalWrite(R1_IN1,HIGH);
  digitalWrite(R1_IN2,LOW);
  analogWrite(R1_ENA,sp);
  digitalWrite(R2_IN1,HIGH);
  digitalWrite(R2_IN2,LOW);
  analogWrite(R2_ENA,sp);
}

void setup() 
{
  pinMode(L1_IN1, OUTPUT);pinMode(L1_IN2, OUTPUT);pinMode(L1_ENA, OUTPUT);
  pinMode(R1_IN1, OUTPUT);pinMode(R1_IN2, OUTPUT);pinMode(R1_ENA, OUTPUT);
  pinMode(L2_IN1, OUTPUT);pinMode(L2_IN2, OUTPUT);pinMode(L2_ENA, OUTPUT);
  pinMode(R2_IN1, OUTPUT);pinMode(R2_IN2, OUTPUT);pinMode(R2_ENA, OUTPUT);
  Serial.begin(57600);
  error = PS2_Control.config_gamepad(PS2_CLK, PS2_CMD, PS2_ATT, PS2_DAT, true, true);       
  //PS2手柄接线方式 GamePad(clock, command, attention, data, Pressures?, Rumble?)
  type = PS2_Control.readType();                                        
  //获取PS2手柄工作模式
  Stop();                                                               
  //设置小车为停止

  if (error == 0) {                                                      //PS2连接正确
    Serial.println("Found Controller, configured successful");
  }
  else if (error == 1)
    Serial.println("No controller found, check wiring, see readme.txt to enable debug. visit www.billporter.info for troubleshooting tips");
  else if (error == 2)
    Serial.println("Controller found but not accepting commands. see readme.txt to enable debug. Visit www.billporter.info for troubleshooting tips");
  else if (error == 3)
    Serial.println("Controller refusing to enter Pressures mode, may not support it. ");

  switch (type) {
    case 0:
      Serial.println("Unknown Controller type");
      break;
    case 1:
      Serial.println("DualShock Controller Found");
      break;
    case 2:
      Serial.println("GuitarHero Controller Found");
      break;
  }



}

void loop() {
  /* You must Read Gamepad to get new values
    Read GamePad and set vibration values
    PS2_Control.read_gamepad(small motor on/off, larger motor strenght from 0-255)
    if you don't enable the rumble, use PS2_Control.read_gamepad(); with no values
    you should call this at least once a second
  */

  if (error == 1)
    return;

  if (type == 2) {
    PS2_Control.read_gamepad();          //read controller
  }
  else
  {
    PS2_Control.read_gamepad(false, vibrate);                                  //读取PS2手柄按钮操作  read controller and set large motor to spin at 'vibrate' speed

    //****设置运动按钮***********************************************************//

    if (PS2_Control.Button(PSB_PAD_UP)) {                                   //长按向上
      Go_Forward();
      Serial.println("Up held this hard: ");
      //Serial.println(PS2_Control.Analog(PSAB_PAD_UP), DEC);
    }
    else Stop();

    if (PS2_Control.Button(PSB_PAD_DOWN)) {                                 //长按向下
      Go_Back();
    }


    if (PS2_Control.Button(PSB_PAD_LEFT)) {                                 //长按向左
      Go_Left();
    }

    if (PS2_Control.Button(PSB_PAD_RIGHT)) {                                //长按向右
      Go_Right();
    }

    if (PS2_Control.Button(PSB_L1))                                         //长按左前
    {
      Forward_Left();
      //Serial.println("L1 pressed");
    }


    if (PS2_Control.Button(PSB_R1))                                      //长按右前
    {
      Forward_Right();
      //Serial.println("R1 pressed");
    }

    if (PS2_Control.Button(PSB_L2))                                      //长按左后
    {
      Back_Left();
      //Serial.println("L3 pressed");
    }

    if (PS2_Control.Button(PSB_R2))                                      //长按右后
    {
      Back_Right();
      //Serial.println("R3 pressed");
    }

    if (PS2_Control.Button(PSB_L3)) {                                    //长按逆时针
      BClock();
    }

    if (PS2_Control.Button(PSB_R3)) {                                    //长按顺时针
      FClock();
    }
    if (PS2_Control.Button(PSB_GREEN)) {                                    //慢前
      Go_Forward1();
    }
    if (PS2_Control.Button(PSB_BLUE)) {                                    //慢前
      Go_Back1();
    }
    if (PS2_Control.NewButtonState(PSB_PINK)) {                                    //长按慢逆时针
      BClock1();
    }
    if (PS2_Control.NewButtonState(PSB_RED)) {                                    //长按顺时针
      FClock1();
    }
        /*左摇杆控制小车运动状态程序*/
    if (PS2_Control.Analog(PSS_LY) < 5 && PS2_Control.Analog(PSS_LX) > 80 && PS2_Control.Analog(PSS_LX) < 180)         //上
    {
      Go_Forward();
    }
    if (PS2_Control.Analog(PSS_LY) > 230 && PS2_Control.Analog(PSS_LX) > 80 && PS2_Control.Analog(PSS_LX) < 180) //下
    {
      Go_Back();
    }
    if (PS2_Control.Analog(PSS_LX) < 5 && PS2_Control.Analog(PSS_LY) > 80 && PS2_Control.Analog(PSS_LY) < 180)   //左
    {
      Go_Left();
    }
    if (PS2_Control.Analog(PSS_LY) > 80 && PS2_Control.Analog(PSS_LY) < 180 && PS2_Control.Analog(PSS_LX) > 230) //右
    {
      Go_Right();
    }


    /*右摇杆控制小车运动状态程序*/
    if (PS2_Control.Analog(PSS_RY) < 5 && PS2_Control.Analog(PSS_RX) > 80 && PS2_Control.Analog(PSS_RX) < 180)         //上
    {
      Go_Forward1();
    }
    if (PS2_Control.Analog(PSS_RY) > 230 && PS2_Control.Analog(PSS_RX) > 80 && PS2_Control.Analog(PSS_RX) < 180) //下
    {
      Go_Back1();
    }
    if (PS2_Control.Analog(PSS_RX) < 5 && PS2_Control.Analog(PSS_RY) > 80 && PS2_Control.Analog(PSS_RY) < 180)   //左
    {
      Go_Left1();
    }
    if (PS2_Control.Analog(PSS_RY) > 80 && PS2_Control.Analog(PSS_RY) < 180 && PS2_Control.Analog(PSS_RX) > 230) //右
    {
      Go_Right1();
    }


    //****PS2手柄空余的按钮***********************************************************//
    /*
      if (PS2_Control.Button(PSB_START))                                  //will be TRUE as long as button is pressed
       Serial.println("Start is being held");
      if (PS2_Control.Button(PSB_SELECT))
       Serial.println("Select is being held");


      if (PS2_Control.NewButtonState(PSB_GREEN))                         //三角按钮按下
      { vibrate = PS2_Control.Analog(PSAB_GREEN);

      }

      if (PS2_Control.NewButtonState(PSB_RED))                           //圆圈按钮按下
      { Serial.println("Circle just pressed");
       vibrate = PS2_Control.Analog(PSAB_RED);

      }


      if (PS2_Control.NewButtonState(PSB_PINK))                           //方块按钮按下
      { Serial.println("Square just released");

       vibrate = PS2_Control.Analog(PSAB_PINK);

      }

      if (PS2_Control.NewButtonState(PSB_BLUE))                           //X按钮按下,当按钮改变状态，相当于响应2次
      { Serial.println("X just changed");
       vibrate = PS2_Control.Analog(PSAB_BLUE);                          //当X按钮按下，手柄震动一次
      }



         if (PS2_Control.Button(PSB_L1) || PS2_Control.Button(PSB_R1))      // 当按下L1、R1键时读取摇杆的度数
         {
           Serial.print("Stick Values:");
           Serial.print(PS2_Control.Analog(PSS_LY), DEC);                   //Left stick, Y axis. Other options: LX, RY, RX
           Serial.print(",");
           Serial.print(PS2_Control.Analog(PSS_LX), DEC);
           Serial.print(",");
           Serial.print(PS2_Control.Analog(PSS_RY), DEC);
           Serial.print(",");
           Serial.println(PS2_Control.Analog(PSS_RX), DEC);
         }
    */
  }

  delay(20);
}
