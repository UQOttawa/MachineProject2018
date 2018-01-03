/*
 * 
 * This class will move the movement motors by treating them as a servo
 * The motors work independently from each other
 * 100 = stopped motor
 * 150 = full speed backward
 * 50 = full speed forward
 * 
 */

#include <Servo.h>
#include <Stepper.h>

String readString;

Servo rightSide;
Servo leftSide;
int nRightSideSpeed = 90;
int nLeftSideSpeed = 90;

Servo servoBridge;

#define CLOSEGRIP 151
#define OPENGRIP 60
  
  const int  INIT2=90;
  const int  MAX2=140;
  const int  MIN2=10;
  
  const int  INIT3=85;
  const int  MAX3=175;
  const int  MIN3=10;
  
  //wrist
  const int  INIT4=0 ; //flat
  const int  MAX4=180;
  const int  MIN4=0;

  //claw
  const int  INIT5= OPENGRIP ; //flat
  const int  MAX5= CLOSEGRIP;
  const int  MIN5= OPENGRIP;

  const int  MOON2 = 27;
  const int  MOON3 = 115;
  const int  MOON4 = 0;

  
  const int  STORE2 = 102;
  const int  STORE3 = 73;
  
  const int  PICK2 = 126;
  const int  PICK3 = 73;

  const int  PICK2_init = 132;
  const int  PICK3_init = 43;

  const int  BOX2 = 90 ;
  const int  BOX3 = 5;

  const int  MAXZ = 300;
  
  const int INIT_DRUM = 15;
  
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;
//Servo position in degrees
int unit2, unit3, unit4, unit5;
int stepP = 3, step2 = 3, step3 = 3, step4 = 3, step5 = 3;

const int stepsPerRevolution = 200;

Stepper stepper (stepsPerRevolution, 8, 9, 10, 11);
int stepCount = 0;

void setup()
{
  Serial.begin(9600);
  
  rightSide.attach(15);
  leftSide.attach(14);
  servo2.attach(16);
  servo3.attach(17);
  servo4.attach(18);
  servo5.attach(19);
  servoBridge.attach(6);
  
  servo2.write(INIT2);
  servo3.write(INIT3);
  servo4.write(INIT4);
  servo5.write(INIT5);
  
  servoBridge.write(180);
  
  unit2 = INIT2;
  unit3 = INIT3;
  unit4 = INIT4;
  unit5 = INIT5;

  stepper.setSpeed(50);
}

