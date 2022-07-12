#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
Adafruit_PWMServoDriver pwm= Adafruit_PWMServoDriver(0x40);

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  pwm.begin();
  
  pwm.setOscillatorFrequency(27000000);
  pwm.setPWMFreq(50);

  for (int n=0; n<12; n++)
  {
    pwm.setPWM(n,0,250);
  }


////-----testing------------
//for(int i=250;i<=350;i++){
//    pwm.setPWM(0,0,i);
//delay(5);
//}
//
//for(int i=250;i<=350;i++){
//    pwm.setPWM(3,0,i);
//delay(5);
//}
//  for(int i=250;i>=150;i--){
//    pwm.setPWM(5,0,i);
//delay(5);
}

void mov(int motor, int initial, int final)
{
  if (initial < final)
  {
    for(int i = initial; i <=final; i+=2)
    {
      pwm.setPWM(motor, 0, i);
      delay(1);
    }
  }
  else
  {
    for(int i = initial; i >=final; i-=2)
    {
      pwm.setPWM(motor, 0, i);
      delay(1);
    }
  }

  delay(100);
}
void loop() {
  // put your main code here, to run repeatedly:

  mov(5, 250, 200);
  mov(1, 250, 300);
  mov(5, 200, 250);

  mov(6, 250, 300);
  mov(2, 250, 200);
  mov(6, 300, 250);

// -----------BODY MOVEMENT-------------
  for (int n = 250; n <=300; n+=2)
  {
    for(int i=0; i<=3; i++)
    {
      if (i==1)
      {
        pwm.setPWM(i, 0, 550-n);
      }

      if (i==3)
      {
        pwm.setPWM(i, 0, n);
      }

      if (i==2)
      {
        pwm.setPWM(i, 0, n-50);
      }

      if (i==0)
      {
        pwm.setPWM(i, 0, 500-n);
      }
    }
    delay(1);
  }

  mov(4, 250, 300);
  mov(0, 200, 250);
  mov(4, 300, 250);

  mov(7, 250, 200);
  mov(3, 300, 250);
  mov(7, 200, 250);

  delay(500);
}