void loop()
{
  while(Serial.available())
  {
    readString = Serial.read();
    delay(1);
  }

  if(readString.length() > 0)
  {
    
    if(readString == "119")
    {
//      Serial.println("going forward");
      rightSide.write(120);
      leftSide.write(120);
      delay(100);
  
      nRightSideSpeed = 90;
      nLeftSideSpeed = 90;
    }
    else if(readString == "120")
    {
//    Serial.println("stopping");
      nRightSideSpeed = 90;
      nLeftSideSpeed = 90;
    }
    else if(readString == "115")
    {
//      Serial.println("going backward");

      rightSide.write(80);
      leftSide.write(80);
      delay(100);
  
      nRightSideSpeed = 90;
      nLeftSideSpeed = 90;
    }
    else if(readString == "100")
    {
//      Serial.println("going right");
      
      rightSide.write(120);
      leftSide.write(75);
      delay(100);
  
      nRightSideSpeed = 90;
      nLeftSideSpeed = 90;
    }
    else if(readString == "97")
    {
//      Serial.println("going left");
      
      rightSide.write(75);
      leftSide.write(120);
      delay(100);
  
      nRightSideSpeed = 90;
      nLeftSideSpeed = 90;
    }
    else if (readString == "105")
    {
      //Serial.println("arm up");
      if(unit2-stepP>MIN2 && unit3+stepP<MAX3)
      {
        unit2 -= stepP;
        unit3 += stepP;
        moveTo(servo2,unit2, unit2+stepP);
        moveTo(servo3,unit3, unit3-stepP);
      }
    }
    else if(readString == "107")
    {
      //Serial.println("arm down");

      if(unit2 + stepP <MAX2 && unit3-stepP>MIN3)
      {
        unit2 += stepP;
        unit3 -= stepP;
        moveTo(servo2,unit2, unit2-stepP);
        moveTo(servo3,unit3, unit3+stepP);
      }
    }
    
    else if(readString == "112")
    {
      //Serial.println("close gripper");
      unit5 = CLOSEGRIP;
      servo5.write(unit5);
    }
  
    else if(readString == "111")
    {
      //Serial.println("open gripper");
      unit5 = OPENGRIP;
      servo5.write(unit5);
    }
    else if(readString == "121")
    {
      //Serial.println("wrist horaire");
      if(unit4-step4>MIN4)
      {
        unit4 -= step4;
        servo4.write(unit4);
        moveTo(servo4,unit4,unit4+step4);
      }
    }
    else if(readString == "117")
    {
      //Serial.println("wrist anti");
      if(unit4+step4<MAX4)
      {
        unit4 += step4;
        moveTo(servo4,unit4,unit4-step4);
      }
    }
    else if(readString == "103")
    {
      //Serial.println("3 up");
      if(unit3- step3>MIN3)
      {
        unit3 -= step3;
        moveTo(servo3,unit3,unit3+step3);
      }

    }
    else if(readString == "104")
    {
      //Serial.println("3 down");
      if(unit3+step3<MAX3 && unit3+step3+unit2 < MAXZ)
      {
        unit3 += step3;
        moveTo(servo3,unit3,unit3-step3);
      }

    }
    else if(readString == "110")
    {
     // Serial.println("2 up");
      if(unit2-step2>MIN2)
      {
        unit2 -= step2;
        moveTo(servo2,unit2,unit2+step2);
      }
    }
    else if(readString == "109")
    {
      //Serial.println("2 down");
      if(unit2+step2<MAX2 && unit3+step2+unit2 < MAXZ)
      {
        unit2 += step2;
        moveTo(servo2,unit2,unit2-step2);
      }
    }
    else if(readString == "49")
    {
      //Serial.println("moon");
      unit4=INIT4;
      bigMoveTo(servo2,MOON2,unit2);
      bigMoveTo(servo3,MOON3,unit3);
      servo4.write(unit4);
      unit3 = MOON3;
      unit2 = MOON2;
    }
     else if(readString == "52")
    {
      //Serial.println("store");
      unit4=INIT4;
      bigMoveTo(servo2,MOON2,unit2);
      unit2 = MOON2;
      bigMoveTo(servo3,STORE3,unit3);
      bigMoveTo(servo2,STORE2,unit2);
      servo4.write(unit4);
      unit3 = STORE3;
      unit2 = STORE2;
    }
    else if(readString == "114")
    {
      //Serial.println("reset");
      servoBridge.write(180);
      reset();
    }
    else if(readString == "32")
    {
      //Serial.println("pickup Stick forest");
      unit4=INIT4;
      bigMoveTo(servo3,PICK3,unit3);
      bigMoveTo(servo2,PICK2,unit2);
      servo4.write(unit4);
      unit3 = PICK3;
      unit2 = PICK2;
    }   
    else if(readString == "51")
    {
      //Serial.println("pickup Stick firdt 4");
      unit4=INIT4;
      bigMoveTo(servo3,PICK3_init,unit3);
      bigMoveTo(servo2,PICK2_init,unit2);
      servo4.write(unit4);
      unit3 = PICK3_init;
      unit2 = PICK2_init;
    }   
    else if(readString == "48")
    {
      //Serial.println("box");
      unit4=INIT4;
      bigMoveTo(servo3,BOX3,unit3);
      bigMoveTo(servo2,BOX2,unit2);
      servo4.write(unit4);
      unit3 = BOX3;
      unit2 = BOX2;
    }   
    else if(readString == "118")
    {
      //Serial.println("5 open");
      if(unit5-step5>MIN5 )
      {
        unit5 -= step5;
        moveTo(servo5,unit5,unit5+step5);
      }
    }
  else if(readString == "98")
    {
      //Serial.println("5 close");
      if(unit5+step5<MAX5)
      {
        unit5 += step5;
        moveTo(servo5,unit5,unit5-step5);
      }
    }
    else if(readString == "50")
    {
     // Serial.println("reverse wrist");
      if(unit4 < (MAX4+MIN4)/2 )
      {
        moveTo(servo4,INIT4+180,unit4);
        unit4 = INIT4+180;
      }
      else
      {
        moveTo(servo4,INIT4,unit4);
        unit4 = INIT4 ;
      }
    }
//    else if(readString == "99")
//    {
//////      Serial.print("1 : ");
//////      Serial.println(unit1);
//      delay(15);
//      Serial.print("2 : ");
//      Serial.println(unit2);
//      Serial.print("3 : ");
//      Serial.println(unit3);
//      Serial.print("4 : ");
//      Serial.println(unit4);
//      Serial.print("5 : ");
//      Serial.println(unit5);
//    }
    else if(readString == "47") {
       // Drop the bridge
       servoBridge.write(0);
    }
    else if(readString == "91") {
       stepper.step(-1);
       stepCount --;
       Serial.print(stepCount);
    }
    else if(readString == "93") {
       stepper.step(1);
       stepCount ++;
       Serial.print(stepCount);
    }
  }

  rightSide.write(nRightSideSpeed);
  leftSide.write(nLeftSideSpeed);
  //Serial.println(readString);

  readString="";
}


void moveTo(Servo servo, int angle, int unit){
  if (unit>angle){
    for(int i = unit; i >= angle ; i--){
      servo.write(i);
      delay(2);
      }
  }
  else if (unit < angle){
    for(int i = unit; i <= angle ; i++){
      servo.write(i);
      delay(2);
    }
  }
  
}

void bigMoveTo(Servo servo, int angle, int unit){
  if (unit>angle){
    for(int i = unit; i >= angle ; i--){
      servo.write(i);
      delay(12);
      }
  }
  else if (unit < angle){
    for(int i = unit; i <= angle ; i++){
      servo.write(i);
      delay(12);
    }
  }
  
}

void reset(){
      bigMoveTo(servo2,INIT2,unit2);
      bigMoveTo(servo3,INIT3,unit3);
      servo4.write(INIT4);
     // servo5.write(INIT5);
      unit2 = INIT2;
      unit3 = INIT3;
      unit4 = INIT4;
}

